#include "Dealer.h"

void Dealer::drawHand(Deck& deck, const int numCards)
{
    hand = new Hand(deck.drawCards(numCards));
}

void Dealer::resetHand()
{
    hand->cards.clear();
}

void Dealer::displayHand() 
{
    hand->displayHand();
}

void Dealer::hit(Deck& deck)
{
    hand->cards.push_back(deck.drawCards(1)[0]);
}

Hand* Dealer::getHand()
{
    return hand;
}