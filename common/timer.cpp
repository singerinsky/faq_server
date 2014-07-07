#include "timer.h"

void common_timeout_call(evutil_socket_t socket_t,short param,void *arg)
{
    if(arg != NULL)
    {
        ((base_timer*)(arg))->on_timeout();
    }
}
