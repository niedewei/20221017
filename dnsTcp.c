#include<netdb.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>



int main(int argc,char *argv[])
{


		int cfd;
		int recbyte;
		int sin_size;
		char buffer[1024] = {0};
		struct sockaddr_in s_add, c_add;
		unsigned int portnum = 0x60000;
		char ch = 'A';
		printf("Hello,welcome to client!\r\n");


	struct hostent *hs=gethostbyname("cn-sy-dx-1.natfrp.cloud");
	if(hs==NULL)
	{
		printf("failed");
		exit(0);
	}

	char *ip=NULL;
	ip=inet_ntoa(*(struct in_addr*)hs->h_addr_list[0]);
	printf("ip:%s\r\n",ip);
	endhostent();

	cfd = socket(AF_INET, SOCK_STREAM, 0);
		if(-1 == cfd)
	{
		printf("socket fail ! \r\n");
		return -1;
	}

	printf("socket ok !\r\n");

	bzero(&s_add,sizeof(struct sockaddr_in));
	s_add.sin_family=AF_INET;
	s_add.sin_addr.s_addr= inet_addr(ip);
	s_add.sin_port=htons(60000);
	printf("s_addr = %#x ,port : %#x\r\n",s_add.sin_addr.s_addr,s_add.sin_port);

	if(-1 == connect(cfd,(struct sockaddr *)(&s_add), sizeof(struct sockaddr)))
	{
		printf("connect fail !\r\n");
		return -1;
	}
		printf("connect ok !\r\n");

	while(1)
	{
		 write(cfd, &ch, 1);														 		
         usleep(1000000);	
	}

	close(cfd);
	return 0;


}
