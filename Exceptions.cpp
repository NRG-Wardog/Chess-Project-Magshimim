#include "Exceptions.h"
#include "pieces.h"
#include <string>
#include <iostream>
#include "Pwn.h"

Exceptions()
{

};





void handleException()
{
    try {
      throw Exceptions("Invalid move", true);
  } catch (const Exceptions& ex) {
      ex.handleException();
  }
}


void Pwn::move(int toX, int toY) {
    if (!canMove(toX, toY)) {
        throw Exception("Invalid pawn move!");
    }
   
    if (std::abs(toX - getX()) == 2 && hasMoved) {
        throw Exception("Pawn cannot move two squares after its first move.");
    }
  
    setPosition(toX, toY);
    hasMoved = true;
}





std::string getExceptionMessage()
{
  return "Chess exception";
}