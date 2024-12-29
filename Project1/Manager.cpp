#include "Manager.h"
#include "Board.h"
#include "Piece.h"
#include <iostream>

#include "MoveException.h"
#define START_OF_BOARD 'a'
#define START_OF_NUM 1


Manager::Manager(Pipe p,std::string chess) : _board(chess), _p(p)
{
    _isWhiteTurn = chess[64] == '0';
}

Manager::~Manager() {}



/*
Validates the move.
Input: Piece pointer piece, string reference newPosition.
Output: true or false
*/
bool Manager::validateMove(Piece* piece, std::string& newPosition)
{
    return piece->canMove(newPosition);
}

/*
Moves the piece itself.
Input: Piece pointer piece, string reference newPosition.
Output: none
*/
void Manager::movePiece(Piece* piece, std::string& newPosition)
{
    piece->move(newPosition);
}

bool Manager::isCheck()
{
    //return king.isAttacked();
    return false;
}


/*
Creates the board.
Input: string reference strBoard.
Output: none
*/
void Manager::createBoard(std::string& strBoard)
{
    if (strBoard.size() < 65) { throw std::runtime_error("size of board invalid."); }
    _isWhiteTurn = strBoard[64] == WHITE_TURN;
    _board = Board(strBoard);
}

void Manager::resetGame()
{
    std::string _chessboard = "rnbqkbnrpppppppp############################PPPPPPPPRNBQKBNR"; // like startgame in mangager
    gameLoop(_chessboard);
}

bool Manager::isGameOver()
{
    return false;
}



/*
Displays the board.
Input: Board type _chessBoard.
Output: none
*/
void Manager::displayBoard()
{
    std::cout << _board.toString();
}


/*
Main loop of the game.
Input: string strBoard.
Output: none
*/
void Manager::gameLoop(std::string strBoard)
{
    char msgToGraphics[1024];
    strcpy_s(msgToGraphics, _board.toString().c_str()); 
    _p.sendMessageToGraphics(msgToGraphics);
    displayBoard();
    std::string msgFromGraphics = _p.getMessageFromGraphics();
    
    while (isGameOver() == false && msgFromGraphics != "quit")
    {
        /*Receives 5 bytes; Message: "e2e4"*/
        try {
            std::string from = msgFromGraphics.substr(29,31);
            std::string to = msgFromGraphics.substr(32, 34);
            std::cout << from << "," << to;

            Piece* selectedPiece = _board.getSymbol(from);
            if (selectedPiece == nullptr) 
            {
                throw MoveException(MOVE_INVALID_SOURCE_EMPTY);
            }

            if ((_isWhiteTurn && selectedPiece->getColor() != 'w') ||
                (!_isWhiteTurn && selectedPiece->getColor() != 'b')) {
                throw MoveException(MOVE_INVALID_TURN);
            }

            if (!validateMove(selectedPiece, to)) {
                throw MoveException(MOVE_INVALID_ILLEGAL_PIECE_MOVE);
            }

            _board.movePiece(from, to);

            if (isCheck() == true)
            {
                throw MoveException(MOVE_VALID_CHECK);
            }
        }
        catch (const std::exception& e) 
        {
            if (e.what() == MOVE_VALID_STR || e.what() == MOVE_VALID_CHECK_STR)
            {
                bool validateMove(Piece * piece, int x, int y);
                strcpy_s(msgToGraphics, sizeof(msgToGraphics), "0");
            }
            msgToGraphics[0] = (char)(e.what());
            msgToGraphics[1] = 0;
            std::cerr << e.what() << std::endl;
            
        }
        std::string msgFromGraphics = _p.getMessageFromGraphics();
        std::cout << msgFromGraphics;
    }
}

