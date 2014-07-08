/*
 * DBConnectionPool.cpp
 *
 *  Created on: 2012-3-16
 *      Author: root
 */

#include "DBConnectionPool.h"


DBConnectionPool* DBConnectionPool::_m_instance;
DBConnectionPool::~DBConnectionPool() {
	// TODO Auto-generated destructor stub
}

mysqlpp::Connection * DBConnectionPool::create(){
//	mysqlpp::Connection* conn =  new mysqlpp::Connection("football","192.168.89.58","testtest","testtest");

	mysqlpp::Connection* conn =  new mysqlpp::Connection(false);//"football","192.168.89.13","root","firefly");
	conn->set_option(new SetCharsetNameOption("UTF8"));
	conn->set_option(new ReconnectOption (true));
	bool connect_rst = conn->connect((db_.empty() ? 0 : db_.c_str()),
					(server_.empty() ? 0 : server_.c_str()),
					(user_.empty() ? 0 : user_.c_str()),
					(password_.empty() ? "" : password_.c_str()),
					(port_== 0)?3306:port_);

	if(connect_rst == false){
		LOG(ERROR)<<"ERROR Connect Server";
        return NULL;
	}else{
		LOG(INFO)<<"Create database pool success...";
	}
	return conn;
}

void DBConnectionPool::destroy(mysqlpp::Connection* conn){
	delete conn;
}
