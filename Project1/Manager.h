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


#define BOARD_LETTERS "rnbkqbnrpppppppp################################PPPPPPPPRNBKQBNR0"
#define UNCONCTION "0"
#define BUFFER_SIZE 1024




class Manager {
private:
    bool _isWhiteTurn;
    Pipe _p;
    Board _board;

    Board createBoard(std::string&);

public:
    //ctor and dtor
    Manager(Pipe,std::string);
    ~Manager();
   //public funcs
    //bool validateMove(Piece* piece, std::string& newPosition);
    void movePiece(Piece* piece, std::string& newPosition); 
    bool isCheck(bool); 
    void resetGame(); 
    bool isGameOver(); 
    void displayBoard();
    void gameLoop(std::string strBoard);
};

#endif

