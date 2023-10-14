#ifndef CLIENT__H
#define CLIENT__H
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>          
#include <sys/socket.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <unistd.h>
#include <pthread.h>
typedef struct sockaddr_in SIN;
typedef struct sockaddr SA;
int MySocket(int domain, int type, int protocol);
int MyConnect(int sockfd, const struct sockaddr *addr,socklen_t addrlen);
void *rMsg(void *serfd);
#endif
