#include <iostream>
#include <iomanip> // we need this library to use fixed and setprecision
#include "Jay_Chong_Coin.h"

using namespace std;

// comment #7 this function simulates a round of the game, where the computer and player both toss their coins and
// display the results
void playRound(double &pBalance, double &cBalance, Coin &quarter, Coin &dime, Coin &nickel);
void displayResults(const double &pBalance, const double &cBalance);

int main() {
    Coin quarter, dime, nickel;
    double pBalance = 0.0, cBalance = 0.0;

    cout << "Your Starting Balance: $0.00" << endl;
    cout << "The Computers Starting Balance: $0.00" << endl;

    // comment #8 this is the main game loop, we will continue as long as the player's balance is less than 1.00 and the computer's balance is less than 1.00
    while (pBalance < 1.0 && cBalance < 1.0) {
        playRound(pBalance, cBalance, quarter, dime, nickel);
        cout << "Player's balance: $" << fixed << setprecision(2) << pBalance << endl;
        cout << "Computer's balance: $" << fixed << setprecision(2) << cBalance << endl;
    }

    displayResults(pBalance, cBalance);

    return 0;
}

// comment #9 this function simulates a round of the game, where the computer and player both toss their coins
void playRound(double &pBalance, double &cBalance, Coin &quarter, Coin &dime, Coin &nickel) {
    
    quarter.toss();
    if (quarter.getSideUp() == "heads") pBalance += 0.25;
    dime.toss();
    if (dime.getSideUp() == "heads") pBalance += 0.10;
    nickel.toss();
    if (nickel.getSideUp() == "heads") pBalance += 0.05;

    // comment #10 this is the same thing as above, but for the computer
    quarter.toss();
    if (quarter.getSideUp() == "heads") cBalance += 0.25;
    dime.toss();
    if (dime.getSideUp() == "heads") cBalance += 0.10;
    nickel.toss();
    if (nickel.getSideUp() == "heads") cBalance += 0.05;
}

// comment #11 this function displays the results of the game
void displayResults(const double &pBalance, const double &cBalance) {
    cout << "Ending balance - Player: $" << fixed << setprecision(2) << pBalance
              << ", Computer: $" << fixed << setprecision(2) << cBalance << endl;
              
    // comment #12, a simple if-else statement to determine the winner
    if (pBalance >= 1.0 && cBalance >= 1.0) {
        if (pBalance == cBalance) {
            cout << "Tie! Nobody Wins" << endl;
        } else if (pBalance < cBalance) {
            cout << "Player wins!" << endl;
        } else {
            cout << "Computer wins!" << endl;
        }
    } else if (pBalance >= 1.0) {
        cout << "Player wins!" << endl;
    } else if (cBalance >= 1.0) {
        cout << "Computer wins!" << endl;
    }
}
