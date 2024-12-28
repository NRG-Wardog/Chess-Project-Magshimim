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


#define MOVE_VALID_STR "0"
#define MOVE_VALID_CHECK_STR "1"
#define MOVE_INVALID_SOURCE_EMPTY_STR "2"
#define MOVE_INVALID_TARGET_OCCUPIED_STR "3"
#define MOVE_INVALID_CAUSES_SELF_CHECK_STR "4"
#define MOVE_INVALID_OUT_OF_BOUNDS_STR "5"
#define MOVE_INVALID_ILLEGAL_PIECE_MOVE_STR "6"
#define MOVE_INVALID_IDENTICAL_SQUARES_STR "7"
#define MOVE_INVALID_TURN_STR "8"
#define MOVE_VALID_CHECKMATE_STR "9"
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
