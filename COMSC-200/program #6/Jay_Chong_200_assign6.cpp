#include <iostream>
#include <iomanip>
#include "Jay_Chong_DeckOfCards.h"
using namespace std;

int main() {
    // comment #1: this is the main function that will be used to test the DeckOfCards class
    DeckOfC deckOfCards; 
    deckOfCards.shuffle();  
    const int cardWidth = 20;

    // comment #2: this loop will deal 26 cards from the deck and print them out in two columns for neater apperance
    for (int i = 0; i < 26; ++i) {
        Card card1 = deckOfCards.dealtheCard();
        Card card2 = deckOfCards.dealtheCard(); 
        cout << left << setw(cardWidth) << card1.toString() << setw(cardWidth) << card2.toString() << endl;
    }
    

    return 0;
}
