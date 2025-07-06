#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <stdbool.h>

#define PORT1 2201
#define PORT2 2202
#define BUFFER_SIZE 1024
#define MAX_PIECES 5

// Game state
typedef struct {
    int width;
    int height;
    int **board;
    int pieces_remaining;
    bool initialized;
} Board;

typedef struct {
    int socket_fd;
    int player_number;
    Board *board;
    bool ready;
} Player;

int main() {
    printf("Battleship server starting...
");
    return 0;
}
