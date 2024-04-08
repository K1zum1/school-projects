#include "Jay_Chong_Die.h"
#include <iostream>

using namespace std;

void playRound(Die& die1, Die& die2, int& pTotal, int& cTotal);
bool askRoll();

int main() {
    cout << "Let's play a game of 21" << endl;
    cout << "_________________________________________" << endl;
    
    // comment #7: we want to create two dies with 6 sides and set the player and computer's total to 0
    Die die1(6), die2(6);
    int pTotal = 0, cTotal = 0;
    bool keepPlaying = true;

    // comment #8: this is the main game loop, which will continue as long as the player's total is less than or equal to 21 and the player wants to keep playing
    while (keepPlaying && pTotal <= 21) {
        playRound(die1, die2, pTotal, cTotal);
        if (pTotal <= 21) {
            keepPlaying = askRoll();
        }
    }

    // comment #9: this is the end of the game, where we compare the player's total to the computer's total and determine the winner
    cout << "Computer's total: " << cTotal << endl;
    if ((pTotal > cTotal && pTotal <= 21) || cTotal > 21) {
        cout << "You win!" << endl;
    } else if (pTotal == cTotal || pTotal > 21) {
        cout << "It's a tie or both players went over 21." << endl;
    } else {
        cout << "Computer wins!" << endl;
    }

    return 0;
}

// comment #10: this function simulates a round of the game, where the computer and player both roll their dice
void playRound(Die& die1, Die& die2, int& pTotal, int& cTotal) {
    // comment #11: the computer rolls its dice and updates its total
    die1.roll();
    die2.roll();
    cTotal += die1.getValue() + die2.getValue();

    // comment #12: the player rolls their dice and updates their total
    cout << "Your turn to roll. " << endl;
    die1.roll();
    die2.roll();
    cout << "You rolled: " << die1.getValue() + die2.getValue() << endl;
    pTotal += die1.getValue() + die2.getValue();
}

// comment #13: this function asks the player if they want to roll again and returns true if they do
bool askRoll() {
    char response;
    cout << "Do you want to roll again? (y/n): ";
    cin >> response;
    return response == 'y' || response == 'Y';
}
