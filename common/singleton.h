#ifndef _TEMPLATE_SINGLETON_H_
#define _TEMPLATE_SINGLETON_H_

#include <cstdlib>
template<class T>
class Singleton
{
    protected:
        Singleton(){}
        ~Singleton(){}
    public:
        static T* GetInstance()
        {
            if(_instance == NULL)
            {
                _instance = new T;
            }
            return _instance;
        }
    private:
        static T* _instance;
};

template<class T> 
T* Singleton<T>::_instance = 0;
#endif


