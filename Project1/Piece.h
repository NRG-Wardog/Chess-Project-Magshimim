#ifndef PIECE_H
#define PIECE_H

#include <string>

#define START_OF_ABC 'a'
#define START_OF_NUM 1
#define CHESS_SIZE 8
#define CHESS_SIZE_AS_CHAR '8'
#define START_OF_NUM_AS_CHAR '1'
#define CHESS_LETTER 'h'
#define ROW 0
#define COL 1

#define MOVE_VALID 0                      // 0 – Valid move
#define MOVE_VALID_CHECK 1                // 1 – Valid move, caused a check on the opponent
#define MOVE_INVALID_SOURCE_EMPTY 2       // 2 – Invalid move, source square does not contain the current player's piece
#define MOVE_INVALID_TARGET_OCCUPIED 3    // 3 – Invalid move, target square is occupied by the current player's piece
#define MOVE_INVALID_CAUSES_SELF_CHECK 4  // 4 – Invalid move, would cause a check on the current player
#define MOVE_INVALID_OUT_OF_BOUNDS 5      // 5 – Invalid move, indices of the squares are not valid
#define MOVE_INVALID_ILLEGAL_PIECE_MOVE 6 // 6 – Invalid move, illegal move for the piece
#define MOVE_INVALID_IDENTICAL_SQUARES 7  // 7 – Invalid move, source and target squares are identical
#define MOVE_VALID_CHECKMATE 8            // 8 – Valid move, caused checkmate



class Piece {
protected:
	std::string _position; 
    char _color;       

public:
    Piece(char col, const std::string &pos);
    virtual ~Piece() = default;

    
    std::string getPosition() const ;
    char getColor() const;

  
    void setPosition(const std::string &pos);
   
    virtual void move(const std::string &newPosition) = 0;
    virtual bool canMove(const std::string &newPosition) const = 0;
    virtual std::string getType() const = 0;

    friend std::ostream& operator<<(std::ostream& os, const Piece& piece);

};


#endif // PIECE_H

