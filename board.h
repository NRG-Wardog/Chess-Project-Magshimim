#pragma once
#include <string>
#include <vector>

#include "pieces.h"

#define CHESS_SIZE 8


#define ROOK 'r'
#define KNIGHT 'n'
#define BISHOP 'b'
#define QUEEN 'q'
#define KING 'k'
#define PWN 'p'
#define EMPTY '#'

class Board
{
public:
    
    Board(const std::string& boardData);
    ~Board();    
    Piece* const (&getBoard() const)[CHESS_SIZE][CHESS_SIZE];
    Piece* getSymbol(std::string& pos) const;
    void setBoard(const std::string& boardData);


private:
    Piece* _board[CHESS_SIZE][CHESS_SIZE];
};
