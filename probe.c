#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<string.h>
#include<time.h>
#include<errno.h>
#include<unistd.h>
#define MSG_CONFIRM 0
#define TRUE 1
#define FALSE 0

typedef struct list
{
  int probe[3];
}list;

int connect_to_port(int connect_to)
{
  int sock_id;
  int opt;
  struct sockaddr_in server;
  if(sock_id=SOCKET(AF_INET,SOCK_DGRAM,0)<0)
  {
    printf("Socket creation failed!");
    exit(EXIT_FAILURE);
  }
  setsockopt(sock_id,SOL_SOCK,SO_REUSEADDR,(const void *)&opt,sizeof(opt));
  memset(&server,0,sizeof(server));
  server.sin_family = AF_INET;
  server.sin_addr.s_addr = INADDR_ANY;
  server.sin_port = htons(connect_to);
  if(bind(sock_id,(const struct sockaddr *)&server,sizeof(server))<0)
  {
    printf("Binding failed!");
    exit(EXIT_FAILURE);
  }
  return sock_id;
}




