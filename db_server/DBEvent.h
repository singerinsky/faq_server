/*
 * DBEvent.h
 *
 *  Created on: 2012-3-16
 *      Author: root
 */

#ifndef DBEVENT_H_
#define DBEVENT_H_
#include "../net/msg.h"
#pragma pack(1)

enum {
	MSG_INIT_MATCH = 2000, //init match from db
	MSG_TYPE_SERVER_REQ = 2001,//server to server msg begin
	MSG_TYPE_MATCH_INFO,
	MSG_TYPE_SERVER_REGISTER,
	MSG_TYPE_MATCH_MOVE = 2008, //tell game server to start move
	MSG_TYPE_GTODB_SERVER_MATCH_END = 2010,//tell db to end game
	MSG_TYPE_GTODB_SERVER_ROUND_EVENT_DATA = 2011,
	MSG_TYPE_GTODB_PLAYER_UPDATE = 2013,//update player info
	MSG_TYPE_GTODB_MATCH_EVENT_WB = 2017,
	MSG_TYPE_GTODB_START_ARENA = 2019,
	MSG_TYPE_UPDATE_GSERVER
};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Client Msg Define Begin
/////////////////////////////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Server Msg Define Begin
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

struct MsgServerReq: MsgBase {
	int _server_typ;
	int _index;
	MsgServerReq() {
		msg_size = sizeof(MsgServerReq);
		msg_type = MSG_TYPE_SERVER_REQ;
	}
};

//服务器注册信号
struct MsgServerRegister: MsgBase {
	int _server_type;
	int _index;
	char	_version[20];
	MsgServerRegister() {
		msg_size = sizeof(MsgServerRegister);
		msg_type = MSG_TYPE_SERVER_REGISTER;
	}
};

//比赛初始化
struct MsgInitMatch: MsgBase {
	int mid;
	int cid;
	int op_cid;
	int match_typ;
	int is_new_bie;
	bool need_win;
	bool is_home_all_attack;
	int total_time_scale;
	MsgInitMatch() {
		msg_type = MSG_INIT_MATCH;
		msg_size = sizeof(MsgInitMatch);
		mid = 0;
		cid = 0;
		op_cid = 0;
		match_typ = 0;
		is_new_bie = 0;
		is_home_all_attack = false;
	}
};

//生成比赛
struct MsgRunMatch: MsgBase {
	int mid;
	MsgRunMatch() {
		msg_type = MSG_TYPE_MATCH_MOVE;
		msg_size = sizeof(MsgRunMatch);
	}
};

//球员的技能
struct PlayerSkill {
	unsigned short skill_id;
	unsigned short skill_level;
	unsigned short skill_chance;
};

//球员的属性
struct MsgPlayerInfo {
	MsgPlayerInfo() {
		pid = 0;
		pos_index = 0;
		is_gk = 0;
		attr_numbers = 0;
		att_value = 0;
		def_value = 0;
		cond = 0;
		memset(player_name, 0, 20);
	}
	int pid;
	char player_name[20];
	int level;
	int pos_index;
	short is_gk;
	int attr_numbers;
	int att_value;
	int def_value;
	unsigned short cond;
	unsigned short attr[19];
	unsigned short skill_count;
	PlayerSkill player_skills[10];
};

//球队的技能
struct TeamSkill {
	int tactic_id;
	int chance;
};

struct MsgMoveOperator {
	int uid;
	int club_level;
	int formation_id;
	int formation_level;
	int tactic_id;
	int propaganda_id;
	int att_value;
	int def_value;
	int default_att_value;
	int default_def_value;
	int default_coach_speak;
	int	alias_tactic_plus;
	short	fitness_coach;
	MsgPlayerInfo player_info[16];
	int team_skill_count;
	TeamSkill team_skills[10];
	MsgMoveOperator() {
		uid = 0;
		formation_id = 0;
		formation_level = 0;
		tactic_id = 0;
		propaganda_id = 0;
		team_skill_count = 0;
		default_coach_speak = -1;
	}
};

struct MsgMatchTeamInfo: MsgBase {
	MsgMatchTeamInfo() {
		msg_type = MSG_TYPE_MATCH_INFO;
		msg_size = sizeof(MsgMatchTeamInfo);
		npc_rate = 0;
	}
	int mid;
	int type;
	bool need_win;
	bool is_home_all_attack;
	int is_home_in_new_bie;
	int npc_rate;
	int	total_time_scale;
	int match_key;
	MsgMoveOperator op1;
	MsgMoveOperator op2;
	int formation1[16];
	int formation2[16];
};

//球员的属性写回
struct MsgGameToDbServerPlayerUpdate: MsgBase {
	int mid;
	int strlen;
	char data[3000];
	MsgGameToDbServerPlayerUpdate() {
		msg_size = sizeof(MsgGameToDbServerPlayerUpdate);
		msg_type = MSG_TYPE_GTODB_PLAYER_UPDATE;
		is_encode = 0;
	}
};

//数据服务器比赛结束
struct MsgGameToDbServerMatchEnd: MsgBase {
	int mid;
	int home_cid;
	int away_cid;
	int typ;
	unsigned short home_score;
	unsigned short away_score;
	unsigned short home_possession;
	unsigned short away_possession;
	unsigned short shot_h;
	unsigned short shot_a;
	unsigned short shot_on_h;
	unsigned short shot_on_a;
	unsigned short penlty_h;
	unsigned short penlty_a;
	char			statis_data[1];
	MsgGameToDbServerMatchEnd() {
		msg_type = MSG_TYPE_GTODB_SERVER_MATCH_END;
		is_encode = 0;
		shot_h = 0;
		shot_a = 0;
		shot_on_h = 0;
		shot_on_a = 0;
	}
};

struct MatchEventWB {
	int timescale;
	int type;
	int cid;
	int pid;
	int op_pid;
};

//比赛中的事件
struct MsgGameEventDBWB: MsgBase {
	MsgGameEventDBWB() {
		msg_type = MSG_TYPE_GTODB_MATCH_EVENT_WB;
		is_encode = 0;
		msg_size = sizeof(MsgGameEventDBWB);
	}
	int mid;
	int time_scale_start;
	int event_count;
	MatchEventWB event[2];
	//GameEvent	data[1];
};

struct MsgMatchArenaStartArena: MsgBase {
	MsgMatchArenaStartArena() {
		msg_type = MSG_TYPE_GTODB_START_ARENA;
		msg_size = sizeof(MsgMatchArenaStartArena);
		is_encode = 0;
	}
	int home_cid;
	int away_cid;
	int	key;
};

//游戏服务器的状态
struct MsgUpdateGServerInfo:MsgBase{
	int index;
	int server_typ;
	char version[20];
	MsgUpdateGServerInfo(){
		msg_type = MSG_TYPE_UPDATE_GSERVER;
		msg_size = sizeof(MsgUpdateGServerInfo);
		is_encode = 0;
	}
};

#pragma pack()

#endif /* DBEVENT_H_ */
