#ifndef _LISTENER_H_
#define _LISTENER_H_

class socketlistenr
{
    public:
        virtual int on_accept(bufferevent* bev,evutil_socket_t fd) = 0;
};

#endif
