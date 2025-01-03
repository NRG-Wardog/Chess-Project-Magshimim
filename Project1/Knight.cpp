#include "Knight.h"
#include <stdexcept>
#include <cmath> 

#define TYPE "Knight"
#define TWOSQURE 2
#define ONESQURE 1



//CTOR
Knight::Knight(char col, const std::string& pos) : Piece(col, pos)
{}

/*
* Checks if moving is possible.
* Input: string reference new position.
* Output: true or false
*/
bool Knight::canMove(const std::string& newPosition) const {
    int currentRow = _position[COL] - START_OF_NUM_BOARD;
    int currentCol = _position[ROW] - START_OF_BOARD;
    int newRow = newPosition[COL] - START_OF_NUM_BOARD;
    int newCol = newPosition[ROW] - START_OF_BOARD;

    // A knight moves in an "L" shape: 2 squares in one direction and 1 in the other
    int rowDiff = std::abs(newRow - currentRow);
    int colDiff = std::abs(newCol - currentCol);

    return (rowDiff == TWOSQURE && colDiff == ONESQURE) || (rowDiff == ONESQURE && colDiff == TWOSQURE);
}

/// func return type
/// intput:none
/// output:type <string>
std::string Knight::getType() const
{
    return std::string(TYPE);
}

/*
* Moves the piece across the board.
* Input: string reference new position.
* Output: none
*/
void Knight::move(const std::string& newPosition) {
    if (!canMove(newPosition)) {
        throw MoveException(MOVE_INVALID_ILLEGAL_PIECE_MOVE);
    }
    setPosition(newPosition);
}
