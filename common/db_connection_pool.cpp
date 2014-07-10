#include "db_connection_pool.h"

template<> 
db_pool* Singleton<db_pool>::_instance = 0;

