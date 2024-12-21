#ifndef QUEEN_H
#define QUEEN_H

#include <stdexcept>

#include "pieces.h"

class Queen : public Piece {
public:
    Queen(char col, const std::string& pos);

    void move(const std::string& newPosition) override;

    bool canMove(const std::string& newPosition) const override;
};

#endif // QUEEN_H
