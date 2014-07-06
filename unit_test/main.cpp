#include <sys/socket.h>
#include <sys/types.h>
#include "stdio.h"
#include "string.h"
#include "string.h"
#include "head.h"
#include "message_define.h"
#include "message.pb.h"
#include "game_packet.h"
#include "packet.h"

void init_server_log(int argc, char** argv){
	google::ParseCommandLineFlags(&argc,&argv,true);		
	google::InitGoogleLogging(argv[0]);
}


typedef cs_packet<CS_MSG_HEART_BEAT_REQ,ClientHeartBeatRequest> cs_client_hb_request;  

int main(int argc,char** argv){
	init_server_log(argc,argv);
	
	int port = 1;
	struct sockaddr_in addr;
	socklen_t len;
	
	memset(&addr,0,sizeof(addr));
	addr.sin_family =	AF_INET;
	addr.sin_port = htons(9999);	
	inet_pton(AF_INET,"127.0.0.1",&addr.sin_addr);
	int fd = socket(AF_INET,SOCK_STREAM,0);

	int flag = fcntl(fd, F_GETFL);
	flag |= O_NONBLOCK;
	fcntl(fd, F_SETFL, flag);
	VLOG(1)<<"ssss";
	if(fd != -1){
		int rest = connect(fd,(struct sockaddr*)&addr,sizeof(addr));
		printf("%d",rest);
		bool is_login = false;
		while(1){
            cs_client_hb_request request;
            request.body.set_client_time(11111);
            char buffer[8*1024];
            int size = request.encode(buffer,8*1024);
            send(fd,(const char*)buffer,size,0);
            usleep(5000000);
/*
            cs_head head;
            head.length = 0;
            head.msg_id = 1;
			if(is_login == false){
				send(fd,(const char*)&msg_login,msg_login.msg_size-4,0);
				is_login = true;
			}
            */
/*
			struct MsgAlive msg_live;
			int msg_len = sizeof(MsgAlive);
			char* buff = (char*)malloc(msg_len);
			int i=0;
			msg_live.live_time = 12345.1112;
			char* time="1986.09.20";
			char* name="管磊";
			strncpy(msg_live.str_time,time,10);
			strncpy(msg_live.str_name,name,10);
			memcpy(buff,&msg_live,msg_len);
			VLOG(1)<<"SEND MSG...";
		//snprintf(buff,sizeof(buff),"send message%d",i);
			int len = send(fd,buff,msg_len,0);
			VLOG(1)<<"SEND MSG";
			char buffer[1024];
			usleep(1000*500);
			recv(fd,buffer,1024,0);
			VLOG(1)<<"Server time is "<<((MsgAlive*)buffer)->live_time;
            */
		}
	}else{
		VLOG(1)<<"error connect";
	}
	pthread_exit(NULL);	
	return 1;
}
