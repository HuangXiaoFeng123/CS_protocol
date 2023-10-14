#include "serve.h"
int MySocket(int domain, int type, int protocol)
{
    int listfd;
    listfd=socket(domain,type,protocol);
    if(listfd==-1)
    {
        printf("create socket fail\n");
        exit(0);
    }
    printf("create socket successful\n");
    return listfd;
}
int MyBind(int sockfd, const struct sockaddr *addr,socklen_t addrlen)
{
    int d;
    d=bind(sockfd,addr,addrlen);
    if(d==-1)
    {
        printf("bind fail\n");
        exit(0);
    }
    printf("bind successful\n");
    return d;
}
int MyListen(int sockfd, int backlog)
{
    int d;
    d=listen(sockfd,backlog);
    if(d==-1)
    {
        printf("listen fail\n");
        exit(0);
    }
    printf("listen successful\n");
    return d;
}
void* rMsg(void *clifd_temp)
{
    char rBuff[128];
    int clifd=*(int *)clifd_temp;
    while(1)
    {
        memset(rBuff,0,128);
        read(clifd,rBuff,128);
        printf("client: %s\n",rBuff);
    }

}