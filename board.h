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

class board
{
public:
    
    board(const std::string& boardData);
    ~board();    
    Piece* (&getBoard())[CHESS_SIZE][CHESS_SIZE];
    void setBoard(const std::string& boardData);


private:
    Piece* _board[CHESS_SIZE][CHESS_SIZE];
};
