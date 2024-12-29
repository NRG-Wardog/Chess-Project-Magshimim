#include "Bishop.h"
#include "MoveException.h"

#include <cmath> // For std::abs

Bishop::Bishop(char color, const std::string& position) : Piece(color, position)
{
}

bool Bishop::canMove(const std::string& newPosition) const
{
    int currentRow = _position[1] - '0'; 
    int currentCol = _position[0] - 'a'; 
    int newRow = newPosition[1] - '0';
    int newCol = newPosition[0] - 'a';

    // Check for valid indices
    if (currentRow < 0 || currentRow >= 8 || currentCol < 0 || currentCol >= 8 ||
        newRow < 0 || newRow >= 8 || newCol < 0 || newCol >= 8) {
        throw MoveException(MOVE_INVALID_OUT_OF_BOUNDS); // Invalid indices
    }

    // Check if the move is diagonal
    if (std::abs(newRow - currentRow) != std::abs(newCol - currentCol)) {
        throw MoveException(MOVE_INVALID_ILLEGAL_PIECE_MOVE); // Illegal move for the piece
    }

    return true;
}

void Bishop::move(const std::string& newPosition)
{
    if (!canMove(newPosition)) {
        throw MoveException(MOVE_INVALID_ILLEGAL_PIECE_MOVE); // Illegal move for the piece
    }
    setPosition(newPosition);
}

std::string Bishop::getType() const
{
    return "Bishop"; 
}
