#include "Dealer.h"

void Dealer::drawHand(Deck& deck, const int numCards)
{
    hand = Hand(deck.drawCards(numCards));
}

void Dealer::resetHand()
{
    hand = Hand();
}

void Dealer::displayHand() 
{
    hand.displayHand();
}