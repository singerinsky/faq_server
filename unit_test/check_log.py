import pycurl
import StringIO
import urllib

file = open("/home/gl/test001")
for line in file:
    print line,

c = pycurl.Curl()
c.setopt(c.POST,1)
post_data={"name":"value"}
c.setopt(c.URL,'http://www.baidu.com')
c.setopt(c.POSTFIELDS,urllib.urlencode(post_data))
c.perform()
response_code =  c.getinfo(pycurl.RESPONSE_CODE)
c.close()
