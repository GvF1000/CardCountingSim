#ifndef DEALER_H
#define DEALER_H

#include "Hand.h"
#include "Deck.h"

class Dealer
{
private:
    Hand* hand;

public:
    void drawHand(Deck& deck, const int numCards);

    void resetHand();

    void displayHand();

    void hit(Deck& deck);

    Hand* getHand();
};

#endif