/*
 * net_util.h
 *
 *  Created on: 2014年1月20日
 *      Author: guanlei
 */

#ifndef NET_UTIL_H_
#define NET_UTIL_H_

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
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
#include <stdint.h>
#include <stdarg.h>
#include <sys/param.h>
#include <sys/stat.h>

//格式化socket地址
int init_sa_in(sockaddr_in* addr_in, const char* ip_str, int port) ;

//设置socket block or not
int set_sock_noblock(int fd,bool blocking) ;

//设置socket是否延迟发送
int set_nodelay(int fd, bool nodelay) ;

//设置地址可重用
int set_reuseaddr(int fd, bool reuse) ;

//绑定且开始监听
int start_tcp_service(sockaddr_in* addr);

#endif /* NET_UTIL_H_ */
