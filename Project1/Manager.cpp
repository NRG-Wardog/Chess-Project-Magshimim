#include "Manager.h"
#include "Board.h"
#include "Piece.h"
#include <iostream>

#include "MoveException.h"
#define START_OF_BOARD 'a'
#define START_OF_NUM 1


Manager::Manager(Pipe p,std::string chess) : _p(p),_board(chess)
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
Board Manager::createBoard(std::string& strBoard)
{
    if (strBoard.size() < 65) { throw std::runtime_error("size of board invalid."); }
    _isWhiteTurn = strBoard[64] == WHITE_TURN;
    _board = Board(strBoard);
    return _board;
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
    std::cout << _board;

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
        try {
            std::string from = msgFromGraphics.substr(0,2);
            std::string to = msgFromGraphics.substr(2, 4);
            std::cout << from << "," << to << "\n";
            
            if (from == to)
            {
                throw MoveException(MOVE_INVALID_IDENTICAL_SQUARES);
            }
            Piece* selectedPiece = _board.getSymbol(from);
            if (selectedPiece == nullptr) 
            {
                throw MoveException(MOVE_INVALID_SOURCE_EMPTY);
            }
            std::cout << *selectedPiece << "\n";
            if ((_isWhiteTurn && selectedPiece->getColor() != 'w') ||(!_isWhiteTurn && selectedPiece->getColor() != 'b')) {
                throw MoveException(MOVE_INVALID_SOURCE_EMPTY);
            }
            _board.movePiece(from, to);

            if (isCheck() == true)
            {
                throw MoveException(MOVE_VALID_CHECK);
            }
            else
            {
                throw MoveException(MOVE_VALID);
            }
        }
        catch (const std::exception& e) 
        {
            std::memset(msgToGraphics, '\0', sizeof(msgToGraphics));
            if (e.what() == MOVE_VALID_STR || e.what() == MOVE_VALID_CHECK_STR)
            {
                bool validateMove(Piece * piece, int x, int y);
                strcpy_s(msgToGraphics, sizeof(msgToGraphics), "0");
                _isWhiteTurn = !_isWhiteTurn;
            }
            strcpy_s(msgToGraphics, e.what());
            msgToGraphics[1] = 0;
            std::cerr << "code:" << e.what() << std::endl;
            _p.sendMessageToGraphics(msgToGraphics);
        }
        std::cout << "\n";
        
        displayBoard();
        msgFromGraphics = _p.getMessageFromGraphics();
    }
}

