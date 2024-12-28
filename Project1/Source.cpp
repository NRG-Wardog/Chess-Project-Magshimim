#include "Pipe.h"
#include "Board.h"
#include "Manager.h"
#include "Piece.h"
#include <iostream>
#include <thread>
#include <string>
#include <chrono>
#include <stdexcept>

#include "MoveException.h"

using std::cout;
using std::endl;
using std::string;

int main() {
    srand(time_t(NULL));
    Pipe p;
    bool isConnect = p.connect();
    Manager man(p);
    string ans;
    while (!isConnect) {
        cout << "Can't connect to graphics" << endl;
        cout << "Do you want to try again or exit? (0-try again, 1-exit)" << endl;
        std::cin >> ans;

        if (ans == "0") {
            cout << "Trying to connect again..." << endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(5000));
            isConnect = p.connect();
        }
        else {
            p.close();
            return 0;
        }
    }



    try {
        char msgToGraphics[1024];
        std::string strBoard = "rnbkqbnrpppppppp################################PPPPPPPPRNBKQBNR1";
        std::cout << "Size of chessboard: " << strBoard.size() << std::endl;
        // Initialize the board

        
        man.gameLoop(strBoard);
         // Convert board to string
    }
    catch (const MoveException& e) {
        std::cerr << "Error " << e.getErrorCode() << ": " << e.what() << std::endl;
    }
    catch (std::exception& e) {
        std::cerr << "An error occurred: " << e.what() << std::endl;
    }
    p.close();

    return 0;
}
