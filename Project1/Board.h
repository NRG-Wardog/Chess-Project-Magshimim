#pragma once
#include <string>
#include <vector>
#include <iostream>
#include "Piece.h"

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
    Board();
    ~Board();    
    Piece* const (&getBoard() const)[CHESS_SIZE][CHESS_SIZE];
    Piece* getSymbol(std::string& pos) const;
    void setBoard(const std::string& boardData);
    std::string toString() const;
    void movePiece(const std::string& from, const std::string& to); 
    bool isPathClear(const int fromRow, const int fromCol, const int toRow, const int toCol, const std::string& pieceType) const;



private:
    Piece* _board[CHESS_SIZE][CHESS_SIZE];
};
