# Chess Game Project

## Overview
This project is a console-based chess game implemented in C++. It allows two players to play a full game of chess with rule enforcement, including piece movement validation and checkmate detection.

## Features
- Fully functional chess game with standard rules.
- Supports all chess pieces: Pawn, Rook, Knight, Bishop, Queen, and King.
- Move validation for each piece.
- Check and Checkmate detection.
- Command-line interface for gameplay.
- Communication with a graphical interface via named pipes.

## Installation & Compilation
### Prerequisites
- A C++ compiler (GCC, Clang, or MSVC)
- CMake (optional, for easier compilation)
- Windows OS (named pipes are used for communication with the graphics interface)

### Compilation Steps
1. Clone the repository:
   ```sh
   git clone https://github.com/ysilberg/Chess-Project-Magshimim.git
   cd <project-directory>
   ```
2. Compile using g++:
   ```sh
   g++ -o chessGame Source.cpp Board.cpp Manager.cpp Piece.cpp Bishop.cpp King.cpp Knight.cpp Pwn.cpp Queen.cpp Rook.cpp -std=c++11
   ```
3. Run the game:
   ```sh
   ./chessGame
   ```

## Usage
- The game runs in the console and interacts with the user for moves.
- Players enter moves using chess notation (e.g., `e2e4` to move a piece from e2 to e4).
- The program checks for valid moves and enforces game rules.
- The game continues until checkmate or draw conditions are met.

## Code Structure
### Main Components
- **Source.cpp** – Entry point of the program, initializes the game.
- **Manager.cpp/.h** – Manages the game loop and rule enforcement.
- **Board.cpp/.h** – Represents the chessboard and handles piece placement.
- **Piece.cpp/.h** – Base class for all chess pieces.
- **MoveException.cpp/.h** – Custom exceptions for invalid moves.
- **Pipe.cpp/.h** – Handles communication with the graphical interface.

### Piece Implementations
- **Bishop.cpp/.h** – Implements diagonal movement.
- **King.cpp/.h** – Implements king's movement and check detection.
- **Knight.cpp/.h** – Implements L-shaped movement.
- **Pwn.cpp/.h** – Implements pawn movement and first-move rules.
- **Queen.cpp/.h** – Implements combined bishop and rook movement.
- **Rook.cpp/.h** – Implements straight-line movement.

## Future Improvements
- Implement a graphical user interface (GUI) for better interaction.
- Add AI for single-player mode.
- Improve move history tracking and undo functionality.
- Support for castling, en passant, and pawn promotion.

## Credits
- Developed by [Your Name].
- Chess rules and logic inspired by standard FIDE regulations.

## License
This project is licensed under the MIT License.

