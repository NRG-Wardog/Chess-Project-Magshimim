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

#define BOARD_LETTERS "rnbkqbnrpppppppp################################PPPPPPPPRNBKQBNR0"
#define UNCONCTION "0"
#define WAIT_TIME 5000
#define BUFFER_SIZE 1024

using std::cout;
using std::endl;
using std::string;

int main() {
    srand(time_t(NULL));
    Pipe p;
    bool isConnect = p.connect();
    char msgToGraphics[BUFFER_SIZE];
    string ans;
    std::string strBoard = BOARD_LETTERS;
    while (!isConnect) 
    {
        cout << "Can't connect to graphics" << endl;
        cout << "Do you want to try again or exit? (0-try again, 1-exit)" << endl;
        std::cin >> ans;

        if (ans == UNCONCTION)
        {
            cout << "Trying to connect again..." << endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(WAIT_TIME));
            isConnect = p.connect();
        }
        else 
        {
            p.close();
            return 0;
        }
    }
    try
    {
        std::cout << "Size of chessboard: " << strBoard.size() << std::endl;
        // Initialize the board
        Manager man(p,strBoard);
        man.gameLoop(strBoard);
    }
    catch (std::exception& e) 
    {
        std::cerr << e.what() << std::endl;
    }
    p.close();

    return 0;
}
