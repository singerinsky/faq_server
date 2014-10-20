#include "logic_player.h"
#include "db_message.pb.h"
#include "tb_user.pb.h"

void LogicPlayer::LoadPlayerInfo()
{

}

void LogicPlayer::InitPlayer(const db_tb_user& user_info)
{
//    LOG(INFO)<<"init user info from db info"<<user_info.user_name();
    _user_info = user_info;
}
