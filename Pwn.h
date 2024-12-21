#ifndef PWN_H
#define PWN_H

#include <stdexcept>

#include "pieces.h"

class Pwn : public Piece {
public:
    Pwn(char col, const std::string& pos);

    void move(const std::string& newPosition) override;

    bool canMove(const std::string& newPosition) const override;
};

#endif // PWN_H
