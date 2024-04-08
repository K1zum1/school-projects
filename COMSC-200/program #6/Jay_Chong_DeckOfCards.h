#ifndef DECKOFCARDS_H
#define DECKOFCARDS_H

#include "Jay_Chong_Card.h"
#include <vector>
using namespace std;

// comment #12 : this is the definition of the DeckOfCards class
class DeckOfC {
public:
    DeckOfC(); 
    void shuffle(); 
    Card dealtheCard(); 
    bool moreCards() const;
// comment #13 : these are the private data members of the DeckOfCards class
private:
    vector<Card> deck;
    int currentCard; 
};

#endif
