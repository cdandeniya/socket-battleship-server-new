#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define PORT1 2201
#define PORT2 2202

int main() {
    int server_fd1, server_fd2, client1_fd, client2_fd;
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

    // Set up address structures
    address1.sin_family = AF_INET;
    address1.sin_addr.s_addr = INADDR_ANY;
    address1.sin_port = htons(PORT1);

    address2.sin_family = AF_INET;
    address2.sin_addr.s_addr = INADDR_ANY;
    address2.sin_port = htons(PORT2);

    // Bind first socket
    if (bind(server_fd1, (struct sockaddr *)&address1, sizeof(address1)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Bind second socket
    if (bind(server_fd2, (struct sockaddr *)&address2, sizeof(address2)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen on both sockets
    if (listen(server_fd1, 1) < 0) {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }

    if (listen(server_fd2, 1) < 0) {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Server listening on ports %d and %d...
", PORT1, PORT2);

    // Accept first player
    if ((client1_fd = accept(server_fd1, (struct sockaddr *)&address1, (socklen_t*)&addrlen)) < 0) {
        perror("accept failed");
        exit(EXIT_FAILURE);
    }
    printf("Player 1 connected on port %d!
", PORT1);

    // Accept second player
    if ((client2_fd = accept(server_fd2, (struct sockaddr *)&address2, (socklen_t*)&addrlen)) < 0) {
        perror("accept failed");
        exit(EXIT_FAILURE);
    }
    printf("Player 2 connected on port %d!
", PORT2);

    printf("Both players connected! Starting game...
");

    close(client1_fd);
    close(client2_fd);
    close(server_fd1);
    close(server_fd2);
    return 0;
}
