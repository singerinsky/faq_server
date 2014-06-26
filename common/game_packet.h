#ifndef GAME_PACKET_H_
#define GAME_PACKET_H_

#include <sstream>
#include <exception>
#include "packet.h"
#include "aliased_buf.h"
/*
typedef unsigned __int8 uint8_t;
typedef unsigned __int16 uint16_t;
typedef unsigned __int32 uint32_t;
typedef __int32 int32_t;
*/
struct ss_head
{
    uint16_t length ;
    uint16_t msgid ;
    uint32_t key ;
    uint32_t seq ;
	uint32_t tick;
} __attribute__((packed)) ;

struct cs_head
{
    uint16_t length ;
    uint16_t msgid ;
} __attribute__((packed)) ;


union msgid_type
{
    uint16_t value ;
    struct
    {
        uint16_t type:2 ;
        uint16_t action_id:10 ;
        uint16_t module:4 ;

    } __attribute__((packed)) ;
} __attribute__((packed)) ;


inline int cs_head_size(uint16_t msgid)
{
    return (int)sizeof(cs_head) ;
}

template<int32_t PT,typename BT>
class cs_packet : public packet
{
public:
    enum{ packet_type = PT ,} ;
    typedef BT body_type ;
public:


    virtual int get_type() {return packet_type ; } ;

    virtual int encode(char* data,int size)
    {
        if(size < cs_head_size(PT) ) return -1 ;

        aliased_buf sbuf(data +cs_head_size(PT), size - cs_head_size(PT)) ;
        std::ostream output(&sbuf) ;
        try
        {
            if(!body.SerializeToOstream(&output) || output.tellp() < 0 ) return -1 ;
        }
        catch(const std::exception& ex)
        {
            return -1 ;
        }
        
        size = cs_head_size(PT) + output.tellp() ;
        if(size >= 65535 ) return -1 ;
        cs_head* head = (cs_head*)data;
        head->length = ntoh_int16(size);
        head->msgid = ntoh_int16(PT);
        return size ;

    }
    virtual int decode(const char* data,int size)
    {
        if(size < cs_head_size(PT) ) return -1 ;

        cs_head* head = (cs_head*)data ;
        if(ntoh_int16(head->msgid)!= PT) return -1 ;


        size = ntoh_int16(head->length) ;

        aliased_buf sbuf((char*)data +cs_head_size(PT), size - cs_head_size(PT)) ;
        std::istream input(&sbuf) ;
        try
        {
            if(!body.ParseFromIstream(&input) ) return -1 ;
        }
        catch(const std::exception& ex)
        {
            return -1 ;
        }

        return size ;

    }

    virtual int encode_size()
    {
        int need_size = cs_head_size(PT) + body.ByteSize() ;
        if(need_size >= 65535 )  return -1 ;
        return need_size ;
    }

    virtual int decode_size(const char* data,int size)
    {
        cs_head* tmp = (cs_head*)data ;
        return  ntoh_int16(tmp->length) ;

    }

public:
    int16_t code ;
    int16_t reserved ;
    int32_t seq ;
    body_type body ;
};


#endif /* GAME_PACKET_H_ */
