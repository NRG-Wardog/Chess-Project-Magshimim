#ifndef MOVE_EXCEPTION_H
#define MOVE_EXCEPTION_H
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


#define MOVE_VALID_STR "Valid move."
#define MOVE_VALID_CHECK_STR "Valid move. Check caused on the opponent."
#define MOVE_INVALID_SOURCE_EMPTY_STR "Invalid move. The source square does not contain the current player's piece."
#define MOVE_INVALID_TARGET_OCCUPIED_STR "Invalid move. The target square contains the current player's piece."
#define MOVE_INVALID_CAUSES_SELF_CHECK_STR "Invalid move. The move would cause a check on the current player."
#define MOVE_INVALID_OUT_OF_BOUNDS_STR "Invalid move. The square indices are not valid."
#define MOVE_INVALID_ILLEGAL_PIECE_MOVE_STR "Invalid move. Illegal move for the piece."
#define MOVE_INVALID_IDENTICAL_SQUARES_STR "Invalid move. Source and target squares are identical."
#define MOVE_INVALID_TURN_STR "It's not your turn"
#define MOVE_VALID_CHECKMATE_STR "Valid move. Checkmate!"
#define UNKOWN_ERROR "Unknown move error."



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
            return MOVE_VALID_STR;
        case MOVE_VALID_CHECK:
            return MOVE_VALID_CHECK_STR;
        case MOVE_INVALID_SOURCE_EMPTY:
            return MOVE_INVALID_SOURCE_EMPTY_STR;
        case MOVE_INVALID_TARGET_OCCUPIED:
            return MOVE_INVALID_TARGET_OCCUPIED_STR;
        case MOVE_INVALID_CAUSES_SELF_CHECK:
            return MOVE_INVALID_CAUSES_SELF_CHECK_STR;
        case MOVE_INVALID_OUT_OF_BOUNDS:
            return MOVE_INVALID_OUT_OF_BOUNDS_STR;
        case MOVE_INVALID_ILLEGAL_PIECE_MOVE:
            return MOVE_INVALID_ILLEGAL_PIECE_MOVE_STR;
        case MOVE_INVALID_IDENTICAL_SQUARES:
            return MOVE_INVALID_IDENTICAL_SQUARES_STR;
        case MOVE_INVALID_TURN:
            return MOVE_INVALID_TURN_STR;
        case MOVE_VALID_CHECKMATE:
            return MOVE_VALID_CHECKMATE_STR;
        default:
            return UNKOWN_ERROR;
        }
    }
};

#endif // MOVE_EXCEPTION_H
