#ifndef _DB_CONNECTION_H_
#define _DB_CONNECTION_H_
#include "mysql/mysql.h"
#include "object_pool.h"
#include "mysql_connection.h"

struct mysql_config
{
    std::string _ip;
    int         _port;
    std::string _user;
    std::string _pwd;
    std::string _dbname;
};

class db_pool:public object_pool<MysqlConnection>
{
    public:
       bool init_config();
       MysqlConnection* create()
        {
            MysqlConnection* conn = new MysqlConnection();
            int rst = conn->init(_config._ip.c_str(),_config._user.c_str(),_config._pwd.c_str(),_config._port);
            if(rst != 0)
            {
                delete conn;
                return NULL; 
            }
            conn->use(_config._dbname.c_str());
            return conn;
        }

    private:
       mysql_config _config;

};

#endif
