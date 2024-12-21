

#ifndef MANAGER_H
#define MANAGER_H

#include <vector>
#include <string>
#include "pieces.h"

class Manager {
private:
    std::vector<std::vector<Piece*>> board;
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

