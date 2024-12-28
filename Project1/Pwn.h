#ifndef PWN_H
#define PWN_H

#include <stdexcept>

#include "Piece.h"

class Pwn : public Piece {
public:
    Pwn(char col, const std::string& pos);

    void move(const std::string& newPosition) override;

    bool canMove(const std::string& newPosition) const override;
    std::string getType() const override { return std::string("Pwn"); }

private:
    bool _firstMove;

};

#endif // PWN_H
