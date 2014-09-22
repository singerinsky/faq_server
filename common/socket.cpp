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
    {
        VLOG(2)<<"receive error mssage"<<head.length<<":"<<head.msgid;
        return -1;
    }

    int buffer_len = evbuffer_get_length(read_buffer);
    if(head.length > buffer_len)
    {
        VLOG(2)<<"data not ready"<<evbuffer_get_length(read_buffer)<<" require"<<head.length;
        return 0;
    }
    LOG(INFO)<<"receive message opcode "<<head.msgid;

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
    }else
    {
        LOG(INFO)<<"connect to "<<host_name<<":"<<port ; 
    }
    _is_online = true;
    init_cb();
    return 1;
}


//TODO
int socket_client::on_read(bufferevent* ev)
{
    evbuffer* input = bufferevent_get_input(ev); 
    if(evbuffer_get_length(input)< sizeof(cs_head))
    {
        LOG(INFO)<<"get uncomplete msg len"<<evbuffer_get_length(input);
        return 0; 
    }

    packet_info info;
    int msg_len = 0;
    while((msg_len = check_packet_info(&info,input)) > 0)
    {
        process_msg(&info);
        delete info.data;
    }

    //TODO断开链接
    if(msg_len < 0)
    {
        LOG(ERROR)<<"message error !"; 
        on_disconnection(_bev);
        return -1;
    }

    if(msg_len == 0)
        return 0;


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

int socket_client::send_packet(packet* p)
{
    int size = p->encode_size();
    char buffer[8096]={0};
    size = p->encode(buffer,8096);
    if(size <0)return -1;
    return send_msg(buffer,size); 
}

void socket_client::init_cb()
{
    bufferevent_setcb(_bev,common_read_cb,/*common_write_cb*/NULL,common_event_cb,this);
    bufferevent_enable(_bev,EV_READ);
    bufferevent_enable(_bev,EV_WRITE);
    bufferevent_enable(_bev,EV_PERSIST);
}

void common_read_cb(struct bufferevent* ev,void *user_data)
{
    ((socket_client*)user_data)->on_read(ev);
}

void common_event_cb(struct bufferevent* ev,short error_no,void *user_data)
{
    if(error_no == BEV_EVENT_CONNECTED)
    {
        VLOG(1)<<"build connection";
        ((socket_client*)user_data)->on_connection(ev);
    }
    else
    {
        VLOG(1)<<"lost connection"<<error_no;
        ((socket_client*)user_data)->on_disconnection(ev);
    }
}
void common_write_cb(struct bufferevent* ev,void *user_data)
{

}
