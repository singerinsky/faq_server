#include "singleton.h"
#include "head.h"

class ReactorCore:public Singleton<ReactorCore>
{
    public:
        friend Singleton<ReactorCore>;
    public:
        bool init();
        event_base* GetEventBase(){return _base;} 
        void        AddEvent(){}
        void        RemoveEvent(){}

    private:
        event_base* _base;

};
