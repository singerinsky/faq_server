#ifndef _GATE_CLIENT_H_
#define _GATE_CLEINT_H_
#include "socket.h"
#include "timer.h"
#include "logic_player.h"

enum
{
    UN_LOGIN,
    HAS_LOGIN, 
    HAS_LOAD,
};

class gate_client: public socket_client
{
    public:
        //bufferevent* bev,int socket,sockaddr_in& addr
        gate_client(bufferevent* bev,evutil_socket_t socket,sockaddr_in* addr
                ):socket_client(bev,socket,addr)
        {
            init();
            _login_status = UN_LOGIN;
        }
        virtual ~gate_client();

        void init();
        void init_timer();

    public:
        int process_msg(packet_info* info);
        void on_error(bufferevent* ev);
        void on_timeout();
        void init_player();
        const LogicPlayer& get_player_info() const
        {
            return _player_info; 
        }

        LogicPlayer& get_player_info()
        {
            return _player_info; 
        }

        void set_role_id(int role_id)
        {
            _role_id = role_id;
        }

    private:
        int  _role_id;
        int  _login_status;
        template_timer<gate_client,&gate_client::on_timeout>    _m_timer;
        LogicPlayer  _player_info;
};

#endif
