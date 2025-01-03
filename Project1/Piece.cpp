#include "Piece.h"
#include <iostream>
#include <stdexcept>

#define WHITE_STR "White"
#define BLACK_STR "Black"


//c'tor
Piece::Piece(const char col, const std::string& pos)
{
	_color = col;
	setPosition(pos);
}

/*
* func return position 
* input:none
* output:string pos
*/
std::string Piece::getPosition() const
{
	return _position;
}

/*
* func return color
* input:none
* output:char col
*/
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

/*
* func print to screen
* input:os,piece refrance const
* output:os to print
*/
std::ostream& operator<<(std::ostream& os, const Piece& piece) {
    os << "Piece: " << piece.getType() 
       << ", Color: " << (piece._color == WHITE ? WHITE_STR : BLACK_STR)
       << ", Position: " << piece._position;
    return os;
}