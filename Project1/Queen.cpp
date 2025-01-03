#include "Queen.h"
#include <stdexcept>
#include <cmath>
#define TYPE "Queen"

//c'tor
Queen::Queen(char col, const std::string& pos) : Piece(col,pos)
{}

/*
* Checks if moving is possible.
* Input: string reference new position.
* Output: true or false
*/
bool Queen::canMove(const std::string& newPosition) const 
{
    int currentRow = _position[1] - '0';
    int currentCol = _position[0] - 'a';
    int newRow = newPosition[1] - '0';
    int newCol = newPosition[0] - 'a';

    bool diagonalMove = (std::abs(newRow - currentRow) == std::abs(newCol - currentCol)); // Check if the move is diagonal (like a Bishop)
    bool straightMove = (currentRow == newRow || currentCol == newCol); // Check if the move is straight (like a Rook)
    return straightMove || diagonalMove;
}

/*
*func return type
* input:none
* output:string type
*/
std::string Queen::getType() const
{
    return std::string(TYPE);
}

/*
* Moves the piece across the board.
* Input: string reference new position.
* Output: none
*/
void Queen::move(const std::string& newPosition) {
    if (!canMove(newPosition)) {
        throw MoveException(MOVE_INVALID_ILLEGAL_PIECE_MOVE);
    }
    setPosition(newPosition);
}