#ifndef KING_H
#define KING_H

#include <stdexcept>

#include "pieces.h"

class King : public Piece {
public:
    King(char col, const std::string& pos);

    void move(const std::string& newPosition) override;

    bool canMove(const std::string& newPosition) const override;
};

#endif // KING_H
