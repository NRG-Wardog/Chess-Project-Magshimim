#pragma once
#include <string>
#include <iostream>

class Exceptions {
private:
    std::string _exception; 
    bool _leadsToMate;    

public:
    
    Exceptions();

   
    Exceptions(const std::string& ex, bool mate);


    
    void handleException() const;

   
    std::string getExceptionMessage() const;

};
