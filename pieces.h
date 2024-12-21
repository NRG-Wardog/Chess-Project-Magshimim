#ifndef PIECE_H
#define PIECE_H

#include <string>
#include <vector>

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
};


#endif // PIECE_H

