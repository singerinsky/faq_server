#ifndef _generate_h_tb_user 
#define _generate_h_tb_user 
#include <mysql++/mysql++.h>
#include "../message/tb_user.pb.h"
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
    int32_t get_id() const { return id;} ; 
    void set_id(int32_t value) { if(id!= value){dirty[0] = 1; id = value;} } ; 
    int sql_id(char* buf,int size) const{return snprintf(buf,size,"id='%lld'",(int64_t)id);}

    const string& get_user_name() const { return user_name;} ; 
    void set_user_name(const string& value) { if(user_name!= value){dirty[1] = 1; user_name.assign(value);} }; 
    void set_user_name(const char* value) { if(strcmp(user_name.c_str(),value)!=0) {dirty[1] = 1; user_name.assign(value);} }; 
    int sql_user_name(char* buf,int size) const{return snprintf(buf,size,"user_name='%s'",user_name.c_str());}

    void load_from_pb(const db_tb_user&);
    void copy_to_pb(db_tb_user&);
private:
    //data member
    int32_t id ; 
    string user_name ; 
private:
    //dirty flag for update
    enum { FIELD_COUNT = 2 } ; 
    int8_t dirty[FIELD_COUNT] ; 
};
#endif
