#include "Rook.h"


Rook::Rook(char col, const std::string& pos)
    : Piece(col, pos) 
{
    if (pos.size() != 2 || pos[0] < 'a' || pos[0] > 'h' || pos[1] < '1' || pos[1] > '8') {
        throw std::invalid_argument("Invalid position for Rook");
    }
}


void Rook::move(const std::string& newPosition) {
    if (!canMove(newPosition)) {
        throw std::invalid_argument("Rook cannot move to the specified position");
    }

    _position = newPosition;
}


bool Rook::canMove(const std::string& newPosition) const {
    if (newPosition.size() != 2 || newPosition[0] < 'a' || newPosition[0] > 'h' || newPosition[1] < '1' || newPosition[1] > '8') {
        return false;
    }

    char currentFile = _position[0];
    char currentRank = _position[1];
    char newFile = newPosition[0];
    char newRank = newPosition[1];

    return (currentFile == newFile || currentRank == newRank);
}
