#include "Jay_Chong_DeckOfCards.h"
#include <algorithm>
#include <random>
#include <chrono>

using namespace std;
// comment #8 : this is the constructor for the DeckOfCards class
DeckOfC::DeckOfC() : currentCard(0) {
    for (int suit = 0; suit < 4; ++suit) {
        for (int face = 0; face < 13; ++face) {
            deck.push_back(Card(face, suit));
        }
    }
}
// comment #9 : this function will shuffle the deck of cards using the random_shuffle function from the algorithm library because its easier
void DeckOfC::shuffle() { // i had to gpt this function because i wasn't sure how to implement it without a library
    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    shuffle(deck.begin(), deck.end(), default_random_engine(seed));
}
// comment #10 : this function will deal a card from the deck if there are any left
Card DeckOfC::dealtheCard() {
    if (currentCard < deck.size()) {
        return deck[currentCard++];
    } else {
        return Card(-1, -1);
    }
}

// comment #11 : this function will return true if there are more cards left in the deck
bool DeckOfC::moreCards() const {
    return currentCard < deck.size();
}
