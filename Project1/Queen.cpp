#include "Queen.h"
#include <stdexcept>
#include <cmath> // For std::abs


Queen::Queen(char col, const std::string& pos) : Piece(col,pos)
{}

/*
* Checks if moving is possible.
* Input: string reference new position.
* Output: true or false
*/
bool Queen::canMove(const std::string& newPosition) const {

    int currentRow = _position[1] - '0';
    int currentCol = _position[0] - 'a';
    int newRow = newPosition[1] - '0';
    int newCol = newPosition[0] - 'a';

    // Check if the move is straight (like a Rook) or diagonal (like a Bishop)
    
    bool diagonalMove = (std::abs(newRow - currentRow) == std::abs(newCol - currentCol));
    bool straightMove = (currentRow == newRow || currentCol == newCol);
    return straightMove || diagonalMove;
}

std::string Queen::getType() const
{
    return std::string("Queen");
}

/*
* Moves the piece across the board.
* Input: string reference new position.
* Output: none
*/
void Queen::move(const std::string& newPosition) {
    if (!canMove(newPosition)) {
        throw std::invalid_argument("Invalid move for Queen.");
    }
    setPosition(newPosition);
}