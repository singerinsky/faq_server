#include "state.h"
#include "npc_object.h"
#include "logic_player.h"
#include "player_manager.h"

void NpcWaitState::Run()
{
    VLOG(1)<<"npc"<< _t->get_name()<<" wait ,check any player enter";    
    LogicPlayer* player = _t->get_nearest_player();
    if(player == NULL)
    {
        return; 
    }
    VLOG(1)<<"player "<<player->GetDbUserInfo().get_id()<<" is near";
    NpcChasePlayerState* state = new NpcChasePlayerState();
    state->SetTarget(player->GetDbUserInfo().get_id());
    state->SetOwner(this->_t);
}

void NpcChasePlayerState::Run()
{
    LogicPlayer* player =  Singleton<LogicPlayerManager>::GetInstance()->GetPlayer(_target);
    if(player == NULL)
    {
        NpcWaitState* wait_state = new NpcWaitState(); 
        wait_state->SetOwner(_t);
        return;
    }
    VLOG(1)<<" move to player"<< player->GetDbUserInfo().get_user_name() <<" x:"<<player->GetPos().pos_x()<<" y:"<<player->GetPos().pos_y();
    _t->move(player->GetPos());
    VLOG(1)<<" npc position x:"<<_t->GetPos().pos_x()<<"  y"<<_t->GetPos().pos_y();
    //move to player ,when near player attack it
    double distance = _t->GetPos().square_distance_to(player->GetPos()); 
    if(distance <= 2)
    {
       _t->Attack(player);  
    }
}

void NpcChasePlayerState::Enter()
{
    VLOG(1)<<" npc "<<_t->get_id()<<" enter chase player"<<_target;
}

void NpcChasePlayerState::Leave()
{

}
