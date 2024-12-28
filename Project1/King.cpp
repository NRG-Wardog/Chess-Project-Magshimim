#include "King.h"
#include "MoveException.h"
#include <cmath>
#include <stdexcept>

King::King(char col, const std::string& pos) : Piece(col, pos) {}

void King::move(const std::string& newPosition)
{
    if (!canMove(newPosition)) {
        throw MoveException(MOVE_INVALID_ILLEGAL_PIECE_MOVE); 
    }
    setPosition(newPosition);
}

bool King::isAttacked(const Board& currentBoard)
{
    Piece* const (&boardState)[CHESS_SIZE][CHESS_SIZE] = currentBoard.getBoard();

    for (int row = 0; row < CHESS_SIZE; ++row) {
        for (int col = 0; col < CHESS_SIZE; ++col) {
            Piece* piece = boardState[row][col];

            // Check if there's an opposing piece
            if (piece != nullptr && piece->getColor() != this->getColor()) {
                // Convert king's position to row and col
                char kingCol = _position[ROW];
                int kingRow = _position[COL] - START_OF_NUM_AS_CHAR;
                // Check if the opposing piece can move to the king's position
                std::string kingPos = std::string(1, kingCol) + std::to_string(kingRow + 1);
                // Validate position before calling canMove
                if (kingPos.size() != 2 || kingPos[ROW] < START_OF_ABC || kingPos[ROW] > CHESS_LETTER || kingPos[COL] < START_OF_NUM_AS_CHAR || kingPos[COL] > CHESS_SIZE_AS_CHAR) {
                    throw MoveException(MOVE_INVALID_OUT_OF_BOUNDS); // Invalid position
                }
                if (piece->canMove(kingPos)) {
                    return true; // King is attacked
                }
            }
        }
    }
    return false;
}


bool King::canMove(const std::string& newPosition) const
{
    // Validate newPosition format
    if (newPosition.size() != 2 ||
        newPosition[ROW] < START_OF_ABC || newPosition[ROW] > CHESS_LETTER ||
        newPosition[COL] < START_OF_NUM_AS_CHAR || newPosition[COL] > CHESS_SIZE_AS_CHAR) {
        throw MoveException(MOVE_INVALID_OUT_OF_BOUNDS); // Invalid position indices
    }

    char newCol = newPosition[ROW];
    int newRow = newPosition[COL] - '0'; // Convert '1'-'8' to 1-8
    char currCol = _position[ROW];
    int currRow = _position[COL] - '0';

    // Check if the move is within one square in any direction
    if (std::abs(newCol - currCol) <= 1 && std::abs(newRow - currRow) <= 1) {
        return true; // Valid move
    }

    return false; // Invalid move
}
