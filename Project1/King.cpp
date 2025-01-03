#include "King.h"
#include "MoveException.h"
#include <cmath>
#include <stdexcept>

#define TYPE "King"
#define DISTANCE 1

King::King(char col, const std::string& pos) : Piece(col, pos) {}

/*
* Moves the piece across the board.
* Input: string reference new position.
* Output: none
*/
void King::move(const std::string& newPosition)
{
    if (!canMove(newPosition)) {
        throw MoveException(MOVE_INVALID_ILLEGAL_PIECE_MOVE); 
    }
    setPosition(newPosition);
}

/*
* Checks if moving is possible.
* Input: string reference new position.
* Output: true or false
*/
bool King::canMove(const std::string& newPosition) const
{
    // Validate newPosition format
    bool valid = false;
    if (newPosition.size() != POS_SIZE||newPosition[ROW] < START_OF_BOARD || newPosition[ROW] > CHESS_END_OF_BOARD ||
        newPosition[COL] < START_OF_NUM_AS_CHAR || newPosition[COL] > CHESS_SIZE_AS_CHAR) 
    {
        throw MoveException(MOVE_INVALID_OUT_OF_BOUNDS); 
    }

    char newCol = newPosition[ROW];
    int newRow = newPosition[COL] - START_OF_NUM_BOARD;
    char currCol = _position[ROW];
    int currRow = _position[COL] - START_OF_NUM_BOARD;

    // Check if the move is within one square in any direction
    if (std::abs(newCol - currCol) <= DISTANCE && std::abs(newRow - currRow) <= DISTANCE) {
        valid =  true; // Valid move
    }

    return valid; // Invalid move
}

/// <summary>
/// fubc return type
/// </summary>
/// <returns></type string>
std::string King::getType() const
{
    return std::string(TYPE);
}
