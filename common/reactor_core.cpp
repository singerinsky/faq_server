#include "reactor_core.h"

bool ReactorCore::init()
{
    _base = event_base_new(); 
    if(_base)
    {
        LOG(ERROR)<<"init event base failed"; 
        return false;
    }
    return true;
}
