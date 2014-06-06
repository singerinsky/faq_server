#include "gate_application.h"


gate_application::gate_application()
{

}

gate_application::~gate_application()
{

}

bool gate_application::init()
{
    LOG(INFO)<<"init gate_application...";
    return true;
}

int main()
{
    gate_application app;
    app.init();
    app.start_service(false);
    return 0;
}

