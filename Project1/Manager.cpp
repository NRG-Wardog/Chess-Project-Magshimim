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

/*
func check if the wanted turn is check
input:how turn is that
output:true or false
*/
bool Manager::isCheck(bool turn)
{
    char kingColor = turn ? 'w' : 'b';
    // Find the king's position
    std::string kingPosition;
    for (int row = 0; row < CHESS_SIZE; ++row) 
    {
        for (int col = 0; col < CHESS_SIZE; ++col) 
        {
            Piece* piece = _board.getBoard()[row][col];
            if (piece != nullptr && piece->getType() == "King" && piece->getColor() == kingColor) {
                kingPosition = std::string(1, START_OF_BOARD + col) + std::to_string(row + START_OF_NUM);
                break;
            }
        }
    }

    if (kingPosition.empty()) {
        throw std::runtime_error("King not found on the board!");
    }

    // Check if any opponent's piece can move to the king's position
    for (int row = 0; row < CHESS_SIZE; ++row) {
        for (int col = 0; col < CHESS_SIZE; ++col) {
            Piece* piece = _board.getBoard()[row][col];
            if (piece != nullptr && piece->getColor() != kingColor) {
                std::string opponentPiecePosition = std::string(1, START_OF_BOARD + col) + std::to_string(row + START_OF_NUM);
                try
                {
                    if (piece->canMove(kingPosition) && _board.isPathClear(row, col, kingPosition[1] - '1', kingPosition[0] - 'a', piece->getType()))
                    {
                        return true; // The king is under attack
                    }
                }
                catch(...)
                {
                    continue;
                }
            }
        }
    }

    return false; // The king is not under attack
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
            
            _board.movePiece(from, to,false);
            if (isCheck(_isWhiteTurn))
            {
                _board.movePiece(to, from, true);
                throw MoveException(MOVE_INVALID_CAUSES_SELF_CHECK);
            }
            
            if (isCheck(!_isWhiteTurn) == true)
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

