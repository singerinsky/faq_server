/*
 * net_util.cpp
 *
 *  Created on: 2014年1月20日
 *      Author: guanlei
 */
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
#include<sys/stat.h>
#include "net_util.h"

//格式化socket地址
int init_sa_in(sockaddr_in* addr_in, const char* ip_str, int port) {
	if (addr_in == NULL || ip_str == NULL || port < 1)
    {
        return -1;
    }
	memset(addr_in, 0, sizeof(sockaddr_in));
	addr_in->sin_family = AF_INET;
	addr_in->sin_port = htons(port);
	addr_in->sin_addr.s_addr = inet_addr(ip_str);
    return 0;
}

//设置socket block or not
int set_sock_noblock(int fd,bool blocking) {

	int flag = fcntl(fd, F_GETFL);
	if (flag == -1) {
		return -1;
	}

	if (blocking) {
		flag &= (~O_NONBLOCK);
	} else {
		flag |= O_NONBLOCK;
	}

	int rv = fcntl(fd, F_SETFL, flag);

	return rv;
}

//设置socket是否延迟发送
int set_nodelay(int fd, bool nodelay) {

	int flag;
	if (nodelay) {
		flag = 1;
	} else {
		flag = 0;
	}

	int rv = setsockopt(fd, IPPROTO_TCP, TCP_NODELAY, &flag, sizeof(flag));

	return rv;
}

//设置地址可重用
int set_reuseaddr(int fd, bool reuse) {
	int flag;

	if (reuse) {
		flag = 1;
	} else {
		flag = 0;
	}

	int rv = setsockopt(fd, SOL_SOCKET, SO_REUSEADDR, &flag, sizeof(flag));

	return rv;
}

//绑定且开始监听
int start_tcp_service(sockaddr_in* addr)
{
	if(addr == NULL)return -1;
	int sockfd = socket(AF_INET,SOCK_STREAM,0);
	if(sockfd < 0 )return -1;
	set_sock_noblock(sockfd,false);
	set_reuseaddr(sockfd,true);
	if(bind(sockfd,(sockaddr*)addr,sizeof(sockaddr))!=0)
	{
		close(sockfd);
		return -2;
	}
	if(listen(sockfd,1024)!=0)
	{
		close(sockfd);
		return -3;
	}
	return sockfd;
}



