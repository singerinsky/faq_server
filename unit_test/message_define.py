import struct
cs_head_format = "!HH"
cs_head_len = struct.calcsize(cs_head_format) 


def pack_head_message(msg_id,body_data):
    global cs_head_format
    global cs_head_len
    msg_len = cs_head_len + len(body_data)
    head_packet = struct.pack(cs_head_format,msg_id,msg_len)
    return head_packet
