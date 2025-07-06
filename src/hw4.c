#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define PORT1 2201
#define PORT2 2202

int main() {
    int server_fd1, server_fd2;
    struct sockaddr_in address1, address2;
    int addrlen = sizeof(struct sockaddr_in);

    // Create first socket
    if ((server_fd1 = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Create second socket
    if ((server_fd2 = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    printf("Created sockets for both players
");
    return 0;
}
