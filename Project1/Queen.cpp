#include "Queen.h"
#include <stdexcept>
#include <cmath> // For std::abs


Queen::Queen(char col, const std::string& pos) : Piece(col,pos)
{}


bool Queen::canMove(const std::string& newPosition) const {
    int currentRow = _position[1] - '1'; // Convert '1'-'8' to 0-7
    int currentCol = _position[0] - 'a'; // Convert 'a'-'h' to 0-7
    int newRow = newPosition[1] - '1';
    int newCol = newPosition[0] - 'a';

    // Check if the move is straight (like a Rook) or diagonal (like a Bishop)
    bool straightMove = (currentRow == newRow || currentCol == newCol);
    bool diagonalMove = (std::abs(newRow - currentRow) == std::abs(newCol - currentCol));

    return straightMove || diagonalMove;
}

void Queen::move(const std::string& newPosition) {
    if (!canMove(newPosition)) {
        throw std::invalid_argument("Invalid move for Queen.");
    }
    setPosition(newPosition);
}