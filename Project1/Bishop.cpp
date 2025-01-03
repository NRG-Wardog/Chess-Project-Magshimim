#include "Bishop.h"
#include "MoveException.h"
#include <cmath> 

#define TYPO "Bishop"

//CTOR
Bishop::Bishop(char color, const std::string& position) : Piece(color, position)
{
}

/*
* func check if the bishop do legal move
* input:pos string
* output:return true or false can/t
*/
bool Bishop::canMove(const std::string& newPosition) const
{
    int currentRow = _position[COL] - START_OF_NUM_BOARD;
    int currentCol = _position[ROW] - START_OF_BOARD;
    int newRow = newPosition[COL] - START_OF_NUM_BOARD;
    int newCol = newPosition[ROW] - START_OF_BOARD;

    // Check for valid indices
    if (currentRow < ROW || currentRow > CHESS_SIZE || currentCol < 0 || currentCol >= CHESS_SIZE ||
        newRow < ROW || newRow > CHESS_SIZE || newCol < 0 || newCol >= CHESS_SIZE) {
        throw MoveException(MOVE_INVALID_OUT_OF_BOUNDS); 
    }

    // Check if the move is diagonal
    if (std::abs(newRow - currentRow) != std::abs(newCol - currentCol)) {
        throw MoveException(MOVE_INVALID_ILLEGAL_PIECE_MOVE); 
    }

    return true;
}

/*
* func check if can move and move it if so
* intput:string new pos
* output:none
*/
void Bishop::move(const std::string& newPosition)
{
    if (!canMove(newPosition)) {
        throw MoveException(MOVE_INVALID_ILLEGAL_PIECE_MOVE); // Illegal move for the piece
    }
    setPosition(newPosition);
}

/*
* func return type
* input:none
* output:return string type
 */
std::string Bishop::getType() const
{
    return TYPO;
}
