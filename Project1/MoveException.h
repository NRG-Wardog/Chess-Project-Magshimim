#ifndef MOVE_EXCEPTION_H
#define MOVE_EXCEPTION_H
#include "MoveStatus.h"
#include <exception>
#include <string>


enum Status {
    MOVE_VALID,
    MOVE_VALID_CHECK,
    MOVE_INVALID_SOURCE_EMPTY,
    MOVE_INVALID_TARGET_OCCUPIED,
    MOVE_INVALID_CAUSES_SELF_CHECK,
    MOVE_INVALID_OUT_OF_BOUNDS,
    MOVE_INVALID_ILLEGAL_PIECE_MOVE,
    MOVE_INVALID_IDENTICAL_SQUARES,
    MOVE_INVALID_TURN,
    MOVE_VALID_CHECKMATE,
};

class MoveException : public std::exception
{
private:
    Status _errorCode;        // Code for the specific error
   

public:
    // Constructor
    MoveException(Status code): _errorCode(code)
    {}

    // Get the error code
    Status getErrorCode() const {
        return _errorCode;
    }

    // Override the what() method to provide an error message
    const char* what() const noexcept override {
        switch (_errorCode) {
        case MOVE_VALID:
            return "Valid move.";
        case MOVE_VALID_CHECK:
            return "Valid move. Check caused on the opponent.";
        case MOVE_INVALID_SOURCE_EMPTY:
            return "Invalid move. The source square does not contain the current player's piece.";
        case MOVE_INVALID_TARGET_OCCUPIED:
            return "Invalid move. The target square contains the current player's piece.";
        case MOVE_INVALID_CAUSES_SELF_CHECK:
            return "Invalid move. The move would cause a check on the current player.";
        case MOVE_INVALID_OUT_OF_BOUNDS:
            return "Invalid move. The square indices are not valid.";
        case MOVE_INVALID_ILLEGAL_PIECE_MOVE:
            return "Invalid move. Illegal move for the piece.";
        case MOVE_INVALID_IDENTICAL_SQUARES:
            return "Invalid move. Source and target squares are identical.";
        case MOVE_INVALID_TURN:
            return "It's not your turn";
        case MOVE_VALID_CHECKMATE:
            return "Valid move. Checkmate!";
        default:
            return "Unknown move error.";
        }
    }
};

#endif // MOVE_EXCEPTION_H
