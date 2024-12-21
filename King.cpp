#include "King.h"

King::King(char col, const std::string& pos) : Piece(col, pos)
{}

void King::move(const std::string& newPosition)
{
    if (canMove(newPosition)) {
        setPosition(newPosition);
    }
    else {
        throw std::invalid_argument("Invalid move for King");
    }
}

bool King::isAttacked(const Board& currentBoard)
{
    Piece* const (&boardState)[CHESS_SIZE][CHESS_SIZE] = currentBoard.getBoard();

    for (int row = 0; row < CHESS_SIZE; ++row) {
        for (int col = 0; col < CHESS_SIZE; ++col) {
            Piece* piece = boardState[row][col];

            // Check if there's an opposing piece
            if (piece != nullptr && piece->getColor() != this->getColor()) {
                // Convert king's position to row and col
                char kingCol = _position[0];
                int kingRow = _position[1] - '1';

                // Check if the opposing piece can move to the king's position
                std::string kingPos = std::string(1, kingCol) + std::to_string(kingRow + 1);
                if (piece->canMove(kingPos)) {
                    return true; // King is attacked
                }
            }
        }
    }
}

bool King::canMove(const std::string& newPosition) const
{
    char newCol = newPosition[0];
    int newRow = newPosition[1] - '0';
    char currCol = _position[0];
    int currRow = _position[1] - '0';

    return (std::abs(newCol - currCol) <= 1 && std::abs(newRow - currRow) <= 1);
}




