#include "manager.h"
#include "board.h"
#include "pieces.h"
#include <iostream>
#define START_OF_ABC 'a'
#define START_OF_NUM 1


Manager::Manager() : isWhiteTurn(true)
{

}

Manager::~Manager() {}

void Manager::startGame()
{
    try {

        std::string initialBoard =
            "RNBQKBNR"
            "PPPPPPPP"
            "........"
            "........"
            "........"
            "........"
            "pppppppp"
            "rnbqkbnr";

        Board chessBoard(initialBoard);
    }
    catch (const std::exception& e)
    {
        std::cerr << "Error initializing the game: " << e.what() << std::endl;
    }
}

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
    return king.isAttacked();
}

void Manager::resetGame()
{
    startGame();
}

bool Manager::isGameOver()
{
    return king.isAttacked() && !king.canMove();
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

void Manager::gameLoop()
{
    startGame();
    while (isGameOver() = false)
    {
        Piece* selectedPiece = board.getSymbol();
        if (selectedPiece == nullptr) {
            throw std::invalid_argument("No piece at the selected position");
        }

        if ((isWhiteTurn && selectedPiece->getColor() != 'w') ||
            (!isWhiteTurn && selectedPiece->getColor() != 'b')) {
            throw std::invalid_argument("It's not your turn");
        }

        string msgFromGraphics = pipe.getMessageFromGraphics();
        std::string newPosition = msgFromGraphics.substr(2, 2);
        if (!validateMove(selectedPiece, newPosition)) {
            throw std::invalid_argument("Invalid move for the selected piece");
        }
        
        movePiece(selectedPiece, newPosition);
        board.getBoard() // [][] = selectedPiece;
        // board.getBoard() //[][] = nullptr;

        if (isCheck() == true)
        {
            //  only king can move
        }
        
    }
}

