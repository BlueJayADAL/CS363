/* redirect input to tcp */
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

void main() {
    struct sockaddr_in server;
    
    // Create a TCP socket
    int sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

    // Fill in the destination information (IP, port #, and family)
    memset(&server, '\0', sizeof(struct sockaddr_in));
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr("10.9.0.1");
    server.sin_port = htons(9090);

    // Connect to the destination
    connect(sockfd, (struct sockaddr*) &server, sizeof(struct sockaddr_in));

    // Read data from the TCP connection
    char data[100];
    // read(sockfd, data, 100);
    dup2(sockfd, 0);
    scanf("%s", data);
    printf("%s\n", data);
}
