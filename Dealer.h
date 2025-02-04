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

    void resetHand(Deck& deck);

    void displayHand() const;

    void hit(Deck& deck);

    const std::unique_ptr<Hand>& getHand() const;
};

#endif