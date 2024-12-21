#include "pieces.h"
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

void Piece::setPosition(const std::string& pos)
{
	if (pos[0]<'a' || pos[0] > 'z' || pos[1]>9 || pos[1] < 0)
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