#ifndef _STATE_H_
#define _STATE_H_
#include "head.h"

enum{
    NPC_STATE_WAIT =0,
};

class State
{
    public:
        virtual ~State(){}
        virtual void Run() = 0;
        virtual void Enter() = 0;
        virtual void Leave() = 0;
        virtual int  GetStateType() = 0;
};

class StateObject
{
    public:
        virtual ~StateObject()
        {
            delete _state;
            _state = NULL;
        }
        State* GetState()
        {
            return _state; 
        }

        void SetState(State* state)
        {
            _state = state; 
        }

    protected:
        State*  _state;
};


class NpcObject;

template<class T,int StateType>
class BaseState:public State
{
    public:
        virtual ~BaseState(){}
        void SetOwner(T* t)
        {
            if (t->GetState() != NULL)
            {
                t->GetState()->Leave(); 
                delete t->GetState();
            }
            
            t->SetState(this); 
            _t = t;
            Enter();
        }
        virtual void Run() = 0;
        virtual void Enter() = 0;
        virtual void Leave() = 0;
        int          GetStateType()
        {
            return _state_type; 
        }
    protected:
        T*  _t;
    public:
        enum
        {
            _state_type = StateType, 
        };

};

class NpcWaitState:public BaseState<NpcObject,NPC_STATE_WAIT>
{
    public:
        virtual ~NpcWaitState(){}
        void Run();
        void Enter(){}
        void Leave(){}
};

#endif
