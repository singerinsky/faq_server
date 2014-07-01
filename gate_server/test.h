#include "template_message.h"
#include "head.h"

class t
{
    public:
        void print()
        {
            LOG(INFO)<<"sssssssss"; 
        }
};

class test:public template_message<t>
{

};
