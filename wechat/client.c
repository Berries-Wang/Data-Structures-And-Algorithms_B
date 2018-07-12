#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <pthread.h>

char mess[1024];
int len;
int clientfile;

void * get1(void* arg);
void * sendcli  (void* arg);

int main(int argc,char *argv[])
{

	if(argc < 2)
	{

		printf("抱歉，用户名为空，正确打开方式： ./client XXX\n");
		exit(1);

	}



	struct sockaddr_in   serveraddr;
	int res = -1;

	char ip[] = "127.0.0.1";
	int  port = 9090;

	pthread_t pid1,pid2;

	bzero(&serveraddr,sizeof(serveraddr));
	serveraddr.sin_family = AF_INET;
	inet_pton(AF_INET,ip,&serveraddr.sin_addr.s_addr);
	serveraddr.sin_port = htons(port);

	clientfile = socket(AF_INET,SOCK_STREAM,0);
tryagin:
	res = connect(clientfile,(struct sockaddr*)&serveraddr,sizeof(serveraddr));

	if(res == -1)
	{
		goto tryagin;

	}


	int ii = pthread_create(&pid1,NULL,get1,NULL);
	int jj = pthread_create(&pid2,NULL,sendcli,argv[1]);
	if(ii==0&&jj==0)
	{

		printf("%s\n","开始聊天");

	}
	pthread_detach(pid1);
	pthread_detach(pid2);

	while(1);

	close(clientfile);

	return 0;
}



void * get1(void* arg)
{

	while(1)
	{

		len = read(clientfile,mess,sizeof(mess));//从服务器接受数据
		printf("%s\n",mess);

	}

}

void * sendcli(void* arg)
{

	char *argv = (char *)arg;
	while(1)
	{

		len = read(STDIN_FILENO,mess,sizeof(mess));//从键盘读取数据
		char mess1[1024];
		int ii = strlen(argv);
		sprintf(mess1,"%s : %s",argv,mess);
		bzero(mess,sizeof(mess1));
		int i = write(clientfile,mess1,len+i); //向服务器发送数据
		fflush(stdin);

	}

}
