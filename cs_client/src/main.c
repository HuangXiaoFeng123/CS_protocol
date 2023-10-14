#include "client.h"

int main(int argc,char *argv[])
{
    if(argc!=3)
    {
        printf("formate error\n");
        printf("%s IP Port",argv[0]);
        return -1;
    }
    int serfd;
    serfd=MySocket(AF_INET,SOCK_STREAM,0);      //创建套接字
    SIN seraddr;                                //定义套接字地址结构
    bzero(&seraddr,sizeof(SIN));
    seraddr.sin_family=AF_INET;
    seraddr.sin_port=htons(atoi(argv[2]));
    seraddr.sin_addr.s_addr=inet_addr(argv[1]);
    MyConnect(serfd,(SA *)&seraddr,sizeof(SA)); //连接
    char sBuff[128];
    pthread_t id;
    pthread_create(&id,NULL,rMsg,(void *)&serfd);
    while(1)
    {
        gets(sBuff);
        write(serfd,sBuff,strlen(sBuff));         //发送
    }
    close(serfd);                                 //关闭
    return 0;
}