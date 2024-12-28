#include "Manager.h"
#include "Board.h"
#include "Piece.h"
#include <iostream>

#include "MoveException.h"
#define START_OF_BOARD 'a'
#define START_OF_NUM 1


Manager::Manager() : _isWhiteTurn(true) 
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

void Manager::resetGame()
{
    std::string _chessboard = "rnbqkbnrpppppppp############################PPPPPPPPRNBQKBNR"; // like startgame in mangager


    Board _chess = Board(_chessboard);
    gameLoop(_chess);
}

bool Manager::isGameOver()
{
    //return king.isAttacked() && !king.canMove();
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

void Manager::gameLoop(Board& board)
{
    char msgToGraphics[1024];

    std::string msgFromGraphics = _p.getMessageFromGraphics();

    while (isGameOver() == false && msgFromGraphics != "quit")
    {
        try {
            std::cout << msgFromGraphics;
            std::string from = msgFromGraphics;
            std::string to = msgFromGraphics;

            Piece* selectedPiece = board.getSymbol(from);
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

            board.movePiece(from, to);

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

            std::cerr << e.what() << std::endl;
            
        }
        
        
    }
}

