#ifndef ROOK_H
#define ROOK_H

#include <stdexcept>

#include "pieces.h"

class Rook : public Piece {
public:
    Rook(char col, const std::string& pos);

    void move(const std::string& newPosition) override;

    bool canMove(const std::string& newPosition) const override;
};

#endif // ROOK_H
