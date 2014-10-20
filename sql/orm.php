<?php

class orm_generator
{
    var $fields = array() ;
    var $name ;
    var $file_h ;
    var $file_cpp ;
    var $file_proto;

    function __construct()
    {
    }

    function init($tbname,$output_dir)
    {
        $this->name = $tbname ;
        $this->file_h = fopen("${output_dir}/${tbname}.h",'w') ;
        $this->file_cpp = fopen("${output_dir}/${tbname}.cpp",'w') ;
        $this->comm_file_h = fopen("${output_dir}/sql_binder.h",'w') ;
        $this->file_proto = fopen("${output_dir}/${tbname}.proto",'w');

    } 


    function add_field($field_index,$field_name,$field_type,$field_key_flag) 
    {
        $this->fields[] = array($field_index,$field_name,$field_type,$field_key_flag) ;
    }

    function generate_comm_h()
    {
        fwrite($this->comm_file_h,"#ifndef _generate_h_SQL_BINDER \n") ;
        fwrite($this->comm_file_h,"#define _generate_h_SQL_BINDER \n") ;
        fwrite($this->comm_file_h,"#include <stdint.h>\n") ;
        fwrite($this->comm_file_h,"#include <string.h>\n") ;
        fwrite($this->comm_file_h,"#include <stdio.h>\n") ;
        fwrite($this->comm_file_h,"#include <string>\n") ;
        fwrite($this->comm_file_h,"#include <vector>\n") ;
        fwrite($this->comm_file_h,"using std::string;\n") ;
        fwrite($this->comm_file_h,"using std::vector;\n") ;

        fwrite($this->comm_file_h,"class sql_binder \n{\n") ;
        fwrite($this->comm_file_h, "public:\n") ;
        fwrite($this->comm_file_h,"    virtual ~sql_binder() { } ;\n") ;
        fwrite($this->comm_file_h,"    virtual void clear_dirty() =0;\n") ;
        fwrite($this->comm_file_h,"    virtual bool is_dirty() const = 0;\n");
        fwrite($this->comm_file_h,"    virtual int sql_insert(char* buf,int size) const =0;\n") ;
        fwrite($this->comm_file_h,"    virtual int sql_replace(char* buf,int size) const =0;\n") ;
        fwrite($this->comm_file_h,"    virtual int sql_update(char* buf,int size) const =0;\n") ;
        fwrite($this->comm_file_h,"    virtual int sql_query(char* buf,int size) const =0;\n") ;
        fwrite($this->comm_file_h,"    virtual int sql_delete(char* buf,int size) const =0;\n") ;
        fwrite($this->comm_file_h, "protected:\n") ;
        fwrite($this->comm_file_h,"    virtual int sql_key(char* buf,int size) const =0;\n") ;
        fwrite($this->comm_file_h,"    virtual int sql_data(char* buf,int size,bool check_dirty=true) const =0;\n") ;
        fwrite($this->comm_file_h,"};\n") ;

        fwrite($this->comm_file_h,"#endif\n") ;


    }
    
    function generate_h_begin()
    {
        fwrite($this->file_h,"#ifndef _generate_h_$this->name \n") ;
        fwrite($this->file_h,"#define _generate_h_$this->name \n") ;
        fwrite($this->file_h,"#include \"$this->name.pb.h\"\n");
        //fwrite($this->file_h,"#include <stdint.h>\n") ;
        //fwrite($this->file_h,"#include <string>\n") ;
        //fwrite($this->file_h,"#include <vector>\n") ;
        //fwrite($this->file_h,"using std::string;\n") ;
        //fwrite($this->file_h,"using std::vector;\n") ;
        fwrite($this->file_h,"#include \"sql_binder.h\"\n") ;


        fwrite($this->file_h,"class $this->name : public sql_binder \n{\n") ;
        fwrite($this->file_h, "public:\n") ;
        fwrite($this->file_h,"    $this->name();\n") ;
        fwrite($this->file_h,"    void clear_dirty(){ memset(dirty,0,sizeof(dirty)); } ;\n") ;
        fwrite($this->file_h,"    bool is_dirty() const\n    {\n");
        fwrite($this->file_h,"        for(int i=0;i<FIELD_COUNT;++i) {if(dirty[i]) return true;} ;\n") ;
        fwrite($this->file_h,"        return false ;\n    } ;\n") ;
        //fwrite($this->file_h,"    void load(mysqlpp::Row&);\n") ;
        fwrite($this->file_h,"    int sql_insert(char* buf,int size) const;\n") ;
        fwrite($this->file_h,"    int sql_replace(char* buf,int size) const;\n") ;
        fwrite($this->file_h,"    int sql_update(char* buf,int size) const;\n") ;
        fwrite($this->file_h,"    int sql_query(char* buf,int size) const;\n") ;
        fwrite($this->file_h,"    int sql_delete(char* buf,int size) const;\n") ;
        fwrite($this->file_h, "protected:\n") ;
        fwrite($this->file_h,"    int sql_key(char* buf,int size) const;\n") ;
        fwrite($this->file_h,"    int sql_data(char* buf,int size,bool check_dirty=true) const;\n") ;
    }

    function generate_h_end()
    {
        fwrite($this->file_h, "};\n" );
        fwrite($this->file_h, "#endif\n" );
    }

    function generate_cpp_begin()
    {
        fwrite($this->file_cpp, "#include \"$this->name.h\" \n\n" );

    }

    function generate_cpp_end()
    {
    }

    function generate_cpp_construct()
    {

        fwrite($this->file_cpp, "$this->name::$this->name()\n{\n" );
        foreach($this->fields as $k=>$field)
        {   
            
            if($field[2] == "string")
            {
                //fwrite($this->file_cpp, "    ${field[1]}.assign(data[$field[0]]);\n" );
            }
            else
            {
                fwrite($this->file_cpp, "    ${field[1]} = 0;\n" );
            }
        }

        fwrite($this->file_cpp, "    memset(dirty,1,sizeof(dirty));\n" );
        fwrite($this->file_cpp, "}\n" );

    }

    function generate_cpp_load()
    {

        /*fwrite($this->file_cpp, "void $this->name::load(mysqlpp::Row& row)\n{\n" );
        foreach($this->fields as $k=>$field)
        {   
            
            if($field[2] == "string")
            {
                fwrite($this->file_cpp, "    ${field[1]}.assign(row[\"$field[1]\"]);\n" );
            }
            else if (strstr($field[2],"int64") )
            {
                fwrite($this->file_cpp, "    ${field[1]} = (${field[2]})atol(row[\"$field[1]\"]);\n" );
            }
            else
            {
                fwrite($this->file_cpp, "    ${field[1]} = (${field[2]})atoi(row[\"$field[1]\"]);\n" );
            }
        }

        fwrite($this->file_cpp, "    memset(dirty,0,sizeof(dirty));\n" );
        fwrite($this->file_cpp, "}\n" );
        */
    }

    function generate_cpp_key()
    {
        fwrite($this->file_cpp, "int $this->name::sql_key(char* buf,int size) const\n{\n" );
        fwrite($this->file_cpp, "    int origin_size = size ,len = 0; \n" );
        $first_key = true ;
        foreach($this->fields as $k=>$field)
        {   
            
            if($field[3]) 
            {
                if($first_key == false ) 
                {
                    fwrite($this->file_cpp, "    memcpy(buf,\" and \",5); buf+= 5 ; size-= 5 ;\n" );
                }

                fwrite($this->file_cpp, "    len =sql_${field[1]}(buf,size);\n" );
                fwrite($this->file_cpp, "    buf += len ; size -= len ;\n" );
                $first_key = false ;
            }
        }
        fwrite($this->file_cpp, "    return origin_size - size ; \n} \n" );
    
    }

    function generate_cpp_data()
    {
        fwrite($this->file_cpp, "int $this->name::sql_data(char* buf,int size,bool check_dirty) const\n{\n" );
        fwrite($this->file_cpp, "    int origin_size = size,len=0 ; \n" );
        fwrite($this->file_cpp, "    int first_flag = 1 ; \n" );
        $first_key = true ;
        foreach($this->fields as $k=>$field)
        {   
            
            fwrite($this->file_cpp, "    if((!check_dirty) || dirty[${field[0]}])\n    {\n" );
            fwrite($this->file_cpp, "        if(first_flag==0) {memcpy(buf,\",\",1); buf+= 1 ; size-= 1 ;}\n" );
            fwrite($this->file_cpp, "        len =sql_${field[1]}(buf,size);\n" );
            fwrite($this->file_cpp, "        buf += len ; size -= len ;first_flag=0;\n" );
            fwrite($this->file_cpp, "    }\n" );
            $first_key = false ;
        }
        fwrite($this->file_cpp, "    return origin_size - size ; \n} \n" );
    
    }

    function generate_cpp_query()
    {
        fwrite($this->file_cpp, "int $this->name::sql_query(char* buf,int size) const\n{\n" );
        fwrite($this->file_cpp, "    int origin_size = size ,len=0; \n" );
        fwrite($this->file_cpp, "    len = snprintf(buf,size,\"select * from $this->name where \");\n" );
        fwrite($this->file_cpp, "    buf += len ; size -= len ;\n" );

        fwrite($this->file_cpp, "    len = sql_key(buf,size) ;\n" );
        fwrite($this->file_cpp, "    buf += len ; size -= len ;\n" );

        fwrite($this->file_cpp, "    return origin_size - size ; \n} \n" );
    
    }


    function generate_cpp_delete()
    {
        fwrite($this->file_cpp, "int $this->name::sql_delete(char* buf,int size) const\n{\n" );
        fwrite($this->file_cpp, "    int origin_size = size ,len=0; \n" );
        fwrite($this->file_cpp, "    len = snprintf(buf,size,\"delete from $this->name where \");\n" );
        fwrite($this->file_cpp, "    buf += len ; size -= len ;\n" );

        fwrite($this->file_cpp, "    len = sql_key(buf,size) ;\n" );
        fwrite($this->file_cpp, "    buf += len ; size -= len ;\n" );

        fwrite($this->file_cpp, "    return origin_size - size ; \n} \n" );
    
    }

   function generate_cpp_update()
    {
        fwrite($this->file_cpp, "int $this->name::sql_update(char* buf,int size) const\n{\n" );
        fwrite($this->file_cpp, "    int origin_size = size,len=0 ; \n" );
        fwrite($this->file_cpp, "    len = snprintf(buf,size,\"update $this->name set \");\n" );
        fwrite($this->file_cpp, "    buf += len ; size -= len ;\n" );

        fwrite($this->file_cpp, "    len = sql_data(buf,size,true) ;\n" );
        fwrite($this->file_cpp, "    buf += len ; size -= len ;\n" );

        fwrite($this->file_cpp, "    memcpy(buf,\" where \",7); buf+= 7 ; size-= 7 ;\n" );
        fwrite($this->file_cpp, "    len = sql_key(buf,size) ;\n" );
        fwrite($this->file_cpp, "    buf += len ; size -= len ;\n" );
        fwrite($this->file_cpp, "    return origin_size - size ; \n} \n" );
    
    }


    function generate_cpp_insert()
    {
        fwrite($this->file_cpp, "int $this->name::sql_insert(char* buf,int size) const\n{\n" );
        fwrite($this->file_cpp, "    int origin_size = size,len=0 ; \n" );
        fwrite($this->file_cpp, "    len = snprintf(buf,size,\"insert into $this->name set \");\n" );
        fwrite($this->file_cpp, "    buf += len ; size -= len ;\n" );

        fwrite($this->file_cpp, "    len = sql_data(buf,size,false) ;\n" );
        fwrite($this->file_cpp, "    buf += len ; size -= len ;\n" );

        fwrite($this->file_cpp, "    return origin_size - size ; \n} \n" );


    }

    function generate_cpp_replace()
    {
        fwrite($this->file_cpp, "int $this->name::sql_replace(char* buf,int size) const\n{\n" );
        fwrite($this->file_cpp, "    int origin_size = size,len=0 ; \n" );
        fwrite($this->file_cpp, "    len = snprintf(buf,size,\"replace into $this->name set \");\n" );
        fwrite($this->file_cpp, "    buf += len ; size -= len ;\n" );

        fwrite($this->file_cpp, "    len = sql_data(buf,size,false) ;\n" );
        fwrite($this->file_cpp, "    buf += len ; size -= len ;\n" );

        fwrite($this->file_cpp, "    return origin_size - size ; \n} \n" );


    }


    function generate_field($field)
    {
        //fwrite($this->file_h, $field[0] ." ". $field[1]." ". $field[2]." ". $field[3] . "\n"  );
        fwrite($this->file_h, "    $field[2] $field[1] ; \n" );
    }

    function generate_method($field)
    {
        if($field[2] == "string")
        {
            fwrite($this->file_h, "    const $field[2]& get_${field[1]}() const { return $field[1];} ; \n" );
            fwrite($this->file_h, "    void set_${field[1]}(const $field[2]& value) { if($field[1]!= value){dirty[${field[0]}] = 1; $field[1].assign(value);} }; \n" );
            fwrite($this->file_h, "    void set_${field[1]}(const char* value) { if(strcmp($field[1].c_str(),value)!=0) {dirty[${field[0]}] = 1; $field[1].assign(value);} }; \n" );
            fwrite($this->file_h, "    int sql_${field[1]}(char* buf,int size) const{return snprintf(buf,size,\"${field[1]}='%s'\",${field[1]}.c_str());}\n\n" );
        }
        else
        {
            fwrite($this->file_h, "    $field[2] get_${field[1]}() const { return $field[1];} ; \n" );
            fwrite($this->file_h, "    void set_${field[1]}($field[2] value) { if($field[1]!= value){dirty[${field[0]}] = 1; $field[1] = value;} } ; \n" );
            fwrite($this->file_h, "    int sql_${field[1]}(char* buf,int size) const{return snprintf(buf,size,\"${field[1]}='%lld'\",(int64_t)${field[1]});}\n\n" );
        }
    }

    function generate_proto()
    {
        fwrite($this->file_proto,"message db_$this->name \n");
        fwrite($this->file_proto,"{\n");
        $start = 1;
        foreach($this->fields as $k=>$v)
        {
            if($v[2] == "string") 
            {
                fwrite($this->file_proto,"required string $v[1] = $start;\n"); 
            }else if($v[2] == "int64_t")
            {
                fwrite($this->file_proto,"required int64 $v[1] = $start;\n");    
            }
            else
            {
                fwrite($this->file_proto,"required int32 $v[1] = $start;\n"); 
            }
            $start++;
        }
        fwrite($this->file_proto,"}\n");
    
    }

    function generate_load_from_pb()
    {
        fwrite($this->file_cpp, "void $this->name::load_from_pb(const db_$this->name& pb)\n"); 
        fwrite($this->file_cpp,"{\n");
        foreach($this->fields as $k=>$v)
        {
            fwrite($this->file_cpp,"    $v[1] = pb.$v[1]();\n"); 
        }
        fwrite($this->file_cpp,"}\n");
    }


    function generate_copy_to_pb()
    {
        fwrite($this->file_cpp, "void $this->name::copy_to_pb(db_$this->name& pb)\n"); 
        fwrite($this->file_cpp,"{\n");
        foreach($this->fields as $k=>$v)
        {
            fwrite($this->file_cpp,"    pb.set_$v[1]($v[1]);\n"); 
        }
        fwrite($this->file_cpp,"}\n");
    
    }

    function generate_h()
    {
        $this->generate_h_begin() ;

        fwrite($this->file_h, "public:\n" );
        foreach($this->fields as $k=>$v) $this->generate_method($v) ;
        fwrite($this->file_h, "    void load_from_pb(const db_$this->name&);\n");
        fwrite($this->file_h, "    void copy_to_pb(db_$this->name&);\n");

        fwrite($this->file_h, "private:\n    //data member\n" );
        foreach($this->fields as $k=>$v) $this->generate_field($v) ;

        fwrite($this->file_h, "private:\n    //dirty flag for update\n" );
        $field_count = count($this->fields) ;
        fwrite($this->file_h, "    enum { FIELD_COUNT = $field_count } ; \n" );
        fwrite($this->file_h, "    int8_t dirty[FIELD_COUNT] ; \n" );

        $this->generate_h_end() ;
    }

    function generate_cpp()
    {
        $this->generate_cpp_begin() ;
        $this->generate_cpp_construct() ;
        $this->generate_cpp_load() ;
        $this->generate_cpp_key() ;
        $this->generate_cpp_data() ;
        $this->generate_cpp_query() ;
        $this->generate_cpp_insert() ;
        $this->generate_cpp_replace() ;
        $this->generate_cpp_update() ;
        $this->generate_cpp_delete() ;
        $this->generate_load_from_pb() ;
        $this->generate_copy_to_pb() ;
        $this->generate_cpp_end() ;
    }

    function generate()
    {
        $this->generate_comm_h() ;
        $this->generate_h() ;
        $this->generate_cpp() ;
        $this->generate_proto();
    }

} 

if($argc < 7 ) die("usage $argv[0] host username password dbname tbname output_dir\n") ;

$host= $argv[1] ;
$username = $argv[2] ;
$password = $argv[3] ;
$dbname = $argv[4] ;
$tbname = $argv[5] ;
$output_dir=$argv[6] ;

$mysql = mysql_connect($host,$username,$password) ;
if(!$mysql) die("connect to mysql failed") ;

$resultset = mysql_query("show fields  from $dbname.$tbname ;",$mysql) ;
if(!$resultset) die("query table $dbname.$tbname failed\n");

//$field_data = mysql_list_fields($dbname,$tbname,$mysql) ;
//$field_count = mysql_num_fields($field_data) ;

$generator = new orm_generator() ;

//for($i = 0 ; $i < $field_count ; ++$i)
$i=0 ;
while($row=mysql_fetch_array($resultset))
{
    
    //var_dump(mysql_field_type($field_data,$i)) ;
    //$field = mysql_fetch_field($resultset,$i) ;
    //$generator->add_field($i,$field->name,$field->type,$field->primary_key) ;   
    if(strpos($row["Type"],"tinyint")===0) $row["Type"] = "int8_t" ;
    else if(strpos($row["Type"],"smallint")===0) $row["Type"] = "int16_t" ;
    else if(strpos($row["Type"],"int")===0) $row["Type"] = "int32_t" ;
    else if(strpos($row["Type"],"timestamp")===0) $row["Type"] = "int32_t" ;
    else if(strpos($row["Type"],"bigint")===0) $row["Type"] = "int64_t" ;
    else if(strpos($row["Type"],"char")===0) $row["Type"] = "string" ;
    else if(strpos($row["Type"],"varchar")===0) $row["Type"] = "string" ;
    else if(strpos($row["Type"],"text")===0) $row["Type"] = "string" ;
    else if(strpos($row["Type"],"datetime")===0) $row["Type"] = "string" ;

    if(strstr($row["Type"],"unsigned") ) $row["Type"] = "unsigned " . $row["Type"] ;

    $generator->add_field($i++,$row["Field"],$row["Type"],$row["Key"] == "PRI") ;
}
$generator->init($tbname,$output_dir) ;
$generator->generate() ;

?>
