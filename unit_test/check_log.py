import pycurl
import StringIO
import urllib
import hashlib
import math
import time 
import datetime
import global_define

#phone_list="18721637456"
#phone_list="15800972778,18621883577"

class log:
    logfile='log_name'

    def __init__(self,name):
        logfile = name
        print 'init log'

    def __del__(self):
        print 'del log'

    def log_info(self,message):
        print message

log1 = log('nice')
log1.log_info("nice body")
global_define.log_array.append(log1)
print len(global_define.log_array)
        

def send_message(msg_content):
    phone_list="18721637456"
    c = pycurl.Curl()
    c.setopt(c.POST,1)
    sign_key = "phone="+phone_list+"&sms="+msg_content+"&key=2dfa32sdmkf43tdscv"
    md5_key = hashlib.md5(sign_key).hexdigest()
    #post_data=[{"phone":"18721637456"},{"sms":"123"},{"sign":""}]
    sign_key = sign_key+"&sign="+md5_key
    print sign_key
    c.setopt(c.URL,'http://t.statics.hiigame.com/wp/send/sms')
    c.setopt(c.POSTFIELDS,sign_key)
    #c.perform()
    #response_code =  c.getinfo(pycurl.RESPONSE_CODE)
    #c.close()

today = datetime.date.today()
today_str ="robot_log_"+today.strftime("%Y%m%d")+".log";

#file_name = 
file = open("/home/gl/"+today_str)
for line in file:
    if(line.find("no match table") != -1):
        print line,
        words = line.split()
        message = words[0]+""+words[2]
        if(int(words[0]) > int(time.time()) - 3000):
            send_message(message)


