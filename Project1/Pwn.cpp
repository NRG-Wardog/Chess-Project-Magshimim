#include "Pwn.h"

Pwn::Pwn(char col, const std::string& pos) : Piece(col,pos), _firstMove(true)
{}

void Pwn::move(const std::string & newPosition)
{
    if (canMove(newPosition)) {
        setPosition(newPosition);
    }
    else {
        throw std::invalid_argument("Invalid move for Pawn");
    }
}

bool Pwn::canMove(const std::string& newPosition) const
{
    int direction = (_color == 'w') ? 1 : -1;
    char newCol = newPosition[0];
    int newRow = newPosition[1] - '0';
    char currCol = _position[0];
    int currRow = _position[1] - '0';
    return (newCol == currCol && (newRow == currRow + direction || (_firstMove && newRow == currRow + 2 * direction)));
}
