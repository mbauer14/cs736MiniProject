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
#include <time.h>

int main(int argc, char ** argv)
{
    int sizeBuffer, retval;
    int sockfd;
    int portno = 5050;
    int cli_sockfd;

    struct timespec stop;

    struct sockaddr_in client;
    memset(&client, 0, sizeof(client));
    socklen_t length = sizeof(client);

	if (argc < 3) {
		printf("Usage %s buffersize\n", argv[0]);
        exit(0);
	}
	else {
		sizeBuffer = atoi(argv[1]);
		portno = atoi(argv[2]);
    }

    char * buff = (char *) malloc(sizeBuffer+1);
    char * curr = buff;
    int charsReceived = 0;
    //memset(&buff, 0, sizeBuffer);
    
    int on = 1;

    sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    setsockopt(sockfd, IPPROTO_TCP, TCP_NODELAY, (const char *) &on, sizeof(int));
    setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, (const char *) &on, sizeof(int));

    if (sockfd == -1) {
        printf("ERROR: create socket.\n");
        return 0;
    } 

    struct sockaddr_in server;
    bzero(&server, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(portno);

    //Bind to a socket
    if (bind(sockfd, (struct sockaddr*) &server, sizeof(server)) != 0) {
        printf("ERROR: bind socket.\n");
        close(sockfd);
        return 0;
    }

    //Listen and wait for a connection
    if (listen(sockfd, 5) != 0) {
        printf("ERROR: listen socket.\n");
        close(sockfd);
        return 0;
    }


    //Create a fd for the new connection
    cli_sockfd = accept(sockfd, (struct sockaddr *) & client, &length);
    if (cli_sockfd == -1) {
        printf("ERROR: accepting client.\n");
        close(sockfd);
        return 0;
    }

    //Receive the data
    while (charsReceived < sizeBuffer) {
         
        retval = recv(cli_sockfd, curr, sizeBuffer-charsReceived, 0);
        charsReceived += retval;
        curr += charsReceived;

    }
    /* 
    if (retval == -1) {
        printf("ERROR: reading from client.\n");
        close(cli_sockfd);
        close(sockfd);
        return 0;
    }
    if (retval > 0) {
        printf("num buffers received: %d\n", retval);
    }
    */
    clock_gettime(CLOCK_REALTIME, &stop);

    retval = send(cli_sockfd, &stop, sizeof(struct timespec), 0);

    if (retval == -1) {
        printf("ERROR: sending to client.\n");
        close(cli_sockfd);
        close(sockfd);
        return 0;
    }



    close(cli_sockfd);
    close(sockfd);

    return 0;
}
