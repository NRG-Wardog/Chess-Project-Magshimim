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
    std::string msgFromGraphics = pipe.getMessageFromGraphics();

    while (isGameOver() == false && msgFromGraphics != "quit")
    {
        try {
            std::string from = msgFromGraphics.substr(0, 2);
            std::string to = msgFromGraphics.substr(2, 2);

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
                try {
                    // Simulate throwing the exception
                    throw MoveException(MOVE_INVALID_ILLEGAL_PIECE_MOVE);
                }
                catch (const MoveException& e) {
                    // Catch the exception and print its message
                    std::cerr << "Exception caught: " << e.what() << std::endl;
                }
            }

            board.movePiece(from, to);

            if (isCheck() == true)
            {
                try {
                  
                    throw MoveException(MOVE_VALID_CHECK);
                }
                catch (const MoveException& e) {
                  
                    std::cerr << "Exception caught: " << e.what() << std::endl;
                }
            }
        }
        catch (const std::exception& e) {
            bool validateMove(Piece * piece, int x, int y);
            strcpy_s(msgToGraphics, sizeof(msgToGraphics), "0");
            std::cerr << "Error handling move: " << e.what() << std::endl;
        }
        
        
    }
}

