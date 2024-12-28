#ifndef PIECE_H
#define PIECE_H

#include <string>

#define START_OF_BOARD 'a'
#define START_OF_NUM 1
#define CHESS_SIZE 8
#define CHESS_SIZE_AS_CHAR '8'
#define START_OF_NUM_AS_CHAR '1'
#define START_OF_NUM_BOARD '0'
#define END_OF_NUM_BOARD '9'
#define CHESS_END_OF_BOARD 'h'
#define ROW 0
#define COL 1




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

