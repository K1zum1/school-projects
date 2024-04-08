#ifndef CARD_H
#define CARD_H

#include <string>
using namespace std;

// comment #6 : this is the Card class definition
class Card {
public:
    Card(int face, int suit); 
    string toString() const;

    static const string faces[13];
    static const string suits[4]; 
// comment #7 : these are the private data members of the Card class
private:
    int face;
    int suit;
};

#endif
