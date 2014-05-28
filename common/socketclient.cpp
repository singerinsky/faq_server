/*
 * socketclient.cpp
 *
 *  Created on: 2014年1月24日
 *      Author: guanlei
 */

#include "socketclient.h"
#include "msg.h"
#include "epoll_handler.h"
#include "net_util.h"

namespace omg {

//#define _MSG_BASE_
#define _MSG_PACKET_

socket_client::socket_client(int fd, sockaddr_in& addr, epoll_handler* handler) {
	// TODO Auto-generated constructor stub
	_socket_fd = fd;
	_conn_state = CONN_UNCONNECT;
    _connected = false;
	_lock.init();
	_epoll_handler = handler;
    _sin = addr;
    reset_id();
    init_epoll();
}

socket_client::socket_client(std::string ip,int port,epoll_handler* handler)
{
    _ip_str = ip;
    _port = port;
    _conn_state = CONN_UNCONNECT;
    _connected = false;
    _lock.init();
    _epoll_handler = handler;
	int fd = socket(AF_INET,SOCK_STREAM,0);
    _socket_fd = fd;
    reset_id();
}

socket_client::~socket_client() {
	// TODO Auto-generated destructor stub
    VLOG(2)<<"delete socket client";
}

void socket_client::reset_id()
{
    _conn_id._fd = _socket_fd;
    _conn_id._timestamp = time(NULL);
}

int socket_client::re_connect()
{
	int fd = socket(AF_INET,SOCK_STREAM,0);
    _socket_fd = fd;
    reset_id();
    return connect();
}

int socket_client::connect()
{
    struct sockaddr_in addr;
    init_sa_in(&addr, _ip_str.c_str(), _port) ;
    int conn_rst = ::connect(_socket_fd,(struct sockaddr*)&addr,sizeof(addr));
    if(conn_rst != 0)
    {
        LOG(ERROR)<<"connect to server"<<_ip_str.c_str()<<" :"<<_port<<" failed";
        return -1;
    }
    LOG(INFO)<<"connect to server"<<_ip_str.c_str()<<" :"<<_port<<" success!";
    _conn_state = CONN_CONNECTED;
    if(init_epoll() < 0)return -1;
    return 1;
}

int socket_client::init_epoll()
{
    if(_socket_fd < 0 || _epoll_handler == NULL)return -1;
    set_nodelay(_socket_fd,false);
    set_sock_noblock(_socket_fd,true);
    _epoll_handler->add_event_handler(_socket_fd,this);    
    return 1;
}

void socket_client::fini()
{
    _epoll_handler->del_event_handler(_socket_fd);
    close(_socket_fd);
}


#define MSG_BUFF_SIZE 2048
int socket_client::on_read() {
	char msg_buffer[MSG_BUFF_SIZE] = { 0 };
	int len = 0;
	while (true) {
		len = recv(_socket_fd, msg_buffer, MSG_BUFF_SIZE, 0);
		if (len == 0) {
			LOG(INFO)<<"client close socket .......";
			return -1;
		}

		if (len == -1) {
			if (errno != EAGAIN && errno != EINTR) {
				LOG(ERROR)<<"system error,close client";
				return -1;
			}
		}

		if (len > 0) {
			_recv_buffer.insert(_recv_buffer.end(), msg_buffer,
					msg_buffer + len);
			int msg_len = -1;
			while (_recv_buffer.size() > 0)
			{
#ifdef  _MSG_BASE_ 
				msg_len = check_msg_complete(_recv_buffer.data(),_recv_buffer.size());
                if(msg_len == -1)//message not complete 
                {
                    break; 
                }

				if (msg_len > MAX_MSG_SIZE) {
					return -1;
				}
#endif

#ifdef _MSG_PACKET_
                packet_info packet;
                msg_len = check_packet_info(_recv_buffer.data(),_recv_buffer.size(),&packet);
                if(msg_len == 0)break;

                if(msg_len < 0 )
                {
                    LOG(ERROR)<<"error decode message";
                    return msg_len;//error of message decode
                }
                process_msg(&packet); 
#endif
				_recv_buffer.erase(_recv_buffer.begin(),
						_recv_buffer.begin() + msg_len);
                return 1;
			}
		}
	}
	return 0;
}

int socket_client::on_write() {
	if (_send_buffer.size() <= 0) {
		return 0;
	}
	//send lock
	ScopeLock<MutexLock> lock(_lock);

	//send unlock
	int rst = ::send(_socket_fd, _send_buffer.data(), _send_buffer.size(), 0);
        if (rst < 0) {
            if (errno == EAGAIN || errno == EINTR) { //缓冲区满了。
                return 0;
            }
            //error should disconnect
            return -1;
        }
        //have data not send ,register write epoll event
        if (rst < (int) _send_buffer.size()) {
            _epoll_handler->mod_epoll_status(_socket_fd,this,EPOLLIN | EPOLLOUT);
        }

        if (rst == (int) _send_buffer.size()) {
            _epoll_handler->mod_epoll_status (_socket_fd,this,EPOLLIN);
        }
        if (rst != 0) {
            _send_buffer.erase(_send_buffer.begin(), _send_buffer.begin() + rst);
        }

        return rst;
    }

    int socket_client::on_error() {
        return 1;        
    }


    int socket_client::send_msg(const char* data_head, int send_size) {
        //if send buffer has data ,push data into buffer
        //send lock
        ScopeLock<MutexLock> lock(_lock);
        if (_send_buffer.size() > 0) {
		_send_buffer.insert(_send_buffer.end(), data_head,
				data_head + send_size);
		_epoll_handler->mod_epoll_status(_socket_fd,this,EPOLLIN | EPOLLOUT);
		return 0;
	}

	//send unlock
	int rst = ::send(_socket_fd, data_head, send_size, 0);
	if (rst < 0) {
		if (errno == EAGAIN || errno == EINTR) {        
			return 0;
		}
		//error should disconnect
		return -1;
	}
	//have data not send ,register write epoll event
	if (rst < send_size) {
		_epoll_handler->mod_epoll_status(_socket_fd,this,EPOLLIN | EPOLLOUT);
		_send_buffer.insert(_send_buffer.end(), data_head + rst,
				data_head + send_size);
	}

	return 0;
}

int socket_client::send_packet_msg(packet* p) {
	int size = p->encode_size();
	if (size < 1)
		return -1;
	char buffer[1024 * 8] = { 0 };
	size = p->encode(buffer, 1024 * 8);
	if (size < 1)
		return -1;
	return send_msg(buffer, size);
}

int socket_client::check_msg_complete(char *data_head, int size) {
	MsgBase* msg_head = (MsgBase*) data_head;
	if (size >= msg_head->msg_size) {
		return msg_head->msg_size;
	}
	return -1;
}

int socket_client::check_packet_info(char* data,int size,packet_info* info)
{
    cs_head* head = (cs_head*)data; 
    if(size < sizeof(cs_head))
    {
        //message not complete
        return  0;
    }
    else
    {
        info->size = (int)head->length;
        info->type = (int)head->msgid;
    }

    if(info->size < size)return 0;

    //message error
    if(info->size <0 || info->size > MAX_MSG_SIZE || info->type < 0 )return -1;
    info->data = data;
    return info->size;
}


} /* namespace omg */
