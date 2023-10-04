#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

void error(const char *msg)
{
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[])
{
    int sockfd, newsockfd, portno;
    socklen_t clilen;
    char buffer[255];
    struct sockaddr_in servAddr, cliAddr;
    int n;

    if (argc < 2)
    {
        fprintf(stderr, "ERROR, no port provided\n");
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);


    if (sockfd < 0)
        error("ERROR opening socket");

    bzero((char *) &serv_addr, sizeof(serv_addr));
    portno = atoi(argv[1]);
    servAddr.sin_family = AF_INET;
    servAddr.sin_addr.s_addr = INADDR_ANY;
    servAddr.sin_port = htons(portno);


    if (bind(sockfd, (struct sockaddr *) &servAddr,
        sizeof(servAddr)) < 0)
        error("ERROR on binding");

    listen(sockfd,5);
    clilen = sizeof(cliAddr);


	newsockfd = accept(sockfd,
                 (struct sockaddr *) &cliAddr,
                 &clilen);

    if (newsockfd < 0)
        error("ERROR on accept");

    while (1)
    {
        bzero(buffer, 256);
        n = read(newsockfd, buffer, 255);
        if (n < 0)
            error("ERROR reading from socket");

        printf("Client: %s\n", buffer);
        bzero(buffer, 256);
        fgets(buffer, 255, stdin);
        n = write(newsockfd, buffer, strlen(buffer));
        if (n < 0)
            error("ERROR writing to socket");

        int i=strncmp("Bye", buffer, 3);
        if(i == 0)
            break;
     }

     close(newsockfd);
     close(sockfd);
     return 0;
}
