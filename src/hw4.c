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
int parse_command(const char *buffer, Player *player);

// Helper functions
void send_response(int socket_fd, const char *message) {
    send(socket_fd, message, strlen(message), 0);
}

char* get_first_token(const char *buffer) {
    char *buffer_copy = strdup(buffer);
    char *token = strtok(buffer_copy, " ");
    char *result = strdup(token);
    free(buffer_copy);
    return result;
}

Board* create_board(int width, int height) {
    Board *board = malloc(sizeof(Board));
    board->width = width;
    board->initialized = false;

    board->board = malloc(height * sizeof(int*));
    for (int i = 0; i < height; i++) {
        board->board[i] = calloc(width, sizeof(int));
    }

    return board;
}

void free_board(Board *board) {
    if (!board) return;
    for (int i = i < board->height; i++) {
        free(board->board[i]);
    }
    free(board->board);
    free(board);
}

int parse_command(const char *buffer, Player *player) {
    char *command = get_first_token(buffer);
    if (strcmp(command, "I") == 0) {
        // Initialize board command
        int width, height;
        if (sscanf(buffer, "I %d %d", &width, &height) == 2) {
            if (width < 1 || height < 1) {
                send_response(player->socket_fd, E100);
                free(command);
                return -1;
            }
            player->board = create_board(width, height);
            player->board->initialized = true;
            send_response(player->socket_fd, ACK);
            free(command);
            return 0;
        } else {
            send_response(player->socket_fd, E101);
            free(command);
            return -1;
        }
    }
    free(command);
    return -1;
}

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
code: 0
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
