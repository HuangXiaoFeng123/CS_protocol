#ifndef SERVE__H
#define SERVE__H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>      
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>
#include <unistd.h>
typedef struct sockaddr_in SIN;
typedef struct sockaddr SA;
int MySocket(int domain, int type, int protocol);
int MyBind(int sockfd, const struct sockaddr *addr,socklen_t addrlen);
int MyListen(int sockfd, int backlog);
void* rMsg(void *clifd_temp);
#endif