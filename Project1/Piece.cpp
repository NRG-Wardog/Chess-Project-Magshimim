#include "Piece.h"
#include <iostream>
#include <stdexcept>

Piece::Piece(const char col, const std::string& pos)
{
	_color = col;
	setPosition(pos);
}

std::string Piece::getPosition() const
{
	return _position;
}

char Piece::getColor() const
{
	return _color;
}

/*
* Sets the position of the piece.
* Input: string reference pos.
* Output: none
*/
void Piece::setPosition(const std::string& pos)
{
	if (pos[ROW]< START_OF_BOARD || pos[ROW] > CHESS_END_OF_BOARD || pos[COL]> END_OF_NUM_BOARD || pos[COL] < START_OF_NUM_BOARD)
	{
		throw std::runtime_error("Invalid board data size. Expected 64 characters.");
	}
	_position = pos;
}

std::ostream& operator<<(std::ostream& os, const Piece& piece) {
    os << "Piece: " << piece.getType() 
       << ", Color: " << (piece._color == 'w' ? "White" : "Black") 
       << ", Position: " << piece._position;
    return os;
}