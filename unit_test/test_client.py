import  eventlet
#import  urllib2
from eventlet.green import urllib2

account_list = [('guanlei','nicebody'),('guanxing','goodjob')]

class TestClient:
    client_name = ''
    client_index = 0
    def __init__(self,name):
        print "init TestClien"
        self.client_name = name
    def run(self):
        while True:
             self.client_index = self.client_index+1
             print self.client_name ,self.client_index
             eventlet.greenthread.sleep(1)



class TestAppliaction:
    client_pool = 0 
    def __init__(self):
        print " start appliactino"
        self.client_pool = eventlet.GreenPool(10)

    def Start(self,account_list):
        for client in account_list:
            print client[0]
            client_ = TestClient(client[0])
            self.client_pool.spawn_n(client_.run())
        #eventlet.Timeout(300,None)
        self.client_pool.waitall()


appliaction = TestAppliaction()
appliaction.Start(account_list)
