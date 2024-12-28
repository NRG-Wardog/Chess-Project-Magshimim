#include "Knight.h"
#include <stdexcept>
#include <cmath> 


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

Knight::Knight(char col, const std::string& pos) : Piece(col,pos)
{}

void Knight::move(const std::string& newPosition) {
    if (!canMove(newPosition)) {
        throw std::invalid_argument("Invalid move for Knight.");
    }
    setPosition(newPosition);
}
