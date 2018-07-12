#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <pthread.h>
#include <string.h>

typedef struct
{

	int *files;
	int client;

}distinguish_client;


static int port = 9090;//端口号
static char mess[1024];//发送的信息的容器
static int onefile,twofile;//两个客户端的文件描述符
static struct sockaddr_in client1,client2;// 两个客户端的IP 

void * do_translate(void *arguments);


int main(int argc,char *argv[])
{
	int sockfd;//文件描述符
	struct sockaddr_in serveraddr;//服务器IP
	struct sockaddr_in adds[2] = {client1,client2};
	int files[2] = {onefile,twofile};
	int addlen;
	int clients = 0;//连接的客户端的数量

	pthread_t pid1,pid2;
	pthread_t pids[2] = {pid1,pid2};

	bzero(&serveraddr,sizeof(serveraddr));
	serveraddr.sin_family = AF_INET;
	serveraddr.sin_addr.s_addr = htons(INADDR_ANY);
	serveraddr.sin_port = htons(port);
	serveraddr.sin_family = AF_INET;

	sockfd = socket(AF_INET,SOCK_STREAM,0);
	bind(sockfd,(struct sockaddr*)&serveraddr,sizeof(serveraddr));
	listen(sockfd,128);

	while(clients < 2 )
	{

		distinguish_client *d2 = (distinguish_client *)malloc(sizeof(distinguish_client));
		d2->files = files;
		d2->client = clients;
		addlen = sizeof(adds[clients]);
		files[clients] = accept(sockfd,(struct sockaddr*)&adds[clients],&addlen);
		//开启线程,传入文件描述符的数组


		int i=-1;
tryagin:i = pthread_create(&pids[clients],NULL,do_translate,d2);
	if(i == 0)	
	{
		char str[] = "线程启动\n";
		write(STDOUT_FILENO,str,sizeof(str));
		pthread_detach(pids[clients]);
		clients++;
	}
	else
	{

		goto tryagin;

	}
	}
	printf("开始聊天，啦啦啦........\n");
	while(1);
	return 0;
}

void * do_translate(void *arguments)
{
	char mess[1024];
	int i = -1;
	distinguish_client* dc = (distinguish_client*)arguments;
	while(1)
	{
		int client = dc->client;
		int len = read((dc->files)[client],mess,sizeof(mess));
		if(client == 1)
		{
			i = 0;
		}
		else
		{
			i = 1;
		}
		write((dc->files)[i],mess,len);
		bzero(mess,strlen(mess)+2);
		printf("客户%d发送了一条消息\n",client);

	}

}
