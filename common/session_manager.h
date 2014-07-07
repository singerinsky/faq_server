#ifndef _SESSION_MANAGER_H_
#define _SESSION_MANAGER_H_
#include "singleton.h"

template<class SessionIdType,class SessionType>
class session_manager:public Singleton<session_manager<SessionIdType,SessionType> >
{
    public:
        friend Singleton<session_manager<SessionIdType,SessionType> >;

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

        void remove_session(SessionIdType key)
        {
            auto itr = _session_map.find(key);
            if(itr == _session_map.end())
                return;
            delete itr->second;
           _session_map.erase(itr);  
        }

    private:
        std::map<SessionIdType,SessionType*>  _session_map;
};

#endif
