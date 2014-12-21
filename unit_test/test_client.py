import  eventlet
import  time
import  struct
import  sys
import  socket
import  random
#import  urllib2
from eventlet.green import urllib2
sys.path.append('../message/python/')
from message_pb2 import *
from message_define import *
from cclient import *

#account_list = [('guanlei','nicebody'),('guanxing','goodjob'),('chongchong','goodkid')]
account_list = [('guanlei','nicebody')]

def pack_head_message(msg_id,body_data):
    global cs_head_format
    global cs_head_len
    msg_len = cs_head_len + len(body_data)
    head_packet = struct.pack(cs_head_format,msg_len,msg_id)
    return head_packet
class TestAppliaction:
    def __init__(self):
        print " start appliactino"
        self.client_pool = eventlet.GreenPool(10)

    def Start(self,account_list):
        global g_client_pool
        for client in account_list:
            print client[0]
            client_ = CClient(client[0])
            self.client_pool.spawn(client_.run)
            #g_client_pool[client[0]] = client_
        #eventlet.Timeout(10,None)
        self.client_pool.waitall()

if  __name__ == "__main__":
    try:
        appliaction = TestAppliaction()
        appliaction.Start(account_list)
    except (SystemExit,KeyboardInterrupt):
        pass

