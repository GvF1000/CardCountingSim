#include "Hand.h"

Hand::Hand(std::vector<Card> const handCards, const int betAmount) : cards(handCards)
{
    for (Card card : cards) 
    {
        score += card.score;
    }
}

void Hand::displayHand() 
{
    for (Card card : cards) 
    {
        card.displayCard();
    }
}