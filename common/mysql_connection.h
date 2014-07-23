/*
 * MysqlConnection.h
 *
 *  Created on: 2012-2-10
 *      Author: lxyfirst@yahoo.com.cn
 */

#ifndef MYSQL_CONNECTION_H_
#define MYSQL_CONNECTION_H_

#include <stdint.h>
#include <stdlib.h>
#include "mysql/mysql.h"
#include <string>
using namespace std;


bool have_escape_char(const char* data,int size) ;
class MysqlResultRow
{
    public:
        MysqlResultRow(MYSQL_RES* result):_result(result)
    {
        _row_count =  mysql_num_rows(result) ;
        _start_index = 0;
    }

    public:
        bool next()
        {
            if(_data == NULL)return false; 
            if(_start_index >= _row_count)return false;
            mysql_data_seek(_result,_start_index) ;
            _data = (const char**)mysql_fetch_row(_result) ;
            _start_index++;
            return true;
        }

        int get_int(int column)
        {
            return atoi(_data[column]); 
        }

        int64_t get_int64(int column)
        {
            return atol(_data[column]); 
        }  

        std::string get_string(int column)
        {
            std::string str;
            str.assign(_data[column]);  
            return str;
        }

    private:
        size_t       _start_index;
        char** _data;
        size_t       _row_count;
        MYSQL_RES*   _result ;
};


class MysqlConnection
{
    public:
        MysqlConnection():m_result(NULL),m_connected(0) {  } ;
        ~MysqlConnection() { fini() ; } ;

        /*
         * @brief connect to mysql
         * @param [in] mysql hostname , socket file must begin with '/'
         * @param [in] username
         * @param [in] password
         * @param [in] port
         * @return 0 on success , -1 on failure
         */
        int init(const char* host,const char* user,const char* password,int port = 3306) ;
        /*
         * @brief close mysql connection
         */
        void fini() ;

        /*
         * @brief choose database
         * @param [in] database name
         * @return 0 on success , -1 on failure
         */
        int use(const char* dbname)
        {
            if(m_connected == 0 ) return -1 ;
            return mysql_select_db(&m_mysql,dbname) ;
        }

        int set_charset(const char* charset_name)
        {
            if(m_connected == 0 ) return -1 ;
            return mysql_set_character_set(&m_mysql,charset_name);
        }


        /*
         * @brief get mysql last errno
         */
        int get_errno()
        {
            return (int)mysql_errno(&m_mysql) ;
        }

        bool connected() const { return m_connected != 0 ; } ;
        int ping()
        {
            if(m_connected == 0 ) return -1 ;
            return mysql_ping(&m_mysql) ;
        }

        /*
         * @brief exec sql statement , result will be hold internally
         * @param [in] sql statement
         * @return 0 on success , -1 on failure
         */
        int exec(const char* sql) ;

        int exec_format(const char* fmt,...) ;

        int64_t result_insert_id()
        {
            return mysql_insert_id(&m_mysql) ;
        }

        int64_t result_affected_rows()
        {
            return mysql_affected_rows(&m_mysql) ;
        }

        void free_result()
        {
            if(m_result != NULL )
            {
                mysql_free_result(m_result) ;
                m_result = NULL ;
            }
        }

        int result_row_count()
        {
            if(m_result == NULL) return 0 ;
            return mysql_num_rows(m_result) ;
        }

        int result_field_count()
        {
            if(m_result == NULL) return 0 ;
            return mysql_num_fields(m_result) ;
        }


        const char** result_row_data(int rowno)
        {
            if(m_result == NULL) return NULL ;
            mysql_data_seek(m_result,rowno) ;
            return (const char**)mysql_fetch_row(m_result) ;
        }

        MysqlResultRow get_data_rows()
        {
            if(m_result == NULL) 
            {
                MysqlResultRow result_row(NULL,0);
                return result_row;
            }
            mysql_data_seek(m_result,0) ;
            MysqlResultRow result_row((const char**)mysql_fetch_row(m_result),result_row_count()) ;
            return result_row;
        }


    private:
        MysqlConnection(const MysqlConnection& o) ;
        MysqlConnection& operator=(const MysqlConnection& o) ;
    private:
        MYSQL m_mysql ;
        MYSQL_RES* m_result ;
        int m_connected ;
};


#endif /* MYSQL_CONNECTION_H_ */
