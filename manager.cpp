#include "manager.h";
#include "board.h";
#include <iostream>



Manager::Manager() : isWhiteTurn(true) {
    board.resize(8, std::vector<Piece*>(8, nullptr));
}

Manager::~Manager() {

    for (auto& row : board) {
        for (auto& piece : row) {
            delete piece;
        }
    }
}

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

        board chessBoard(initialBoard);

     
        auto& chess = chessBoard.getBoard();
        std::cout << "Initial Board Setup:" << std::endl;
        for (int row = 0; row < CHESS_SIZE; ++row) {
            for (int col = 0; col < CHESS_SIZE; ++col) {
                if (chess[row][col] != nullptr) {
                    std::cout << chess[row][col]->getSymbol() << " ";
                } else {
                    std::cout << ". ";
                }
            }
            std::cout << std::endl;
        }
    } catch (const std::exception& e) {
        std::cerr << "Error initializing the game: " << e.what() << std::endl;
    }
}
bool validateMove(Pieces* piece, int x, int y)
{
  return canMove();
}
void movePiece(Piece* piece, int x, int y)
{
  move(int x, int y);
}
bool isCheck()
{
  return isAttacked();
}
void resetGame()
{
  void startGame();
}
//bool isGameOver()


void displayBoard()
{ 
  auto& chess = _chessBoard.getBoard(); 

  std::cout << "  a b c d e f g h" << std::endl; 
  for (int row = CHESS_SIZE - 1; row >= 0; --row) { 
      std::cout << row + 1 << " "; 
      for (int col = 0; col < CHESS_SIZE; ++col) {
          if (chess[row][col] != nullptr) {
              std::cout << chess[row][col]->getSymbol() << " "; 
          } else {
              std::cout << ". "; 
          }
      }
      std::cout << row + 1 << std::endl; 
}
