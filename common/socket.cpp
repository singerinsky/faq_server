#include "socket.h"
#include "net_util.h"
#include "packet.h"
#include "game_packet.h"
#include "head.h"


socket_client::~socket_client()
{
    if(_bev != NULL)
        bufferevent_free(_bev);

}

int socket_client::check_packet_info(packet_info* packet,struct evbuffer* read_buffer)
{
    cs_head head;
    evbuffer_copyout(read_buffer,(void*)&head,sizeof(cs_head));
    if(head.length < 0 || head.msgid < 0)
        return -1;

    if(head.length > evbuffer_get_length(read_buffer))
    {
        VLOG(2)<<"data not ready"<<evbuffer_get_length(read_buffer);
        return 0;
    }

    char* buffer = new char[head.length];
    int total_size = evbuffer_remove(read_buffer,buffer,head.length);
    if(total_size != head.length)
        return -1;
    packet->size = (int)head.length;
    packet->type = (int)head.msgid;
    packet->data = buffer;

    return packet->size;
}

int socket_client::connect_to(const char* host_name,int port)
{
    if(_bev == NULL)
    {
        LOG(ERROR)<<"bufferevent not init!!!";
        return -1;
    }

    sockaddr_in addr_in;
    int rst = init_sa_in(&addr_in, host_name,port);
    if(rst < 0)
    {
        LOG(ERROR)<<"init socket addr"<<host_name<<":"<<port<<" error";
        return -2;
    }
 
    if(bufferevent_socket_connect(_bev,(struct sockaddr*)&addr_in,sizeof(addr_in)) < 0 )
    {
        bufferevent_free(_bev);
        LOG(ERROR)<<"connect failed";
        return -2;
    }
    return 1;
}

//TODO
int socket_client::on_read(bufferevent* ev)
{
    evbuffer* input = bufferevent_get_input(ev); 
    if(evbuffer_get_length(input)< sizeof(cs_head))
    {
        return 0; 
    }
    
    packet_info info;
    int msg_len = check_packet_info(&info,input);
    //TODO断开链接
    if(msg_len < 0)
    {
        LOG(ERROR)<<"message error !"; 
        on_error(_bev);
        return -1;
    }

    if(msg_len == 0)
        return 0;
   
    process_msg(&info);

    /*
    int n = 0;
    while ((n = evbuffer_remove(input, buf, sizeof(buf))) > 0) {
        //fwrite(buf, 1, n, stdout);
        LOG(INFO)<<buf;
    }
    */
    return 1;
}

int socket_client::on_write(bufferevent* ev)
{
    return 1;
}

int socket_client::send_msg(const char* buffer,int size)
{
    return bufferevent_write(_bev,buffer,size);
}

void socket_client::init_cb()
{

}
