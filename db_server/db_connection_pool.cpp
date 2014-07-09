#include "db_connection_pool.h"

typedef db_pool sql_pool;
template<> 
sql_pool* Singleton<sql_pool>::_instance = 0;

