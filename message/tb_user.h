#ifndef _generate_h_tb_user 
#define _generate_h_tb_user 
#include "tb_user.pb.h"
#include "sql_binder.h"
class tb_user : public sql_binder 
{
public:
    tb_user();
    void clear_dirty(){ memset(dirty,0,sizeof(dirty)); } ;
    bool is_dirty() const
    {
        for(int i=0;i<FIELD_COUNT;++i) {if(dirty[i]) return true;} ;
        return false ;
    } ;
    int sql_insert(char* buf,int size) const;
    int sql_replace(char* buf,int size) const;
    int sql_update(char* buf,int size) const;
    int sql_query(char* buf,int size) const;
    int sql_delete(char* buf,int size) const;
protected:
    int sql_key(char* buf,int size) const;
    int sql_data(char* buf,int size,bool check_dirty=true) const;
public:
    int32_t get_id() const { return id;} ; 
    void set_id(int32_t value) { if(id!= value){dirty[0] = 1; id = value;} } ; 
    int sql_id(char* buf,int size) const{return snprintf(buf,size,"id='%ld'",(int64_t)id);}

    const string& get_user_name() const { return user_name;} ; 
    void set_user_name(const string& value) { if(user_name!= value){dirty[1] = 1; user_name.assign(value);} }; 
    void set_user_name(const char* value) { if(strcmp(user_name.c_str(),value)!=0) {dirty[1] = 1; user_name.assign(value);} }; 
    int sql_user_name(char* buf,int size) const{return snprintf(buf,size,"user_name='%s'",user_name.c_str());}

    int32_t get_level() const { return level;} ; 
    void set_level(int32_t value) { if(level!= value){dirty[2] = 1; level = value;} } ; 
    int sql_level(char* buf,int size) const{return snprintf(buf,size,"level='%ld'",(int64_t)level);}

    int32_t get_map_id() const { return map_id;} ; 
    void set_map_id(int32_t value) { if(map_id!= value){dirty[3] = 1; map_id = value;} } ; 
    int sql_map_id(char* buf,int size) const{return snprintf(buf,size,"map_id='%ld'",(int64_t)map_id);}

    int32_t get_pos_x() const { return pos_x;} ; 
    void set_pos_x(int32_t value) { if(pos_x!= value){dirty[4] = 1; pos_x = value;} } ; 
    int sql_pos_x(char* buf,int size) const{return snprintf(buf,size,"pos_x='%ld'",(int64_t)pos_x);}

    int32_t get_pos_y() const { return pos_y;} ; 
    void set_pos_y(int32_t value) { if(pos_y!= value){dirty[5] = 1; pos_y = value;} } ; 
    int sql_pos_y(char* buf,int size) const{return snprintf(buf,size,"pos_y='%ld'",(int64_t)pos_y);}

    int32_t get_hp() const { return hp;} ; 
    void set_hp(int32_t value) { if(hp!= value){dirty[6] = 1; hp = value;} } ; 
    int sql_hp(char* buf,int size) const{return snprintf(buf,size,"hp='%ld'",(int64_t)hp);}

    int32_t get_mp() const { return mp;} ; 
    void set_mp(int32_t value) { if(mp!= value){dirty[7] = 1; mp = value;} } ; 
    int sql_mp(char* buf,int size) const{return snprintf(buf,size,"mp='%ld'",(int64_t)mp);}

    int32_t get_direct() const { return direct;} ; 
    void set_direct(int32_t value) { if(direct!= value){dirty[8] = 1; direct = value;} } ; 
    int sql_direct(char* buf,int size) const{return snprintf(buf,size,"direct='%ld'",(int64_t)direct);}

    void load_from_pb(const db_tb_user&);
    void copy_to_pb(db_tb_user&);
private:
    //data member
    int32_t id ; 
    string user_name ; 
    int32_t level ; 
    int32_t map_id ; 
    int32_t pos_x ; 
    int32_t pos_y ; 
    int32_t hp ; 
    int32_t mp ; 
    int32_t direct ; 
private:
    //dirty flag for update
    enum { FIELD_COUNT = 9 } ; 
    int8_t dirty[FIELD_COUNT] ; 
};
#endif
