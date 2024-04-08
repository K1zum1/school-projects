// comment 14: include guards as requsted by the assignment
#ifndef DIE_H
#define DIE_H

class Die {
// comment #1: these are my data members that are not accessible to the user outside of the class
private:
    int sides; 
    int value; 

public:
    // comment #2: these are my member functions that are accessible to the user outside of the class
    Die(int numSides); 
    void setSides(int numSides); // comment #3: this is a mutator function, which allows the number of sides on the die to be changed
    void roll();
    int getSides() const;
    int getValue() const;
};

#endif
