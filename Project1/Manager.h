#ifndef MANAGER_H
#define MANAGER_H

#define WHITE_TURN 0
#define BLACK_TURN 1

#include "Board.h"
#include "King.h"
#include "Pipe.h"
#include "MoveException.h"
#include <iostream>
#include "Piece.h"
#include <thread>
#include <string>
#include <chrono>
#include <stdexcept>

class Manager {
private:
    bool _isWhiteTurn;
    Pipe _p;
    Board _board;

    Board createBoard(std::string&);

public:
    
    Manager(Pipe,std::string);
    
    ~Manager();
   
    bool validateMove(Piece* piece, std::string& newPosition);
    void movePiece(Piece* piece, std::string& newPosition); 
    bool isCheck(); 
    void resetGame(); 
    bool isGameOver(); 
    void displayBoard();
    void gameLoop(std::string strBoard);
};

#endif

