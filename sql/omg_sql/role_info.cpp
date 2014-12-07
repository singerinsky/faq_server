#include "role_info.h" 

role_info::role_info()
{
    role_id = 0;
    uid = 0;
    tid = 0;
    gender = 0;
    job_type = 0;
    role_level = 0;
    role_exp = 0;
    costume_tid = 0;
    title = 0;
    coin = 0;
    coupon = 0;
    diamond = 0;
    vip_end_ts = 0;
    vip_level = 0;
    map_id = 0;
    map_x = 0;
    map_y = 0;
    last_map_id = 0;
    last_map_x = 0;
    last_map_y = 0;
    flag = 0;
    status = 0;
    server_id = 0;
    create_time = 0;
    team_id = 0;
    team_create_time = 0;
    bag_size = 0;
    depot_size = 0;
    buddy_size = 0;
    lineup_size = 0;
    default_lineup_id = 0;
    lineup_capacity = 0;
    login_time = 0;
    last_logoff_time = 0;
    instance_count = 0;
    instance_time = 0;
    guild_id = 0;
    guild_time = 0;
    phy_strength = 0;
    extra_phy_strength = 0;
    time_to_recover_phy_strength = 0;
    time_to_recover_extra_phy_strength = 0;
    renown = 0;
    memset(dirty,1,sizeof(dirty));
}
void role_info::load(mysqlpp::Row& row)
{
    role_id = (int32_t)atoi(row["role_id"]);
    uid = (int32_t)atoi(row["uid"]);
    tid = (int32_t)atoi(row["tid"]);
    name.assign(row["name"]);
    gender = (int8_t)atoi(row["gender"]);
    job_type = (int8_t)atoi(row["job_type"]);
    role_level = (int8_t)atoi(row["role_level"]);
    role_exp = (int32_t)atoi(row["role_exp"]);
    costume_tid = (int32_t)atoi(row["costume_tid"]);
    title = (int32_t)atoi(row["title"]);
    coin = (int32_t)atoi(row["coin"]);
    coupon = (int32_t)atoi(row["coupon"]);
    diamond = (int32_t)atoi(row["diamond"]);
    vip_end_ts = (int32_t)atoi(row["vip_end_ts"]);
    vip_level = (int8_t)atoi(row["vip_level"]);
    map_id = (int16_t)atoi(row["map_id"]);
    map_x = (int16_t)atoi(row["map_x"]);
    map_y = (int16_t)atoi(row["map_y"]);
    last_map_id = (int16_t)atoi(row["last_map_id"]);
    last_map_x = (int16_t)atoi(row["last_map_x"]);
    last_map_y = (int16_t)atoi(row["last_map_y"]);
    flag = (int16_t)atoi(row["flag"]);
    status = (int8_t)atoi(row["status"]);
    server_id = (int32_t)atoi(row["server_id"]);
    create_time = (int32_t)atoi(row["create_time"]);
    team_id = (int32_t)atoi(row["team_id"]);
    team_create_time = (int32_t)atoi(row["team_create_time"]);
    bag_size = (int16_t)atoi(row["bag_size"]);
    depot_size = (int16_t)atoi(row["depot_size"]);
    buddy_size = (int8_t)atoi(row["buddy_size"]);
    lineup_size = (int8_t)atoi(row["lineup_size"]);
    default_lineup_id = (int32_t)atoi(row["default_lineup_id"]);
    lineup_capacity = (int32_t)atoi(row["lineup_capacity"]);
    login_time = (int32_t)atoi(row["login_time"]);
    last_logoff_time = (int32_t)atoi(row["last_logoff_time"]);
    login_ip.assign(row["login_ip"]);
    instance_count = (int32_t)atoi(row["instance_count"]);
    instance_time = (int32_t)atoi(row["instance_time"]);
    guild_id = (int32_t)atoi(row["guild_id"]);
    guild_time = (int32_t)atoi(row["guild_time"]);
    guild_name.assign(row["guild_name"]);
    phy_strength = (int32_t)atoi(row["phy_strength"]);
    extra_phy_strength = (int32_t)atoi(row["extra_phy_strength"]);
    time_to_recover_phy_strength = (int32_t)atoi(row["time_to_recover_phy_strength"]);
    time_to_recover_extra_phy_strength = (int32_t)atoi(row["time_to_recover_extra_phy_strength"]);
    renown = (int32_t)atoi(row["renown"]);
    memset(dirty,0,sizeof(dirty));
}
int role_info::sql_key(char* buf,int size) const
{
    int origin_size = size ,len = 0; 
    len =sql_role_id(buf,size);
    buf += len ; size -= len ;
    return origin_size - size ; 
} 
int role_info::sql_data(char* buf,int size,bool check_dirty) const
{
    int origin_size = size,len=0 ; 
    int first_flag = 1 ; 
    if((!check_dirty) || dirty[0])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_role_id(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if((!check_dirty) || dirty[1])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_uid(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if((!check_dirty) || dirty[2])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_tid(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if((!check_dirty) || dirty[3])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_name(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if((!check_dirty) || dirty[4])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_gender(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if((!check_dirty) || dirty[5])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_job_type(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if((!check_dirty) || dirty[6])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_role_level(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if((!check_dirty) || dirty[7])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_role_exp(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if((!check_dirty) || dirty[8])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_costume_tid(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if((!check_dirty) || dirty[9])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_title(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if((!check_dirty) || dirty[10])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_coin(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if((!check_dirty) || dirty[11])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_coupon(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if((!check_dirty) || dirty[12])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_diamond(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if((!check_dirty) || dirty[13])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_vip_end_ts(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if((!check_dirty) || dirty[14])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_vip_level(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if((!check_dirty) || dirty[15])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_map_id(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if((!check_dirty) || dirty[16])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_map_x(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if((!check_dirty) || dirty[17])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_map_y(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if((!check_dirty) || dirty[18])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_last_map_id(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if((!check_dirty) || dirty[19])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_last_map_x(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if((!check_dirty) || dirty[20])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_last_map_y(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if((!check_dirty) || dirty[21])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_flag(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if((!check_dirty) || dirty[22])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_status(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if((!check_dirty) || dirty[23])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_server_id(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if((!check_dirty) || dirty[24])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_create_time(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if((!check_dirty) || dirty[25])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_team_id(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if((!check_dirty) || dirty[26])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_team_create_time(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if((!check_dirty) || dirty[27])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_bag_size(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if((!check_dirty) || dirty[28])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_depot_size(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if((!check_dirty) || dirty[29])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_buddy_size(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if((!check_dirty) || dirty[30])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_lineup_size(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if((!check_dirty) || dirty[31])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_default_lineup_id(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if((!check_dirty) || dirty[32])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_lineup_capacity(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if((!check_dirty) || dirty[33])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_login_time(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if((!check_dirty) || dirty[34])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_last_logoff_time(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if((!check_dirty) || dirty[35])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_login_ip(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if((!check_dirty) || dirty[36])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_instance_count(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if((!check_dirty) || dirty[37])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_instance_time(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if((!check_dirty) || dirty[38])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_guild_id(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if((!check_dirty) || dirty[39])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_guild_time(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if((!check_dirty) || dirty[40])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_guild_name(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if((!check_dirty) || dirty[41])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_phy_strength(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if((!check_dirty) || dirty[42])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_extra_phy_strength(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if((!check_dirty) || dirty[43])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_time_to_recover_phy_strength(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if((!check_dirty) || dirty[44])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_time_to_recover_extra_phy_strength(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if((!check_dirty) || dirty[45])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_renown(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    return origin_size - size ; 
} 
int role_info::sql_query(char* buf,int size) const
{
    int origin_size = size ,len=0; 
    len = snprintf(buf,size,"select * from role_info where ");
    buf += len ; size -= len ;
    len = sql_key(buf,size) ;
    buf += len ; size -= len ;
    return origin_size - size ; 
} 
int role_info::sql_insert(char* buf,int size) const
{
    int origin_size = size,len=0 ; 
    len = snprintf(buf,size,"insert into role_info set ");
    buf += len ; size -= len ;
    len = sql_data(buf,size,false) ;
    buf += len ; size -= len ;
    return origin_size - size ; 
} 
int role_info::sql_replace(char* buf,int size) const
{
    int origin_size = size,len=0 ; 
    len = snprintf(buf,size,"replace into role_info set ");
    buf += len ; size -= len ;
    len = sql_data(buf,size,false) ;
    buf += len ; size -= len ;
    return origin_size - size ; 
} 
int role_info::sql_update(char* buf,int size) const
{
    int origin_size = size,len=0 ; 
    len = snprintf(buf,size,"update role_info set ");
    buf += len ; size -= len ;
    len = sql_data(buf,size,true) ;
    buf += len ; size -= len ;
    memcpy(buf," where ",7); buf+= 7 ; size-= 7 ;
    len = sql_key(buf,size) ;
    buf += len ; size -= len ;
    return origin_size - size ; 
} 
int role_info::sql_delete(char* buf,int size) const
{
    int origin_size = size ,len=0; 
    len = snprintf(buf,size,"delete from role_info where ");
    buf += len ; size -= len ;
    len = sql_key(buf,size) ;
    buf += len ; size -= len ;
    return origin_size - size ; 
} 
void role_info::load_from_pb(const db_role_info& pb)
{
    role_id = pb.role_id();
    uid = pb.uid();
    tid = pb.tid();
    name = pb.name();
    gender = pb.gender();
    job_type = pb.job_type();
    role_level = pb.role_level();
    role_exp = pb.role_exp();
    costume_tid = pb.costume_tid();
    title = pb.title();
    coin = pb.coin();
    coupon = pb.coupon();
    diamond = pb.diamond();
    vip_end_ts = pb.vip_end_ts();
    vip_level = pb.vip_level();
    map_id = pb.map_id();
    map_x = pb.map_x();
    map_y = pb.map_y();
    last_map_id = pb.last_map_id();
    last_map_x = pb.last_map_x();
    last_map_y = pb.last_map_y();
    flag = pb.flag();
    status = pb.status();
    server_id = pb.server_id();
    create_time = pb.create_time();
    team_id = pb.team_id();
    team_create_time = pb.team_create_time();
    bag_size = pb.bag_size();
    depot_size = pb.depot_size();
    buddy_size = pb.buddy_size();
    lineup_size = pb.lineup_size();
    default_lineup_id = pb.default_lineup_id();
    lineup_capacity = pb.lineup_capacity();
    login_time = pb.login_time();
    last_logoff_time = pb.last_logoff_time();
    login_ip = pb.login_ip();
    instance_count = pb.instance_count();
    instance_time = pb.instance_time();
    guild_id = pb.guild_id();
    guild_time = pb.guild_time();
    guild_name = pb.guild_name();
    phy_strength = pb.phy_strength();
    extra_phy_strength = pb.extra_phy_strength();
    time_to_recover_phy_strength = pb.time_to_recover_phy_strength();
    time_to_recover_extra_phy_strength = pb.time_to_recover_extra_phy_strength();
    renown = pb.renown();
}
void role_info::copy_to_pb(db_role_info& pb)
{
    pb.set_role_id(role_id);
    pb.set_uid(uid);
    pb.set_tid(tid);
    pb.set_name(name);
    pb.set_gender(gender);
    pb.set_job_type(job_type);
    pb.set_role_level(role_level);
    pb.set_role_exp(role_exp);
    pb.set_costume_tid(costume_tid);
    pb.set_title(title);
    pb.set_coin(coin);
    pb.set_coupon(coupon);
    pb.set_diamond(diamond);
    pb.set_vip_end_ts(vip_end_ts);
    pb.set_vip_level(vip_level);
    pb.set_map_id(map_id);
    pb.set_map_x(map_x);
    pb.set_map_y(map_y);
    pb.set_last_map_id(last_map_id);
    pb.set_last_map_x(last_map_x);
    pb.set_last_map_y(last_map_y);
    pb.set_flag(flag);
    pb.set_status(status);
    pb.set_server_id(server_id);
    pb.set_create_time(create_time);
    pb.set_team_id(team_id);
    pb.set_team_create_time(team_create_time);
    pb.set_bag_size(bag_size);
    pb.set_depot_size(depot_size);
    pb.set_buddy_size(buddy_size);
    pb.set_lineup_size(lineup_size);
    pb.set_default_lineup_id(default_lineup_id);
    pb.set_lineup_capacity(lineup_capacity);
    pb.set_login_time(login_time);
    pb.set_last_logoff_time(last_logoff_time);
    pb.set_login_ip(login_ip);
    pb.set_instance_count(instance_count);
    pb.set_instance_time(instance_time);
    pb.set_guild_id(guild_id);
    pb.set_guild_time(guild_time);
    pb.set_guild_name(guild_name);
    pb.set_phy_strength(phy_strength);
    pb.set_extra_phy_strength(extra_phy_strength);
    pb.set_time_to_recover_phy_strength(time_to_recover_phy_strength);
    pb.set_time_to_recover_extra_phy_strength(time_to_recover_extra_phy_strength);
    pb.set_renown(renown);
}
