#ifndef _SERVER_MANAGE_H_
#define _SERVER_MANAGE_H
#include "../common/head.h"
#include "../net/socketclient.h"
#include "../net/packet.h"
#include "../net/game_packet.h"
#include <set>
#include "../common/timer_manager.h"
#include "../message/message_define.h"
#include <memory>


using namespace std;
using namespace omg;

enum
{
    WAIT_LOGIN = 1,
    ALREADY_LOGIN = 2,
    HEART_BEAT_TIME_OUT =3
};

class GameServerClient :public socket_client{
public:
	GameServerClient(int fd,
                    sockaddr_in& in,
                    epoll_handler* handler,
                    timer_manager* timer_mgr):socket_client(fd,in,handler){
        _timer_mgr = timer_mgr;    
        _timer.set_owner(this);        
        _timer.set_expired(ServerRun->get_run_ms()+5000);
        _timer_mgr->add_timer(&_timer);
        _connection_status = WAIT_LOGIN;
	}

	~GameServerClient(){
        VLOG(2)<<"delete game server client";
	}

    void on_timeout(timer_manager* timer_mgr);

    int on_error();

    void reset();
    void set_connection_status(int value)
    {
        _connection_status = value;
    }

    int process_msg(packet_info * packet);

    int do_get_soccer_player_info(const packet_info* packet);
    int do_check_client_log(const packet_info* packet);
    int do_register_gate(const packet_info* packet);
    int do_common_update_del(const packet_info* packet);
public:
	int index;
	std::set<int> _match_list;
private:
    template_timer<GameServerClient,&GameServerClient::on_timeout> _timer;
    timer_manager* _timer_mgr;
private:
    int _connection_status;
};


typedef shared_ptr<GameServerClient>   game_client_spr;

class CServerManage {
protected:
	CServerManage() {
		_lock.init();
	}

public:
	static CServerManage* GetInstance() {
		if (_m_instance == NULL) {
			_m_instance = new CServerManage();
		}
		return _m_instance;
	}

	void RegisterServer(int index, game_client_spr client) {
		VLOG(2)<<"GateServer from "<<client->get_ip_port_str().c_str();
		_server_map[index] = client;
	}

	void RemoveServer(int index){
		SERVER_ITR itr = _server_map.find(index);
		if(itr != _server_map.end()){
			_server_map.erase(itr);
		}
	}

    game_client_spr GetGameServerByIndex(int index)
    {
        _lock.lock();
        std::map<int,game_client_spr>::iterator itr;
        itr = _server_map.find(index);
		if(itr != _server_map.end()) {
				_lock.unlock();
				return itr->second;
		}
		_lock.unlock();
		return NULL;
	
    }

	game_client_spr GetGameServerBySocketFd(int fd){
		_lock.lock();
		SERVER_ITR itr = _server_map.begin();
		while(itr != _server_map.end()) {
			if(fd == itr->second->get_socket_fd()){
				_lock.unlock();
				return itr->second;
			}
			itr++;
		}
		_lock.unlock();
		return NULL;
	}

    int GetMatchServerOnlineCount(){
		return _server_map.size();	
	}

private:
	static CServerManage* _m_instance;
	omg::MutexLock _lock;
	std::map<int,game_client_spr> _server_map;
	typedef std::map<int,game_client_spr>::iterator SERVER_ITR;
};

#endif
