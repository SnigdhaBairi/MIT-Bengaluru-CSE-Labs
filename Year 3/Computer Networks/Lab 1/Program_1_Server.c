// Make the necessary includes and set up the variables:
#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#define PORTNO 10200
int main()
{
int sockfd,newsockfd,portno,clilen,n=1;
struct sockaddr_in seraddr,cliaddr;
int i,value;
// create an unnamed socket for the server
sockfd = socket(AF_INET,SOCK_STREAM,0);
//Name the socket
seraddr.sin_family = AF_INET;
seraddr.sin_addr.s_addr = inet_addr("172.20.16.37");// **
seraddr.sin_port = htons(PORTNO);
bind(sockfd,(struct sockaddr *)&seraddr,sizeof(seraddr));
//Create a connection queue and wait for clients
listen(sockfd,5);
while (1) {
char buf[256];
printf("server waiting");
//Accept a connection
clilen = sizeof(clilen);
newsockfd=accept(sockfd,(struct sockaddr *)&cliaddr,&clilen);
//Read and write to client on client_sockfd (Logic for problem mentioned here)
n = read(newsockfd,buf,sizeof(buf));//read the string from the client
//decryption of string by decreasing each character by 1
for(int i=0;i<strlen(buf);i++)
{
buf[i]=buf[i]-1;
}
printf(" \nMessage from Client %s \n",buf);
n = write(newsockfd,buf,sizeof(buf));//write the string to the client
}
}
