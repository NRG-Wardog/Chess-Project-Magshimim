#ifndef MOVE_EXCEPTION_H
#define MOVE_EXCEPTION_H

#include <exception>
#include <string>

#define MOVE_VALID 0                      // 0 – Valid move
#define MOVE_VALID_CHECK 1                // 1 – Valid move, caused a check on the opponent
#define MOVE_INVALID_SOURCE_EMPTY 2       // 2 – Invalid move, source square does not contain the current player's piece
#define MOVE_INVALID_TARGET_OCCUPIED 3    // 3 – Invalid move, target square is occupied by the current player's piece
#define MOVE_INVALID_CAUSES_SELF_CHECK 4  // 4 – Invalid move, would cause a check on the current player
#define MOVE_INVALID_OUT_OF_BOUNDS 5      // 5 – Invalid move, indices of the squares are not valid
#define MOVE_INVALID_ILLEGAL_PIECE_MOVE 6 // 6 – Invalid move, illegal move for the piece
#define MOVE_INVALID_IDENTICAL_SQUARES 7  // 7 – Invalid move, source and target squares are identical
#define MOVE_VALID_CHECKMATE 8            // 8 – Valid move, caused checkmate




class MoveException : public std::exception
{
private:
    int errorCode;        // Code for the specific error
    std::string message;  // Error message description

public:
    // Constructor
    MoveException(int code, const std::string& msg): errorCode(code),message(msg)
    {
        createException(errorCode);
    }

    // Get the error code
    int getErrorCode() const {
        return errorCode;
    }

    // Override the what() method to provide an error message
    const char* what() const noexcept override {
        return message.c_str();
    }

    // Static method to create exceptions based on predefined cases
    static MoveException createException(int code) {
        switch (code) {
        case MOVE_VALID:
            return MoveException(code, "Valid move.");
        case MOVE_VALID_CHECK:
            return MoveException(code, "Valid move. Check caused on the opponent.");
        case MOVE_INVALID_SOURCE_EMPTY:
            return MoveException(code, "Invalid move. The source square does not contain the current player's piece.");
        case MOVE_INVALID_TARGET_OCCUPIED:
            return MoveException(code, "Invalid move. The target square contains the current player's piece.");
        case MOVE_INVALID_CAUSES_SELF_CHECK:
            return MoveException(code, "Invalid move. The move would cause a check on the current player.");
        case MOVE_INVALID_OUT_OF_BOUNDS:
            return MoveException(code, "Invalid move. The square indices are not valid.");
        case MOVE_INVALID_ILLEGAL_PIECE_MOVE:
            return MoveException(code, "Invalid move. Illegal move for the piece.");
        case MOVE_INVALID_IDENTICAL_SQUARES:
            return MoveException(code, "Invalid move. Source and target squares are identical.");
        case MOVE_VALID_CHECKMATE:
            return MoveException(code, "Valid move. Checkmate!");
        default:
            return MoveException(-1, "Unknown move error.");
        }
    }
};

#endif // MOVE_EXCEPTION_H
