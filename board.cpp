#include "Board.h"
#include <cctype>
#include <stdexcept>

#include "King.h"
#include "Knight.h"
#include "Pwn.h"
#include "Queen.h"
#include "Rook.h"

#define START_OF_ABC 'a'
#define START_OF_NUM 1
#define WHITE 'w'
#define BLACK 'b'

Board::Board(const std::string& boardData)
{
    setBoard(boardData);
}

Board::~Board() {
    for (int row = 0; row < CHESS_SIZE; ++row) {
        for (int col = 0; col < CHESS_SIZE; ++col) {
            delete _board[row][col]; 
        }
    }
}


Piece* const (&Board::getBoard() const)[CHESS_SIZE][CHESS_SIZE]{
    return _board;
}


Piece* Board::getSymbol(std::string& pos) const
{
    if (pos.size() != 2 || pos[0] < 'a' || pos[0] > 'h' || pos[1] < '1' || pos[1] > '8') {
        throw std::runtime_error("Invalid chessboard position format.");
    }
    auto col = pos[0] - START_OF_ABC;
    auto row = pos[1] - '1';
    return _board[col][row];
}

void Board::setBoard(const std::string& boardData)
{
    if (boardData.size() != CHESS_SIZE * CHESS_SIZE)
    {
        throw std::runtime_error("Invalid board data size. Expected 64 characters.");
    }
    for (auto row = 0; row < CHESS_SIZE; ++row)
    {
        for (auto col = 0; col < CHESS_SIZE; ++col)
        {
            std::string pos = std::string(1, START_OF_ABC + col) + std::to_string(row + START_OF_NUM);
            char pieceChar = boardData[row * CHESS_SIZE + col];
            char color = WHITE;
            if (std::isupper(pieceChar))
            {
                color = BLACK;
            }
	        switch (std::tolower(pieceChar))
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
    }
}
