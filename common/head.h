#ifndef _HEAD_H_
#define _HEAD_H_
//libc
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
//os
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/wait.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <sys/epoll.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <assert.h>
#include <sys/ioctl.h>     
#include <netdb.h> 
#include <netinet/tcp.h>
#include <sys/prctl.h>
#include <cstddef>
#include <cstdlib>
#include <stdint.h>
#include <stdarg.h>
#include <sys/param.h>
#include<sys/stat.h>
//libc++
#include <string>
#include <vector>
#include <map>
#include <list>
//third part
#include <glog/logging.h>
#include "../include/tinyxml.h"
#include "../include/tinystr.h"
#include <event2/bufferevent.h>
#include <event2/buffer.h>
#include <event2/listener.h>
#include <event2/util.h>
#include <event2/event-config.h>
#include <event2/event.h>
#include "singleton.h"
#include "tinyxml.h"
using namespace std;
//local

#endif
