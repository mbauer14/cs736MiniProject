#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/tcp.h>

int main(int argc, char ** argv)
{
    int sizeBuffer, retval;
    int sockfd;
    int portno;
    
	if (argc < 3) {
		printf("Usage %s buffersize\n", argv[0]);
        exit(0);
	}
	else {
		sizeBuffer = atoi(argv[1]);
		portno = atoi(argv[2]);
    }

    //sizeBuffer = 100;
    void * buff = malloc(sizeBuffer);
    //char buff[100];
    //bzero(&buff, sizeBuffer);


    int on = 1;

    sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    setsockopt(sockfd, IPPROTO_TCP, TCP_NODELAY, (const char *)&on, sizeof(int));

    if (sockfd == -1) {
        printf("ERROR: create socket.");
    }

    struct sockaddr_in client;
    bzero(&client, sizeof(client));
    client.sin_family = AF_INET;
    client.sin_addr.s_addr = inet_addr("127.0.0.1");
    client.sin_port = htons(portno);
     
    //Actually connect to the server
    if (connect(sockfd, (struct sockaddr*)&client, sizeof(client)) != 0) {
        printf("ERROR: connect\n");
        close(sockfd);
        return 0;
    }


    //Send the buffer
    retval = send(sockfd, buff, sizeBuffer, 0);
    if (retval == -1) {
        printf("ERROR: sending to server.\n");
        close(sockfd);
        return 0;
    }
  
    //Receive the data
    retval = recv(sockfd, buff, sizeBuffer, 0);
    if (retval == -1) {
        printf("ERROR: reading from server.\n");
        close(sockfd);
        return 0;
    }


    printf("Complete.\n");
    close(sockfd);

    return 0;
}
