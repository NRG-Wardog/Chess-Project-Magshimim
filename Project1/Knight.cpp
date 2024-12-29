#include "Knight.h"
#include <stdexcept>
#include <cmath> 

/*
* Checks if moving is possible.
* Input: string reference new position.
* Output: true or false
*/
bool Knight::canMove(const std::string& newPosition) const {
    int currentRow = _position[1] - '1'; 
    int currentCol = _position[0] - 'a'; 
    int newRow = newPosition[1] - '1';
    int newCol = newPosition[0] - 'a';

    // A knight moves in an "L" shape: 2 squares in one direction and 1 in the other
    int rowDiff = std::abs(newRow - currentRow);
    int colDiff = std::abs(newCol - currentCol);

    return (rowDiff == 2 && colDiff == 1) || (rowDiff == 1 && colDiff == 2);
}

std::string Knight::getType() const
{
    return std::string("Knight");
}

Knight::Knight(char col, const std::string& pos) : Piece(col,pos)
{}

/*
* Moves the piece across the board.
* Input: string reference new position.
* Output: none
*/
void Knight::move(const std::string& newPosition) {
    if (!canMove(newPosition)) {
        throw std::invalid_argument("Invalid move for Knight.");
    }
    setPosition(newPosition);
}
