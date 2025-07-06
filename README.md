# Socket Battleship Server

This project implements a networked Battleship game server in C, using TCP sockets to allow two players to connect and play a game of Battleship in real time. The server manages the game state, validates player moves, and enforces the rules of the game.

## Features
- **Two-player Battleship gameplay** over TCP sockets
- **Custom board size** and ship placement
- **Robust command parsing** and error handling
- **Turn-based play** with real-time feedback
- **Clear error codes** and server-side logging for debugging
- **Extensible C codebase** for further enhancements

## How it Works
- The server listens on two ports (default: 2201 and 2202), one for each player.
- Players connect using a client (provided or custom) and send commands to initialize the board, place ships, and fire at the opponent.
- The server validates all commands, updates the game state, and sends responses or error codes as appropriate.
- The game continues until one player sinks all of the opponent's ships.

## Project Context
This codebase was originally developed as part of a private university course project. As such, the public commit history is not extensive, and some earlier development history is not included here. The current repository reflects a clean, functional, and well-documented version of the project, suitable for learning, demonstration, or further development.

## Getting Started
1. **Build the server:**
   ```sh
   ./build_scripts/build.sh
   ```
2. **Run the server:**
   ```sh
   ./build_scripts/run_server.sh
   ```
3. **Connect clients:**
   Use the provided `player_automated` or `player_interactive` clients, or build your own client to connect to the server ports.

## Directory Structure
- `src/` — C source code for the server and clients
- `build_scripts/` — Scripts to build and run the server/clients
- `scripts/` — Example scripts for automated testing

## Notes
- This project is a solid foundation for learning about network programming, socket communication, and game logic in C.
- Contributions and forks are welcome for educational or personal use.

---

*Developed for a past private course project. For questions or further improvements, feel free to open an issue or fork the repository.*
