#ifndef COIN_H
#define COIN_H

#include <string>

using namespace std;

// comment #1 these are my data members that are not accessible to the user outside of the class
class Coin {
private:
    string sideUp;

// comment #2 these are my member functions that are accessible to the user outside of the class
public:
    Coin(); 
    void toss(); 
    string getSideUp() const; // comment #3 this is an accessor function, which allows the user to see the value of the data member sideUp
};

#endif
