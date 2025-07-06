#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define PORT1 2201
#define PORT2 2202

int main() {
    printf("Battleship server starting...
");
    printf("Will listen on ports %d and %d
", PORT1, PORT2);
    return 0;
}
