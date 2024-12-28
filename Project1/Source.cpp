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
    Manager man;
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
        std::string chessboard = "rnbqkbnrpppppppp################################PPPPPPPPRNBQKBNR"; // like startgame in mangager

        // Initialize the board

        Board board = Board(chessboard);
     
        man.gameLoop(board);
        strcpy_s(msgToGraphics, board.toString().c_str()); // Convert board to string

        // TODO: decide if we need it here or in Manager

        //p.sendMessageToGraphics(msgToGraphics); // Send the board string

        //string msgFromGraphics = p.getMessageFromGraphics();
        //while (msgFromGraphics != "quit") {
        //    // Parse and execute move
        //    try {
        //        std::string from = msgFromGraphics.substr(0, 2);
        //        std::string to = msgFromGraphics.substr(2, 2);
        //        board.movePiece(from, to);
        //        strcpy_s(msgToGraphics, "1"); // Success
        //    }
        //    catch (const std::exception& e) {
        //        bool validateMove(Piece* piece, int x, int y);
        //        strcpy_s(msgToGraphics, sizeof(msgToGraphics), "0");
        //        std::cerr << "Error handling move: " << e.what() << std::endl;
        //    }

        //    p.sendMessageToGraphics(msgToGraphics); // Send result back to graphics
        //    msgFromGraphics = p.getMessageFromGraphics(); // Get next message
        //}
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
