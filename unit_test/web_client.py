#!/bin/env python

import sys,os
import re,json
import eventlet
from eventlet.green import urllib2
import cookielib , urllib
import struct,string

from message import *
import client_config



def daemon():
    pid = os.fork()
    if pid >0:
        sys.exit(0)
    os.umask(0)
    os.setsid()
    pid = os.fork()
    if pid >0:
        sys.exit(0)


def sig_handler(signum,frame):
    pass

server_header_fmt = "!HHHHi"
server_header_size = struct.calcsize(server_header_fmt) 
notify_header_size = 4   

class XYWebClient :
    def __init__(self):
        self.seq = 1
        self.reserved = 0 
        self.now = 0
        self.ckjar = cookielib.CookieJar()
        self.ckproc = urllib2.HTTPCookieProcessor(self.ckjar)

    def get_platform_cookie(self,login_url,username,password):
        login_data = [("username",username),("password",password),("login_path","index")] 
        post_data = urllib.urlencode(login_data)
        login_req = urllib2.Request(login_url, post_data)
        login_req.add_header("User-Agent","Mozilla/4.0 (compatible; MSIE 6.0; Windows NT 5.1)")

        ckjar = cookielib.CookieJar()
        ckproc = urllib2.HTTPCookieProcessor(ckjar)
        opener = urllib2.build_opener(ckproc)
        login_result = opener.open(login_req,timeout=10)
        if login_result.getcode() != 200 :
            return False
        opener.close()

        return ckjar
       

    def get_inner_game_url(self,platform_game_url,ckjar):
        game_req = urllib2.Request(platform_game_url)
        ckproc = urllib2.HTTPCookieProcessor(ckjar)
        opener = urllib2.build_opener(ckproc)
        game_result = opener.open(game_req,timeout=10)
        if game_result.getcode() != 200 :
            return False
        game_data = game_result.read()
        opener.close()

        game_url_data = re.search('<iframe src="(http\://b2\.sheng\.xy\.com/.*?)"',game_data)
        if not game_url_data :
            return False
        
        return game_url_data.group(1)

    def get_game_server(self,game_url):
        urlfile = urllib2.urlopen(game_url,timeout=10)
        if urlfile.getcode() != 200 :
            return False

        pattern="var[ \t]*serverObj[ \t]*=[ \t\n]*(\{.*?\});"
        server_data = re.search(pattern,urlfile.read())
        if not server_data :
            return False

        server_info = json.loads(server_data.group(1),"latin-1")
        return server_info

    def do_play_game(self,server_info):
        self.uid = int(server_info["uid"])
        self.token = str(server_info["token"])
        self.sid = int(server_info["sid"])
        self.t = int(server_info["t"])
        print "enter game:%s" % self.uid
        self.socket = eventlet.connect( (server_info["ip"],int(server_info["port"]) )  )
        #self.socket = eventlet.connect( ("192.169.1.2",9999) )
        if not socket :
            print " uid:%s connect to server failed" % server_info["uid"]
            return
        
       
        self.send_packet(CSMSG_INIT_CONNECTION_REQ,InitConnectionRequest() )
        
        self.socket.settimeout(2)
        self.now = time.time()
        recv_data = ""
        while True:
            
            try:    
                recv_data += self.socket.recv(1024)
            except (socket.timeout):
                pass
            
            if time.time() - self.now >= 60 :
                self.on_timeout()   
                self.now = time.time()
            
            while len(recv_data) >= server_header_size :
                header_data = recv_data[:server_header_size]
                header = struct.unpack(server_header_fmt,header_data)
                msg_size= header[0]
                msg_id = header[1]
                print "process msgsize:%d" % msg_size
                if len(recv_data) < msg_size :
                    break 
                if msg_id & 0x3 == 2:
                    body_data = recv_data[notify_header_size:msg_size]
                else:
                    body_data = recv_data[server_header_size:msg_size]
                recv_data = recv_data[msg_size:]

                
                self.on_message(msg_id,body_data)

    def on_timeout(self):
        print "%d timeout uid:%d" % (time.time(),self.uid)
        self.send_packet(CSMSG_HEARTBEAT_REQ,HeartBeatRequest())
        
    def acc_login_response(self,body):
        print "recv acc_login response"
        if len(body.roles) == 0 :
            self.send_packet(CSMSG_CREATE_PLAYER_REQ,CreatePlayerRequest(gender=MALE,job=ARCHER,name=body.random_name) )
        else:
            self.send_packet(CSMSG_PLAYER_LOGIN_REQ,PlayerLoginRequest(guid=body.roles[0].guid ) )

    def player_login_response(self,body):
        self.send_packet(CSMSG_ENTER_MAP_REQ,EnterMapRequest() )
    def enter_map_response(self,body):
        pass
    def create_player_response(self,body):
        self.send_packet(CSMSG_PLAYER_LOGIN_REQ,PlayerLoginRequest(guid=body.player.guid ) )
    def init_connection_response(self,body):
         self.seq = body.begin_seq +1
         self.reserved = (body.server_time/1000) & 0xffff    
         print "recv init response begin_seq:%d heart:%d"%(self.seq,self.reserved)
         self.send_packet(CSMSG_ACC_LOGIN_REQ,AccountLoginRequest(server_id=self.sid,token=self.token,uid= self.uid,t=self.t ) )      

    def heartbeat_response(self,body):
         self.reserved = (body.server_time/1000) & 0xffff           
         
    def on_message(self,msg_id,body_data):
    
        if not response_factory.has_key(msg_id):
            return
            
       
        print "parse message action:%d" % (msg_id >> 2)
            
        body = response_factory[msg_id]
        body.ParseFromString(body_data)
       
        if msg_id == CSMSG_ACC_LOGIN_REP :
            self.acc_login_response(body)
        elif msg_id == CSMSG_PLAYER_LOGIN_REP:
            self.player_login_response(body)
        elif msg_id == CSMSG_CREATE_PLAYER_REP:  
            self.create_player_response(body)
        elif msg_id == CSMSG_ENTER_MAP_REP:
            self.enter_map_response(body)
        elif msg_id == CSMSG_INIT_CONNECTION_REP:
            self.init_connection_response(body)
        elif msg_id == CSMSG_HEARTBEAT_REP:
            self.heartbeat_response(body)
            
    def send_packet(self,msgid,message):
        self.seq += 1
        body_data = message.SerializeToString()
        head = struct.pack(server_header_fmt,len(body_data) +server_header_size,msgid,0,self.reserved,self.seq)
        print "seq:%d heart:%d"%(self.seq,self.reserved)
        self.socket.send(head)
        self.socket.send(body_data)
            
    def run(self,account):
        cookie = self.get_platform_cookie("http://xy.com/account/login",account[0],account[1])
        game_url = self.get_inner_game_url("http://s2.sheng.xy.com/",cookie)    
        server_info = self.get_game_server(game_url)
        self.do_play_game(server_info)
        

def get_url_data(url,pattern,timeout) :
    urlfile = urllib2.urlopen(url,"",timeout)
    if urlfile.getcode() == 200 :
        data = urlfile.read()
        obj_data = re.search(pattern,data)
        return obj_data

    return False

def do_login(account):
    logindata = [ ("username",account[0]),("password",account[1]),("login_path","index") ] 
    postdata = urllib.urlencode(logindata)
    login_req = urllib2.Request("http://xy.com/account/login", postdata)
    login_req.add_header("User-Agent","Mozilla/4.0 (compatible; MSIE 6.0; Windows NT 5.1)")

    ckjar = cookielib.CookieJar()
    ckproc = urllib2.HTTPCookieProcessor(ckjar)
    opener = urllib2.build_opener(ckproc)
    login_result = opener.open(login_req)
    if login_result.getcode() != 200 :
        print "login failed"
        return False
    opener.close()

    game_req = urllib2.Request("http://s2.sheng.xy.com")
    game_result = opener.open(game_req)
    if game_result.getcode() != 200 :
        print "enter game failed"
        return False
    game_data = game_result.read()
    game_url_data = re.search('<iframe src="(http\://b2\.sheng\.xy\.com/.*?)"',game_data)
    if not game_url_data :
        return False

    pattern="var[ \t]*serverObj[ \t]*=[ \t\n]*(\{.*?\});"
    game_url = game_url_data.group(1)
    server_data = get_url_data(game_url,pattern,10)
    if server_data :
        server_info = json.loads(server_data.group(1))
        print server_info["uid"]
    


class Application :
    def __init__(self):
        self.pool = eventlet.GreenPool(len(client_config.account_list) )
        pass

    def start(self) :
        for account in client_config.account_list :
            print "login (%s ,%s)" % account
            client = XYWebClient()
            self.pool.spawn_n(client.run,account)

        timeout = eventlet.Timeout(client_config.run_duration,None)
        try:
            self.pool.waitall()
        except (eventlet.Timeout):
            print "system stop"


if __name__ == "__main__" :
    try:
        app = Application()
        app.start()
    except (SystemExit,KeyboardInterrupt):
        pass

