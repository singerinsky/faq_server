import  eventlet
import  struct
import  sys
import  socket
#import  urllib2
from eventlet.green import urllib2
sys.path.append('../message/python/')
from message_pb2 import *


#message define
CSMSG_CLIENT_LOGIN_REQ  = MSG_CLIENT_LOGIN << 2|MSG_REQUEST  
CSMSG_CLIENT_LOGIN_ACK  = MSG_CLIENT_LOGIN << 2|MSG_RESPONSE


cs_head_format = "HH"
cs_head_len = struct.calcsize(cs_head_format) 
#account_list = [('guanlei','nicebody'),('guanxing','goodjob'),('chongchong','goodkid')]
account_list = [('guanlei','nicebody')]
g_server_ip = "127.0.0.1"
g_server_port = 9998
g_client_pool = {}

def pack_head_message(msg_id,body_data):
    global cs_head_format
    global cs_head_len
    msg_len = cs_head_len + len(body_data)
    head_packet = struct.pack(cs_head_format,msg_len,msg_id)
    print "message",msg_id,msg_len
    return head_packet

class TestClient:
    def __init__(self,name):
        print "init TestClien"
        self.client_naome = name
    def run(self):
        global g_server_ip
        global g_server_port
        try:
            self.client_socket = socket.create_connection((g_server_ip,g_server_port),2)
        except (IOError, OSError):
            print "connect to ",g_server_ip,g_server_port,"error"
            return

        message_body = ClientLoginRequest();  
        message_body.role_id = 111
        message_body.token = "nicebody"
        body_data = message_body.SerializeToString()
        head_packet = pack_head_message(CSMSG_CLIENT_LOGIN_REQ,body_data)
        self.client_socket.send(head_packet)
        self.client_socket.send(body_data)
class TestAppliaction:
    def __init__(self):
        print " start appliactino"
        self.client_pool = eventlet.GreenPool(10)

    def Start(self,account_list):
        global g_client_pool
        for client in account_list:
            print client[0]
            client_ = TestClient(client[0])
            self.client_pool.spawn_n(client_.run)
            g_client_pool[client[0]] = client_
        #eventlet.Timeout(300,None)
        self.client_pool.waitall()

if  __name__ == "__main__":
    try:
        appliaction = TestAppliaction()
        appliaction.Start(account_list)
    except (SystemExit,KeyboardInterrupt):
        pass
