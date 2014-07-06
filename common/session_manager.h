#ifndef _SESSION_MANAGER_H_
#define _SESSION_MANAGER_H_
#include "singleton.h"

template<class SessionIdType,classs SessionType>
class session_manager:public Singleton<session_manager>
{
    public:
        friend Singleton<session_manager>;

    public:
        bool add_session(SessionIdType key,SessionType* value)
        {
            auto itr = _session_map.find(key); 
            if(itr == _session_map.end())
            {
                _session_map[key] = value; 
                return true;
            }
            return false;
        }

        SessionType* get_session(SessionIdType key)
        {
            auto itr = _session_map.find(key);
            if(itr == _session_map.end())
            {
                return NULL; 
            }
            return itr->second; 
        }

    private:
        std::map<SessionIdType,SessionIdType*>  _session_map;
};

#endif
