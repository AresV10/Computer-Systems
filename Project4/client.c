#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#define SA struct sockaddr

void func(int sockfd)
{
    printf("starting func\n");
    char buff[80];
    int n;
    char msg[] = "cs230 HELLO bmandla@umass.edu\n";
    send(sockfd, msg, strlen(msg), 0);
    while (1)
    {
        recv(sockfd, buff, 2000, 0);
        printf("%s", buff);
        //solve answer
        //check for STATUS
        //extract info
        if (strstr(buff, "STATUS") != NULL)
        {
            int a = 0, b = 0, answer = 0;
            char c;
            sscanf(buff, "%*s"
                         "%*s"
                         "%i"
                         " %c "
                         "%i",
                   &a, &c, &b);

            printf("%i ", a);
            printf("%c ", c);
            printf("%i\n", b);

            switch (c)
            {
            case '+':
                answer = a + b;
                break;
            case '-':
                answer = a - b;
                break;
            case '*':
                answer = a * b;
                break;
            case '/':
                answer = a / b;
                break;
            default:
                break;
            }
            printf("The Answer is %i\n", answer);
            sprintf(buff, "cs230  %d\n", answer);
            send(sockfd, buff, strlen(buff), 0);
        }
        //this is the flag
        if (strstr(buff, "BYE") != NULL)
        {
            return;
        }
    }
}

int main(int argc, char *argv[])
{
    int port = atoi(argv[2]);
    char *add = argv[3];
    int sockfd, connfd;
    struct sockaddr_in servaddr, cli;

    // socket create and varification
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1)
    {
        printf("socket creation failed...\n");
        exit(0);
    }
    else
        printf("Socket successfully created..\n");
    bzero(&servaddr, sizeof(servaddr));

    // assign IP, PORT
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = inet_addr(add);
    servaddr.sin_port = htons(port);
    //27993, "128.119.243.147"

    // connect the client socket to server socket
    if (connect(sockfd, (SA *)&servaddr, sizeof(servaddr)) != 0)
    {
        printf("connection with the server failed...\n");
        exit(0);
    }
    else
        printf("connected to the server..\n");

    // function for chat
    func(sockfd);

    // close the socket
    close(sockfd);
}