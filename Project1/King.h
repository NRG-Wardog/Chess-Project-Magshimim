#ifndef KING_H
#define KING_H

#include <stdexcept>

#include "board.h"
#include "Piece.h"

class King : public Piece {
public:
    King(char col, const std::string& pos);

    void move(const std::string& newPosition) override;
    bool isAttacked(const Board& currentBoard);
    bool canMove(const std::string& newPosition) const override;
    std::string getType() const override;

};

#endif // KING_H
