#ifndef DEALER_H
#define DEALER_H

#include "Hand.h"
#include "Deck.h"

class Dealer
{
private:
    std::unique_ptr<Hand> hand;

public:
    void drawCards(Deck& deck, const int numCards);

    void resetHand();

    void displayHand();

    void hit(Deck& deck);

    std::unique_ptr<Hand>& getHand();
};

#endif