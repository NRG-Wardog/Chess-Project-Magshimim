#ifndef MOVE_EXCEPTION_H
#define MOVE_EXCEPTION_H

#include <exception>
#include <string>

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
        case 0:
            return MoveException(code, "Valid move.");
        case 1:
            return MoveException(code, "Valid move. Check caused on the opponent.");
        case 2:
            return MoveException(code, "Invalid move. The source square does not contain the current player's piece.");
        case 3:
            return MoveException(code, "Invalid move. The target square contains the current player's piece.");
        case 4:
            return MoveException(code, "Invalid move. The move would cause a check on the current player.");
        case 5:
            return MoveException(code, "Invalid move. The square indices are not valid.");
        case 6:
            return MoveException(code, "Invalid move. Illegal move for the piece.");
        case 7:
            return MoveException(code, "Invalid move. Source and target squares are identical.");
        case 8:
            return MoveException(code, "Valid move. Checkmate!");
        default:
            return MoveException(-1, "Unknown move error.");
        }
    }
};

#endif // MOVE_EXCEPTION_H
