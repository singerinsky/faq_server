#ifndef _generate_h_role_info 
#define _generate_h_role_info 
#include <mysql++/mysql++.h>
#include "../message/role_info.pb.h"
#include "sql_binder.h"
class role_info : public sql_binder 
{
public:
    role_info();
    void clear_dirty(){ memset(dirty,0,sizeof(dirty)); } ;
    bool is_dirty() const
    {
        for(int i=0;i<FIELD_COUNT;++i) {if(dirty[i]) return true;} ;
        return false ;
    } ;
    void load(mysqlpp::Row&);
    int sql_insert(char* buf,int size) const;
    int sql_replace(char* buf,int size) const;
    int sql_update(char* buf,int size) const;
    int sql_query(char* buf,int size) const;
    int sql_delete(char* buf,int size) const;
protected:
    int sql_key(char* buf,int size) const;
    int sql_data(char* buf,int size,bool check_dirty=true) const;
public:
    int32_t get_role_id() const { return role_id;} ; 
    void set_role_id(int32_t value) { if(role_id!= value){dirty[0] = 1; role_id = value;} } ; 
    int sql_role_id(char* buf,int size) const{return snprintf(buf,size,"role_id='%lld'",(int64_t)role_id);}

    int32_t get_uid() const { return uid;} ; 
    void set_uid(int32_t value) { if(uid!= value){dirty[1] = 1; uid = value;} } ; 
    int sql_uid(char* buf,int size) const{return snprintf(buf,size,"uid='%lld'",(int64_t)uid);}

    int32_t get_tid() const { return tid;} ; 
    void set_tid(int32_t value) { if(tid!= value){dirty[2] = 1; tid = value;} } ; 
    int sql_tid(char* buf,int size) const{return snprintf(buf,size,"tid='%lld'",(int64_t)tid);}

    const string& get_name() const { return name;} ; 
    void set_name(const string& value) { if(name!= value){dirty[3] = 1; name.assign(value);} }; 
    void set_name(const char* value) { if(strcmp(name.c_str(),value)!=0) {dirty[3] = 1; name.assign(value);} }; 
    int sql_name(char* buf,int size) const{return snprintf(buf,size,"name='%s'",name.c_str());}

    int8_t get_gender() const { return gender;} ; 
    void set_gender(int8_t value) { if(gender!= value){dirty[4] = 1; gender = value;} } ; 
    int sql_gender(char* buf,int size) const{return snprintf(buf,size,"gender='%lld'",(int64_t)gender);}

    int8_t get_job_type() const { return job_type;} ; 
    void set_job_type(int8_t value) { if(job_type!= value){dirty[5] = 1; job_type = value;} } ; 
    int sql_job_type(char* buf,int size) const{return snprintf(buf,size,"job_type='%lld'",(int64_t)job_type);}

    int8_t get_role_level() const { return role_level;} ; 
    void set_role_level(int8_t value) { if(role_level!= value){dirty[6] = 1; role_level = value;} } ; 
    int sql_role_level(char* buf,int size) const{return snprintf(buf,size,"role_level='%lld'",(int64_t)role_level);}

    int32_t get_role_exp() const { return role_exp;} ; 
    void set_role_exp(int32_t value) { if(role_exp!= value){dirty[7] = 1; role_exp = value;} } ; 
    int sql_role_exp(char* buf,int size) const{return snprintf(buf,size,"role_exp='%lld'",(int64_t)role_exp);}

    int32_t get_costume_tid() const { return costume_tid;} ; 
    void set_costume_tid(int32_t value) { if(costume_tid!= value){dirty[8] = 1; costume_tid = value;} } ; 
    int sql_costume_tid(char* buf,int size) const{return snprintf(buf,size,"costume_tid='%lld'",(int64_t)costume_tid);}

    int32_t get_title() const { return title;} ; 
    void set_title(int32_t value) { if(title!= value){dirty[9] = 1; title = value;} } ; 
    int sql_title(char* buf,int size) const{return snprintf(buf,size,"title='%lld'",(int64_t)title);}

    int32_t get_coin() const { return coin;} ; 
    void set_coin(int32_t value) { if(coin!= value){dirty[10] = 1; coin = value;} } ; 
    int sql_coin(char* buf,int size) const{return snprintf(buf,size,"coin='%lld'",(int64_t)coin);}

    int32_t get_coupon() const { return coupon;} ; 
    void set_coupon(int32_t value) { if(coupon!= value){dirty[11] = 1; coupon = value;} } ; 
    int sql_coupon(char* buf,int size) const{return snprintf(buf,size,"coupon='%lld'",(int64_t)coupon);}

    int32_t get_diamond() const { return diamond;} ; 
    void set_diamond(int32_t value) { if(diamond!= value){dirty[12] = 1; diamond = value;} } ; 
    int sql_diamond(char* buf,int size) const{return snprintf(buf,size,"diamond='%lld'",(int64_t)diamond);}

    int32_t get_vip_end_ts() const { return vip_end_ts;} ; 
    void set_vip_end_ts(int32_t value) { if(vip_end_ts!= value){dirty[13] = 1; vip_end_ts = value;} } ; 
    int sql_vip_end_ts(char* buf,int size) const{return snprintf(buf,size,"vip_end_ts='%lld'",(int64_t)vip_end_ts);}

    int8_t get_vip_level() const { return vip_level;} ; 
    void set_vip_level(int8_t value) { if(vip_level!= value){dirty[14] = 1; vip_level = value;} } ; 
    int sql_vip_level(char* buf,int size) const{return snprintf(buf,size,"vip_level='%lld'",(int64_t)vip_level);}

    int16_t get_map_id() const { return map_id;} ; 
    void set_map_id(int16_t value) { if(map_id!= value){dirty[15] = 1; map_id = value;} } ; 
    int sql_map_id(char* buf,int size) const{return snprintf(buf,size,"map_id='%lld'",(int64_t)map_id);}

    int16_t get_map_x() const { return map_x;} ; 
    void set_map_x(int16_t value) { if(map_x!= value){dirty[16] = 1; map_x = value;} } ; 
    int sql_map_x(char* buf,int size) const{return snprintf(buf,size,"map_x='%lld'",(int64_t)map_x);}

    int16_t get_map_y() const { return map_y;} ; 
    void set_map_y(int16_t value) { if(map_y!= value){dirty[17] = 1; map_y = value;} } ; 
    int sql_map_y(char* buf,int size) const{return snprintf(buf,size,"map_y='%lld'",(int64_t)map_y);}

    int16_t get_last_map_id() const { return last_map_id;} ; 
    void set_last_map_id(int16_t value) { if(last_map_id!= value){dirty[18] = 1; last_map_id = value;} } ; 
    int sql_last_map_id(char* buf,int size) const{return snprintf(buf,size,"last_map_id='%lld'",(int64_t)last_map_id);}

    int16_t get_last_map_x() const { return last_map_x;} ; 
    void set_last_map_x(int16_t value) { if(last_map_x!= value){dirty[19] = 1; last_map_x = value;} } ; 
    int sql_last_map_x(char* buf,int size) const{return snprintf(buf,size,"last_map_x='%lld'",(int64_t)last_map_x);}

    int16_t get_last_map_y() const { return last_map_y;} ; 
    void set_last_map_y(int16_t value) { if(last_map_y!= value){dirty[20] = 1; last_map_y = value;} } ; 
    int sql_last_map_y(char* buf,int size) const{return snprintf(buf,size,"last_map_y='%lld'",(int64_t)last_map_y);}

    int16_t get_flag() const { return flag;} ; 
    void set_flag(int16_t value) { if(flag!= value){dirty[21] = 1; flag = value;} } ; 
    int sql_flag(char* buf,int size) const{return snprintf(buf,size,"flag='%lld'",(int64_t)flag);}

    int8_t get_status() const { return status;} ; 
    void set_status(int8_t value) { if(status!= value){dirty[22] = 1; status = value;} } ; 
    int sql_status(char* buf,int size) const{return snprintf(buf,size,"status='%lld'",(int64_t)status);}

    int32_t get_server_id() const { return server_id;} ; 
    void set_server_id(int32_t value) { if(server_id!= value){dirty[23] = 1; server_id = value;} } ; 
    int sql_server_id(char* buf,int size) const{return snprintf(buf,size,"server_id='%lld'",(int64_t)server_id);}

    int32_t get_create_time() const { return create_time;} ; 
    void set_create_time(int32_t value) { if(create_time!= value){dirty[24] = 1; create_time = value;} } ; 
    int sql_create_time(char* buf,int size) const{return snprintf(buf,size,"create_time='%lld'",(int64_t)create_time);}

    int32_t get_team_id() const { return team_id;} ; 
    void set_team_id(int32_t value) { if(team_id!= value){dirty[25] = 1; team_id = value;} } ; 
    int sql_team_id(char* buf,int size) const{return snprintf(buf,size,"team_id='%lld'",(int64_t)team_id);}

    int32_t get_team_create_time() const { return team_create_time;} ; 
    void set_team_create_time(int32_t value) { if(team_create_time!= value){dirty[26] = 1; team_create_time = value;} } ; 
    int sql_team_create_time(char* buf,int size) const{return snprintf(buf,size,"team_create_time='%lld'",(int64_t)team_create_time);}

    int16_t get_bag_size() const { return bag_size;} ; 
    void set_bag_size(int16_t value) { if(bag_size!= value){dirty[27] = 1; bag_size = value;} } ; 
    int sql_bag_size(char* buf,int size) const{return snprintf(buf,size,"bag_size='%lld'",(int64_t)bag_size);}

    int16_t get_depot_size() const { return depot_size;} ; 
    void set_depot_size(int16_t value) { if(depot_size!= value){dirty[28] = 1; depot_size = value;} } ; 
    int sql_depot_size(char* buf,int size) const{return snprintf(buf,size,"depot_size='%lld'",(int64_t)depot_size);}

    int8_t get_buddy_size() const { return buddy_size;} ; 
    void set_buddy_size(int8_t value) { if(buddy_size!= value){dirty[29] = 1; buddy_size = value;} } ; 
    int sql_buddy_size(char* buf,int size) const{return snprintf(buf,size,"buddy_size='%lld'",(int64_t)buddy_size);}

    int8_t get_lineup_size() const { return lineup_size;} ; 
    void set_lineup_size(int8_t value) { if(lineup_size!= value){dirty[30] = 1; lineup_size = value;} } ; 
    int sql_lineup_size(char* buf,int size) const{return snprintf(buf,size,"lineup_size='%lld'",(int64_t)lineup_size);}

    int32_t get_default_lineup_id() const { return default_lineup_id;} ; 
    void set_default_lineup_id(int32_t value) { if(default_lineup_id!= value){dirty[31] = 1; default_lineup_id = value;} } ; 
    int sql_default_lineup_id(char* buf,int size) const{return snprintf(buf,size,"default_lineup_id='%lld'",(int64_t)default_lineup_id);}

    int32_t get_lineup_capacity() const { return lineup_capacity;} ; 
    void set_lineup_capacity(int32_t value) { if(lineup_capacity!= value){dirty[32] = 1; lineup_capacity = value;} } ; 
    int sql_lineup_capacity(char* buf,int size) const{return snprintf(buf,size,"lineup_capacity='%lld'",(int64_t)lineup_capacity);}

    int32_t get_login_time() const { return login_time;} ; 
    void set_login_time(int32_t value) { if(login_time!= value){dirty[33] = 1; login_time = value;} } ; 
    int sql_login_time(char* buf,int size) const{return snprintf(buf,size,"login_time='%lld'",(int64_t)login_time);}

    int32_t get_last_logoff_time() const { return last_logoff_time;} ; 
    void set_last_logoff_time(int32_t value) { if(last_logoff_time!= value){dirty[34] = 1; last_logoff_time = value;} } ; 
    int sql_last_logoff_time(char* buf,int size) const{return snprintf(buf,size,"last_logoff_time='%lld'",(int64_t)last_logoff_time);}

    const string& get_login_ip() const { return login_ip;} ; 
    void set_login_ip(const string& value) { if(login_ip!= value){dirty[35] = 1; login_ip.assign(value);} }; 
    void set_login_ip(const char* value) { if(strcmp(login_ip.c_str(),value)!=0) {dirty[35] = 1; login_ip.assign(value);} }; 
    int sql_login_ip(char* buf,int size) const{return snprintf(buf,size,"login_ip='%s'",login_ip.c_str());}

    int32_t get_instance_count() const { return instance_count;} ; 
    void set_instance_count(int32_t value) { if(instance_count!= value){dirty[36] = 1; instance_count = value;} } ; 
    int sql_instance_count(char* buf,int size) const{return snprintf(buf,size,"instance_count='%lld'",(int64_t)instance_count);}

    int32_t get_instance_time() const { return instance_time;} ; 
    void set_instance_time(int32_t value) { if(instance_time!= value){dirty[37] = 1; instance_time = value;} } ; 
    int sql_instance_time(char* buf,int size) const{return snprintf(buf,size,"instance_time='%lld'",(int64_t)instance_time);}

    int32_t get_guild_id() const { return guild_id;} ; 
    void set_guild_id(int32_t value) { if(guild_id!= value){dirty[38] = 1; guild_id = value;} } ; 
    int sql_guild_id(char* buf,int size) const{return snprintf(buf,size,"guild_id='%lld'",(int64_t)guild_id);}

    int32_t get_guild_time() const { return guild_time;} ; 
    void set_guild_time(int32_t value) { if(guild_time!= value){dirty[39] = 1; guild_time = value;} } ; 
    int sql_guild_time(char* buf,int size) const{return snprintf(buf,size,"guild_time='%lld'",(int64_t)guild_time);}

    const string& get_guild_name() const { return guild_name;} ; 
    void set_guild_name(const string& value) { if(guild_name!= value){dirty[40] = 1; guild_name.assign(value);} }; 
    void set_guild_name(const char* value) { if(strcmp(guild_name.c_str(),value)!=0) {dirty[40] = 1; guild_name.assign(value);} }; 
    int sql_guild_name(char* buf,int size) const{return snprintf(buf,size,"guild_name='%s'",guild_name.c_str());}

    int32_t get_phy_strength() const { return phy_strength;} ; 
    void set_phy_strength(int32_t value) { if(phy_strength!= value){dirty[41] = 1; phy_strength = value;} } ; 
    int sql_phy_strength(char* buf,int size) const{return snprintf(buf,size,"phy_strength='%lld'",(int64_t)phy_strength);}

    int32_t get_extra_phy_strength() const { return extra_phy_strength;} ; 
    void set_extra_phy_strength(int32_t value) { if(extra_phy_strength!= value){dirty[42] = 1; extra_phy_strength = value;} } ; 
    int sql_extra_phy_strength(char* buf,int size) const{return snprintf(buf,size,"extra_phy_strength='%lld'",(int64_t)extra_phy_strength);}

    int32_t get_time_to_recover_phy_strength() const { return time_to_recover_phy_strength;} ; 
    void set_time_to_recover_phy_strength(int32_t value) { if(time_to_recover_phy_strength!= value){dirty[43] = 1; time_to_recover_phy_strength = value;} } ; 
    int sql_time_to_recover_phy_strength(char* buf,int size) const{return snprintf(buf,size,"time_to_recover_phy_strength='%lld'",(int64_t)time_to_recover_phy_strength);}

    int32_t get_time_to_recover_extra_phy_strength() const { return time_to_recover_extra_phy_strength;} ; 
    void set_time_to_recover_extra_phy_strength(int32_t value) { if(time_to_recover_extra_phy_strength!= value){dirty[44] = 1; time_to_recover_extra_phy_strength = value;} } ; 
    int sql_time_to_recover_extra_phy_strength(char* buf,int size) const{return snprintf(buf,size,"time_to_recover_extra_phy_strength='%lld'",(int64_t)time_to_recover_extra_phy_strength);}

    int32_t get_renown() const { return renown;} ; 
    void set_renown(int32_t value) { if(renown!= value){dirty[45] = 1; renown = value;} } ; 
    int sql_renown(char* buf,int size) const{return snprintf(buf,size,"renown='%lld'",(int64_t)renown);}

    void load_from_pb(const db_role_info&);
    void copy_to_pb(db_role_info&);
private:
    //data member
    int32_t role_id ; 
    int32_t uid ; 
    int32_t tid ; 
    string name ; 
    int8_t gender ; 
    int8_t job_type ; 
    int8_t role_level ; 
    int32_t role_exp ; 
    int32_t costume_tid ; 
    int32_t title ; 
    int32_t coin ; 
    int32_t coupon ; 
    int32_t diamond ; 
    int32_t vip_end_ts ; 
    int8_t vip_level ; 
    int16_t map_id ; 
    int16_t map_x ; 
    int16_t map_y ; 
    int16_t last_map_id ; 
    int16_t last_map_x ; 
    int16_t last_map_y ; 
    int16_t flag ; 
    int8_t status ; 
    int32_t server_id ; 
    int32_t create_time ; 
    int32_t team_id ; 
    int32_t team_create_time ; 
    int16_t bag_size ; 
    int16_t depot_size ; 
    int8_t buddy_size ; 
    int8_t lineup_size ; 
    int32_t default_lineup_id ; 
    int32_t lineup_capacity ; 
    int32_t login_time ; 
    int32_t last_logoff_time ; 
    string login_ip ; 
    int32_t instance_count ; 
    int32_t instance_time ; 
    int32_t guild_id ; 
    int32_t guild_time ; 
    string guild_name ; 
    int32_t phy_strength ; 
    int32_t extra_phy_strength ; 
    int32_t time_to_recover_phy_strength ; 
    int32_t time_to_recover_extra_phy_strength ; 
    int32_t renown ; 
private:
    //dirty flag for update
    enum { FIELD_COUNT = 46 } ; 
    int8_t dirty[FIELD_COUNT] ; 
};
#endif
