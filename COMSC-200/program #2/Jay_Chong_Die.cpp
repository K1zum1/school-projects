#include "Jay_Chong_Die.h"
#include <cstdlib> 
#include <ctime> 

// comment #4: this is the constructor for the Die class, which takes in the number of sides on the die, and then calls the roll function to generate a random value
Die::Die(int numSides) {
    srand(time(0));
    this->sides = numSides;
    roll(); 
}
// comment #5: this is also a constructor, it sets the number of sides to the value passed as an argument and performs an initial roll of the die.
void Die::setSides(int numSides) {
    this->sides = numSides;
    roll(); }

void Die::roll() {
    this->value = rand() % sides + 1; 
}

// comment #6: this is an accessor function, which allows the value/side of the die to be accessed

int Die::getSides() const {
    return sides; 
}

int Die::getValue() const {
    return value; 
}
