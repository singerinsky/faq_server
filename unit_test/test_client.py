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
    return head_packet

class CClient:
    def __init__(self,name):
        print "init TestClien"
        self.client_name = name
    def run(self):
        global g_server_ip
        global g_server_port
        global cs_head_len
        try:
            self.client_socket = eventlet.connect((g_server_ip,g_server_port))
        except (IOError, OSError):
            print "connect to ",g_server_ip,g_server_port,"error"
            return
        self.client_socket.settimeout(0.1)
        self.do_login()
        recv_data = ""
        self.alive_time = time.time()
        print "run client",self.alive_time
        while True:
            try:
                recv_data += self.client_socket.recv(1024)
            except (socket.timeout):
                self.action_game()
                pass

            while len(recv_data) >= cs_head_len:
                head_data = recv_data[:cs_head_len]
                head_packet = struct.unpack(cs_head_format,head_data)
                msg_id = head_packet[1]
                msg_len = head_packet[0]
                if msg_len > len(recv_data):
                    break
                print head_packet
                body_data = recv_data[cs_head_len:msg_len] 
                self.process_msg(msg_id,body_data)
                recv_data = recv_data[msg_len:]

    def do_init_client(self,message):
        print "init client from message name %s id %d"%(message.user_info.user_name,message.user_info.user_id)
        self.user_info = message.user_info

    def process_msg(self,msg_id,msg_content):
        print "process msg code",msg_id>>2
        if msg_id == CSMSG_CLIENT_LOGIN_ACK:
            message = response_factory[msg_id]
            message.ParseFromString(msg_content)
            print "login message",message.ret
        if msg_id == CSMSG_INIT_PLAYER_NOTF:
            message = response_factory[msg_id]
            message.ParseFromString(msg_content)
            self.do_init_client(message)


    def do_login(self):
        message_body = ClientLoginRequest();  
        message_body.role_id = 1
        message_body.token = "nicebody"
        body_data = message_body.SerializeToString()
        head_packet = pack_head_message(CSMSG_CLIENT_LOGIN_REQ,body_data)
        self.client_socket.send(head_packet)
        self.client_socket.send(body_data)
        print "send login msg"

    def action_game(self):
        if self.alive_time < time.time() - 1:
            request = ClientHeartBeatRequest()
            request.client_time = int(time.time())
            body_data = request.SerializeToString()
            head_data = pack_head_message(CSMSG_HEART_REQ,body_data)
            self.client_socket.send(head_data)
            self.client_socket.send(body_data)
            self.alive_time = time.time()

        rand_value = random.randint(0,99);
        if rand_value <= 10:
            self.do_move()

    def do_move(self):
        move_x = random.randint(0,10);
        move_y = random.randint(0,10);
        message_body = ClientMoveRequest();
        message_body.pos_x = move_x;
        message_body.pos_y = move_y;
        message_body.map_id = 1;
        body_data = message_body.SerializeToString();
        head_packet = pack_head_message(CSMSG_CLIENT_MOVE_REP,body_data)
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

