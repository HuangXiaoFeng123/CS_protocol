#include "serve.h"

int main(int argc,char *argv[])
{
    if(argc!=3)
    {
        printf("formate error\n");
        printf("%s IP port\n",argv[0]);
        return -1;
    }
    int listfd;
    listfd=MySocket(AF_INET,SOCK_STREAM,0);
    SIN seraddr;
    seraddr.sin_family=AF_INET;
    seraddr.sin_port=htons(atoi(argv[2]));
    seraddr.sin_addr.s_addr=inet_addr(argv[1]);
    MyBind(listfd,(SA *)&seraddr,sizeof(SA));
    MyListen(listfd,5);
    while(1)
    {
        SIN cliaddr;
        int lent;
        int clifd;
        clifd=accept(listfd,(SA *)&cliaddr,&lent);
        if(clifd==-1)
        {
            printf("accept fail\n");
            exit(0);
        }
        printf("accept successful\n");
        char sBuff[128];
        pthread_t id;
        pthread_create(&id,NULL,rMsg,(void *)&clifd);
        while(1)
        {
            gets(sBuff);
            write(clifd,sBuff,strlen(sBuff));
        }
    }
    return 0;
}