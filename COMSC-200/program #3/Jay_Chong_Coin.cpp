#include "Jay_Chong_Coin.h"
#include <cstdlib> 
#include <ctime> 

// comment #4: this is the constructor for the Coin class, which initializes the random number generator and tosses the coin
Coin::Coin() {
    srand(time(0)); 
    toss(); 
}

// comment #5: this function simulates a simple coin toss and sets the sideUp data member to either "heads" or "tails"
void Coin::toss() {
    int outcome = rand() % 2; 
    if (outcome == 0) {
        sideUp = "heads";
    } else {
        sideUp = "tails";
    }
}

// comment #6: this function returns the value of the sideUp data member
std::string Coin::getSideUp() const {
    return sideUp;
}
