#ifndef MANAGER_H
#define MANAGER_H

#include "board.h"
#include "pieces.h"
#include "King.h"
#include "Pipe.h"


class Manager {
private:
    bool _isWhiteTurn;
    Pipe pipe;

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

