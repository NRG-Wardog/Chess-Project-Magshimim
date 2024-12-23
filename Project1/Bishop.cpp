#include "Bishop.h"

#include <stdexcept>

Bishop::Bishop(char color, const std::string& position) : Piece(color,position)
{
}

bool Bishop::canMove(const std::string& newPosition) const
{
    int currentRow = _position[1] - '1'; // Convert '1'-'8' to 0-7
    int currentCol = _position[0] - 'a'; // Convert 'a'-'h' to 0-7
    int newRow = newPosition[1] - '1';
    int newCol = newPosition[0] - 'a';

    // Check if the move is diagonal
    return std::abs(newRow - currentRow) == std::abs(newCol - currentCol);
}

void Bishop::move(const std::string& newPosition)
{
	if (!canMove(newPosition)) {
		throw std::invalid_argument("Invalid move for Bishop.");
	}
	setPosition(newPosition);
    
}
