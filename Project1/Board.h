#pragma once
#include <string>
#include <vector>
#include <iostream>
#include "Piece.h"
#include "MoveException.h"
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
    const std::vector<std::vector<Piece*>>& getBoard() const;
    Piece* getSymbol(std::string& pos) const;
    void setBoard(const std::string& boardData);
    std::string toString() const;
    void movePiece(const std::string& from, const std::string& to); 
    bool isPathClear(const int fromRow, const int fromCol, const int toRow, const int toCol, const std::string& pieceType) const;
    friend std::ostream& operator<<(std::ostream& os, const Board& board);
private:
    std::vector<std::vector<Piece*>> _board;
    bool _whiteTurn;
};
