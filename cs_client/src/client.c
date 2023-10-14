#include "client.h"
int MySocket(int domain, int type, int protocol)
{
    int fd;
    fd=socket(domain,type,protocol);
    if(fd==-1)
    {
        printf("create socket fail\n");
        exit(0);
    }
    printf("create socket successful\n");
    return fd;
}
int MyConnect(int sockfd, const struct sockaddr *addr,socklen_t addrlen)
{
    int d;
    d=connect(sockfd,addr,addrlen);
    if(d==-1)
    {
        printf("connect fail\n");
        exit(0);
    }
    printf("connect successful\n");
    return d;
}
void *rMsg(void *serfd_temp)
{
    char rBuff[128];
    int serfd=*(int *)serfd_temp;
    while(1)
    {
        int ret;
        memset(rBuff,0,128);
        ret=read(serfd,rBuff,128);
        if(ret==0)
        {
            printf("serve close\n");
            close(serfd);
            exit(0);
        }
        printf("serve: %s\n",rBuff);
    }
}