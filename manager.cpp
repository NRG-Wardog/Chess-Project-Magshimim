#include "manager.h";
#include <iostream>
#define START_OF_ABC 'a'
#define START_OF_NUM 1


Manager::Manager() : isWhiteTurn(true)
{}

Manager::~Manager() {}

void startGame()
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
        while (true)
        {




        }
    }
	catch (const std::exception& e) 
    {
        std::cerr << "Error initializing the game: " << e.what() << std::endl;
    }
}
bool validateMove(Board board, int x, int y)
{
  //return canMove();
    return true;
}
void movePiece(Board board, int x, int y)
{

    //move(int x, int y);
}
bool isCheck()
{
    return false;
  //return isAttacked();
}
void resetGame()
{
  startGame();
}
//bool isGameOver()


void displayBoard(Board _chessBoard)
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
