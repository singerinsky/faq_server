#ifndef OBJECT_POOL_H_
#define OBJECT_POOL_H_
#include "head.h"
#include <list>
#include "singleton.h"

template<class T>
class object_pool:public Singleton<object_pool<T> >
{
    protected:
        virtual T*  create() = 0;
    public:
        friend class Singleton<object_pool<T> >;
        int     init(int number)
        {
            for(int i=0;i<number;i++)
            {
                T* t = create();
                if(t != NULL)
                {
                    _object_list.push_back(t); 
                }else
                {
                    LOG(ERROR)<<"create object error"; 
                }
                
            }
            return _object_list.size();
        }
        T*      pop()
        {
            if(_object_list.size() == 0 )return NULL;
            T* t = (_object_list.front()); 
            _object_list.pop_front();
            return t;
        }

        void    push(T* t)
        {
            _object_list.push_back(t); 
        }

        int     current_size()
        {
            return _object_list.size(); 
        }


    
    private:
        std::list<T*>   _object_list;
};

#endif
