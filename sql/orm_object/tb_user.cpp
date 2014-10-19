#include "tb_user.h" 

tb_user::tb_user()
{
    id = 0;
    level = 0;
    map_id = 0;
    pos_x = 0;
    pos_y = 0;
    memset(dirty,1,sizeof(dirty));
}
void tb_user::load(mysqlpp::Row& row)
{
    id = (int32_t)atoi(row["id"]);
    user_name.assign(row["user_name"]);
    level = (int32_t)atoi(row["level"]);
    map_id = (int32_t)atoi(row["map_id"]);
    pos_x = (int32_t)atoi(row["pos_x"]);
    pos_y = (int32_t)atoi(row["pos_y"]);
    memset(dirty,0,sizeof(dirty));
}
int tb_user::sql_key(char* buf,int size) const
{
    int origin_size = size ,len = 0; 
    len =sql_id(buf,size);
    buf += len ; size -= len ;
    return origin_size - size ; 
} 
int tb_user::sql_data(char* buf,int size,bool check_dirty) const
{
    int origin_size = size,len=0 ; 
    int first_flag = 1 ; 
    if((!check_dirty) || dirty[0])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_id(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if((!check_dirty) || dirty[1])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_user_name(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if((!check_dirty) || dirty[2])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_level(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if((!check_dirty) || dirty[3])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_map_id(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if((!check_dirty) || dirty[4])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_pos_x(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    if((!check_dirty) || dirty[5])
    {
        if(first_flag==0) {memcpy(buf,",",1); buf+= 1 ; size-= 1 ;}
        len =sql_pos_y(buf,size);
        buf += len ; size -= len ;first_flag=0;
    }
    return origin_size - size ; 
} 
int tb_user::sql_query(char* buf,int size) const
{
    int origin_size = size ,len=0; 
    len = snprintf(buf,size,"select * from tb_user where ");
    buf += len ; size -= len ;
    len = sql_key(buf,size) ;
    buf += len ; size -= len ;
    return origin_size - size ; 
} 
int tb_user::sql_insert(char* buf,int size) const
{
    int origin_size = size,len=0 ; 
    len = snprintf(buf,size,"insert into tb_user set ");
    buf += len ; size -= len ;
    len = sql_data(buf,size,false) ;
    buf += len ; size -= len ;
    return origin_size - size ; 
} 
int tb_user::sql_replace(char* buf,int size) const
{
    int origin_size = size,len=0 ; 
    len = snprintf(buf,size,"replace into tb_user set ");
    buf += len ; size -= len ;
    len = sql_data(buf,size,false) ;
    buf += len ; size -= len ;
    return origin_size - size ; 
} 
int tb_user::sql_update(char* buf,int size) const
{
    int origin_size = size,len=0 ; 
    len = snprintf(buf,size,"update tb_user set ");
    buf += len ; size -= len ;
    len = sql_data(buf,size,true) ;
    buf += len ; size -= len ;
    memcpy(buf," where ",7); buf+= 7 ; size-= 7 ;
    len = sql_key(buf,size) ;
    buf += len ; size -= len ;
    return origin_size - size ; 
} 
int tb_user::sql_delete(char* buf,int size) const
{
    int origin_size = size ,len=0; 
    len = snprintf(buf,size,"delete from tb_user where ");
    buf += len ; size -= len ;
    len = sql_key(buf,size) ;
    buf += len ; size -= len ;
    return origin_size - size ; 
} 
void tb_user::load_from_pb(const db_tb_user& pb)
{
    id = pb.id();
    user_name = pb.user_name();
    level = pb.level();
    map_id = pb.map_id();
    pos_x = pb.pos_x();
    pos_y = pb.pos_y();
}
void tb_user::copy_to_pb(db_tb_user& pb)
{
    pb.set_id(id);
    pb.set_user_name(user_name);
    pb.set_level(level);
    pb.set_map_id(map_id);
    pb.set_pos_x(pos_x);
    pb.set_pos_y(pos_y);
}
