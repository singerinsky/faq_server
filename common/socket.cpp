#include "socket.h"
#include "head.h"

socket_client::~socket_client()
{
    if(_bev != NULL)
        bufferevent_free(_bev);

}

int socket_client::get_packet_info(const char* buffer,int size)
{

    return 1;
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
        buffereven_free(_bev);
        LOG(ERROR)<<"connect failed";
        return -2;
    }
}

//TODO
int socket_client::on_read(bufferevent* ev)
{
    return 1;
}

int socket_client::on_wirte(bufferevent* ev)
{
    return 1;
}
