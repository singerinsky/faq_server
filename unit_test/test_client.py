import  eventlet
import  socket
#import  urllib2
from eventlet.green import urllib2

account_list = [('guanlei','nicebody'),('guanxing','goodjob'),('chongchong','goodkid')]
g_server_ip = "127.0.0.1"
g_server_port = 9998
g_client_pool = {}

class TestClient:
    def __init__(self,name):
        print "init TestClient",name
        self.client_name = name
    def run(self,status):
        global g_server_ip
        global g_server_port
        try:
            self.client_socket_ = socket.create_connection((g_server_ip,g_server_port),2)
        except (IOError, OSError):
            print "connect to ",g_server_ip,g_server_port,"error"
            pass

class TestAppliaction:
    def __init__(self):
        print " start appliactino"
        self.client_pool = eventlet.GreenPool(10)

    def Start(self,account_list):
        global g_client_pool
        for client in account_list:
            print client[0]
            client_ = TestClient(client[0])
            self.client_pool.spawn_n(client_.run,client[0])
            g_client_pool[client[0]] = client_
        #eventlet.Timeout(300,None)
        self.client_pool.waitall()

if  __name__ == "__main__":
    try:
        appliaction = TestAppliaction()
        appliaction.Start(account_list)
    except (SystemExit,KeyboardInterrupt):
        pass
