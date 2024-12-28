#include "Manager.h"
#include "Board.h"
#include "Piece.h"
#include <iostream>

#include "MoveException.h"
#define START_OF_BOARD 'a'
#define START_OF_NUM 1


Manager::Manager(Pipe p) : _isWhiteTurn(true), _board(),_p(p)
{}

Manager::~Manager() {}



bool Manager::validateMove(Piece* piece, std::string& newPosition)
{
    return piece->canMove(newPosition);
}

void Manager::movePiece(Piece* piece, std::string& newPosition)
{
    piece->move(newPosition);
}

bool Manager::isCheck()
{
    //return king.isAttacked();
    return false;
}

void Manager::createBoard(std::string& strBoard)
{
    if (strBoard.size() < 65) { throw std::runtime_error("size of board invalid."); }
    std::string boardStrFixed = strBoard.substr(0, 64);
    _isWhiteTurn = strBoard[64] == WHITE_TURN;
    _board = Board(boardStrFixed);
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

void Manager::displayBoard(Board _chessBoard)
{
  auto& chess = _chessBoard.getBoard(); 

  std::cout << "  a b c d e f g h" << std::endl; 
  for (int row = CHESS_SIZE - 1; row >= 0; --row)
  {
      std::cout << row + 1 << " ";
      for (int col = 0; col < CHESS_SIZE; ++col)
      {
          if (chess[row][col] != nullptr) {
              std::cout << chess[row][col] << " ";
          }
          else {
              std::cout << ". ";
          }
      }
      std::cout << row + 1 << std::endl;
  }
}

void Manager::gameLoop(std::string strBoard)
{
    char msgToGraphics[1024];
    //createBoard(strBoard);
    //strcpy_s(msgToGraphics, strBoard.c_str());
    //_p.sendMessageToGraphics(msgToGraphics);
    //std::string msgFromGraphics = _p.getMessageFromGraphics();
    strcpy_s(msgToGraphics, "rnbkqbnrpppppppp################################PPPPPPPPRNBKQBNR0"); // just example...

    _p.sendMessageToGraphics(msgToGraphics);
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

