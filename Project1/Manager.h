#ifndef MANAGER_H
#define MANAGER_H

#include "board.h"
#include "King.h"
#include "Pipe.h"
#include "MoveException.h"
#include <iostream>

class Manager {
private:
    bool _isWhiteTurn;
    Pipe _p;

public:
    
    Manager();
    
    ~Manager();
   
    bool validateMove(Piece* piece, std::string& newPosition);
    void movePiece(Piece* piece, std::string& newPosition); 
    bool isCheck(); 
    void resetGame(); 
    bool isGameOver(); 
    void displayBoard(Board _chessBoard);
    void gameLoop(Board& board);
};

#endif

