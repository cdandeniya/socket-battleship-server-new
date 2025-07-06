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

// Error codes
#define E100 "E 100"
#define E101 "E 101"
#define E102 "E 102"
#define E200 "E 200"
#define E201 "E 201"
#define E202 "E 202"
#define E300 "E 300"
#define E301 "E 301"
#define E302 "E 302"
#define E303 "E 303"
#define E400 "E 400"
#define E401 "E 401"

// Response codes
#define ACK "A"
#define HALT_WIN "H 1"
#define HALT_LOSS "H 0"

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

// Function declarations
void send_response(int socket_fd, const char *message);
char* get_first_token(const char *buffer);
Board* create_board(int width, int height);
void free_board(Board *board);

int main() {
    printf("Battleship server starting...
");
    return 0;
}
