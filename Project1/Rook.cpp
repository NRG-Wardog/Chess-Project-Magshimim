#include "Rook.h"
#include "MoveException.h"



Rook::Rook(char col, const std::string& pos)
    : Piece(col, pos)
{
    if (pos.size() != 2 || pos[ROW] < START_OF_ABC || pos[ROW] > CHESS_LETTER || pos[COL] < START_OF_NUM_AS_CHAR || pos[COL] > CHESS_SIZE_AS_CHAR) {
        throw MoveException(MOVE_INVALID_OUT_OF_BOUNDS); // Invalid position indices
    }
}

void Rook::move(const std::string& newPosition) {
    if (!canMove(newPosition)) {
        throw MoveException(MOVE_INVALID_ILLEGAL_PIECE_MOVE); // Illegal move for Rook
    }

    _position = newPosition;
}

bool Rook::canMove(const std::string& newPosition) const {
    // Validate position format
<<<<<<< HEAD
    if (newPosition.size() != 2 || newPosition[ROW] < START_OF_ABC || newPosition[ROW] > CHESS_LETTER || newPosition[COL] < START_OF_NUM_AS_CHAR || newPosition[COL] > CHESS_SIZE_AS_CHAR) {
=======
    if (newPosition.size() != 2 || newPosition[ROW] < START_OF_ABC || newPosition[ROW] > CHESS_LETTER || newPosition[COL] < START_OF_NUM_AS_CHAR || newPosition[COL] > CHESS_SIZE_AS_CHAR) 
    {
>>>>>>> f7d7c4ba3e9efaace66ef53ed71b1299985547a9
        throw MoveException(MOVE_INVALID_OUT_OF_BOUNDS); // Invalid position indices
    }

    char currentFile = _position[ROW];
    char currentRank = _position[COL];
    char newFile = newPosition[ROW];
    char newRank = newPosition[COL];

    // Rook can only move in straight lines: same file or same rank
    if (currentFile == newFile || currentRank == newRank) {
        return true;
    }

    return false;
}
