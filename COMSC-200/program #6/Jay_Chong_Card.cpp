#include "Jay_Chong_Card.h"

// comment #3 : this is the definition of the faces and suits arrays
const string Card::faces[13] = {"Ace", "Deuce", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};
const string Card::suits[4] = {"Hearts", "Diamonds", "Clubs", "Spades"};

// comment #4 : this is the constructor for the Card class
Card::Card(int face, int suit) : face(face), suit(suit) {}

// comment #5 : this function will return a string representation of the card
string Card::toString() const {
    return faces[face] + " of " + suits[suit];
}
