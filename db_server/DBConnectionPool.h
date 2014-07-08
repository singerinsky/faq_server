/*
 * DBConnectionPool.h
 *
 *  Created on: 2012-3-16
 *      Author: root
 */

#ifndef DBCONNECTIONPOOL_H_
#define DBCONNECTIONPOOL_H_
#include <mysql++/mysql++.h>
#include "../common/head.h"
using namespace mysqlpp;

struct DBServerInfo{
	std::string server_ip;
	std::string data_base_ip;
	int			listening_port;
	int			port;
	std::string	db_name;
	std::string	username;
	std::string	password;
};

extern DBServerInfo g_db_server_info;
class DBConnectionPool: public mysqlpp::ConnectionPool {
private:
	DBConnectionPool(DBServerInfo* server_info):
		conns_in_use(0),
		db_(server_info->db_name),
		server_(server_info->data_base_ip),
		user_(server_info->username),
		password_(server_info->password),
		port_(server_info->port){
		LOG(INFO)<<"Init database "<<server_info->db_name<<" ip:"<<server_info->data_base_ip<<" port:"<<server_info->port;
        mysqlpp::Connection* temp_conn = create();
        if(temp_conn == NULL)
        {
            LOG(ERROR)<<"Connect mysql server error!";
            exit(1);
        }
        delete temp_conn;
	}
public:
	virtual ~DBConnectionPool();
	static DBConnectionPool* GetInstance(){
		if(_m_instance == NULL){
			_m_instance = new DBConnectionPool(&g_db_server_info);
		}
		return _m_instance;
	}

protected:
	mysqlpp::Connection *create();
	void destroy(mysqlpp::Connection*);
	unsigned int max_idle_time(){
		return 2;
	};

private:
	unsigned int conns_in_use;

	// Our connection parameters
	std::string db_;
	std::string server_;
	std::string	user_;
	std::string	password_;
	int			port_;
	static DBConnectionPool *_m_instance;

};

#define SQLConnection mysqlpp::Connection
#define SQLPool mysqlpp::ConnectionPool

#endif /* DBCONNECTIONPOOL_H_ */
