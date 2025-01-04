#include "Manager.h"
#include "Board.h"
#include "Piece.h"
#include <iostream>
#include "MoveException.h"

#define START_OF_BOARD 'a'
#define START_OF_NUM 1
#define WHITE_MOVE '0'
#define ENTER '\n'
#define END '\0'
#define KING "King"
#define OVER "quit"


//C'tor
//checks if the last char is for white to play
Manager::Manager(Pipe p,std::string chess) : _p(p),_board(chess)
{
    _isWhiteTurn = chess[CHESS_BOARD_SIZE] == WHITE_MOVE;
}
//d'tor
Manager::~Manager() {}

/*
Validates the move.
Input: Piece pointer piece, string reference newPosition.
Output: true or false
*/
//bool Manager::validateMove(Piece* piece, std::string& newPosition)
//{
//    return piece->canMove(newPosition);
//}

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
    char kingColor = turn ? WHITE : BLACK;
    bool isAtk = false;
    bool flag = true;//didnt find king
    int row = 0, col = 0;
    // Find the king's position
    std::string kingPosition ="";
    for (row = 0; row < CHESS_SIZE &&flag; ++row) 
    {
        for (col = 0; col < CHESS_SIZE&&flag; ++col)
        {
            Piece* piece = _board.getBoard()[row][col];
            if (piece != nullptr && piece->getType() == KING && piece->getColor() == kingColor) {
                kingPosition = std::string(1, START_OF_BOARD + col) + std::to_string(row + START_OF_NUM);
                flag = false;;
            }
        }
    }
    //if not found that mean he got eat
    if (flag) {
        throw MoveException(MOVE_VALID_CHECKMATE);
    }

    // Check if any opponent's piece can move to the king's position
    for (row = 0; row < CHESS_SIZE; ++row) {
        for (col = 0; col < CHESS_SIZE; ++col) {
            Piece* piece = _board.getBoard()[row][col];
            if (piece != nullptr && piece->getColor() != kingColor) {
                std::string opponentPiecePosition = std::string(1, START_OF_BOARD + col) + std::to_string(row + START_OF_NUM);
                try
                {
                    if (piece->canMove(kingPosition) && _board.isPathClear(row, col, kingPosition[COL] - START_OF_NUM_AS_CHAR, kingPosition[ROW] - START_OF_BOARD, piece->getType()))
                    {
                        isAtk=true; // The king is under attack
                    }
                }
                catch(...)// just becuse it may sent error mesage from canMove or isPathClear
                {
                    continue;
                }
            }
        }
    }

    return isAtk; // The king is not under attack
}

/*
Creates the board.
Input: string reference strBoard.
Output: none
*/
Board Manager::createBoard(std::string& strBoard)
{
    if (strBoard.size() != CHESS_BOARD_SIZE +1 ) { throw std::runtime_error("size of board invalid."); }
    _isWhiteTurn = strBoard[CHESS_BOARD_SIZE] == WHITE_TURN;
    _board = Board(strBoard);
    return _board;
}

/*
* func reset game board
* input:none
* output:none
*/
void Manager::resetGame()
{
    std::string _chessboard = BOARD_LETTERS; // like startgame in mangager
    gameLoop(_chessboard);
}

/*
* func check if game ended annd return true or false
* input:none
* output:bool true or false -- for now its false because it bouns
*/
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
    char msgToGraphics[BUFFER_SIZE];
    strcpy_s(msgToGraphics, _board.toString().c_str()); 
    _p.sendMessageToGraphics(msgToGraphics);
    displayBoard();
    std::string msgFromGraphics = _p.getMessageFromGraphics();
    
    while (isGameOver() == false && msgFromGraphics != OVER)
    {
        try {
            std::string from = msgFromGraphics.substr(0,2);
            std::string to = msgFromGraphics.substr(2, 4);
            std::cout << from << "," << to << ENTER;
            
            if (from == to)
            {
                throw MoveException(MOVE_INVALID_IDENTICAL_SQUARES);
            }
            Piece* selectedPiece = _board.getSymbol(from);
            if (selectedPiece == nullptr) 
            {
                throw MoveException(MOVE_INVALID_SOURCE_EMPTY);
            }
            std::cout << *selectedPiece << ENTER;
            if ((_isWhiteTurn && selectedPiece->getColor() != WHITE) ||(!_isWhiteTurn && selectedPiece->getColor() != BLACK)) {
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
            std::memset(msgToGraphics, END, sizeof(msgToGraphics));
            if (e.what() == MOVE_VALID_STR || e.what() == MOVE_VALID_CHECK_STR)
            {
                strcpy_s(msgToGraphics, sizeof(msgToGraphics), "0");
                _isWhiteTurn = !_isWhiteTurn;
            }
            strcpy_s(msgToGraphics, e.what());
            msgToGraphics[COL] = 0;
            std::cerr << "code:" << e.what() << std::endl;
            _p.sendMessageToGraphics(msgToGraphics);
        }
        std::cout << ENTER;
        
        displayBoard();
        msgFromGraphics = _p.getMessageFromGraphics();
    }
}

