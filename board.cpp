#include "board.h"
#include <stdexcept>

#include "King.h"
#include "Knight.h"
#include "pwn.h"
#include "Queen.h"
#include "Rook.h"

#define START_OF_ABC 'a'
#define START_OF_NUM 1


board::board(const std::string& boardData)
{
    setBoard(boardData);
}

board::~board() {
    for (int row = 0; row < CHESS_SIZE; ++row) {
        for (int col = 0; col < CHESS_SIZE; ++col) {
            delete _board[row][col]; 
        }
    }
}


Piece* (&board::getBoard())[CHESS_SIZE][CHESS_SIZE]
{
    return _board;
}

void board::setBoard(const std::string& boardData)
{
    if (boardData.size() != CHESS_SIZE * CHESS_SIZE)
    {
        throw std::runtime_error("Invalid board data size. Expected 64 characters.");
    }
    char color = 'w';
    for (auto row = 0; row < CHESS_SIZE; ++row)
    {
        for (auto col = 0; col < CHESS_SIZE; ++col)
        {
            std::string pos = std::string(1, START_OF_ABC + col) + std::to_string(row + START_OF_NUM);
	        switch (boardData[row * CHESS_SIZE + col])
	        {
	        case ROOK:
                _board[row][col] = new Rook(color,pos);
                break;
	        case PWN:
                _board[row][col] = new Pwn(color,pos);
                break;
	        case KING:
                _board[row][col] = new King(color, pos);
                break;;
	        case QUEEN:
                _board[row][col] = new Queen(color, pos);
                break;
	        case KNIGHT:
                _board[row][col] = new Knight(color, pos);
                break;
	        case EMPTY:
                _board[row][col] = nullptr;
	        default:
                throw std::runtime_error("Invalid piece character '" + std::string(1, pieceChar) + "' at position: " + pos);
	        }
        }
        color = 'b';
    }
}
