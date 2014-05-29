#ifndef _TEMPLATE_SINGLETON_H_
#define _TEMPLATE_SINGLETON_H_

template<class T>
class Singleton
{

    protected:
        Singleton(){}
        ~Singleton(){}
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

#endif


