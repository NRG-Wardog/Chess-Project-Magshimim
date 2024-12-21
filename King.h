#ifndef KING_H
#define KING_H

#include <stdexcept>

#include "Board.h"
#include "pieces.h"

class King : public Piece {
public:
    King(char col, const std::string& pos);

    void move(const std::string& newPosition) override;
    bool isAttacked(const Board& currentBoard);
    bool canMove(const std::string& newPosition) const override;
    std::string getType() const override { return std::string("King"); }

};

#endif // KING_H
