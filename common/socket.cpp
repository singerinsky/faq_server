#include "socket.h"
#include "net_util.h"

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
        bufferevent_free(_bev);
        LOG(ERROR)<<"connect failed";
        return -2;
    }
}

//TODO
int socket_client::on_read(bufferevent* ev)
{
    char buf[1024];
    evbuffer* input = bufferevent_get_input(ev); 
    int n = 0;
    while ((n = evbuffer_remove(input, buf, sizeof(buf))) > 0) {
        fwrite(buf, 1, n, stdout);
    }
    return 1;
}

int socket_client::on_write(bufferevent* ev)
{
    return 1;
}
