#ifndef MANAGER_H
#define MANAGER_H

#include "board.h"
#include "pieces.h"


class Manager {
private:
    bool isWhiteTurn;
   

public:
    
    Manager();

    
    ~Manager();

    
    void startGame(); 
    bool validateMove(Piece* piece, int x, int y);
    void movePiece(Piece* piece, int x, int y); 
    bool isCheck(); 
    void resetGame(); 
    bool isGameOver(); 
    void displayBoard(); 
};

#endif

