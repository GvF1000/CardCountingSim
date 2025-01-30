#include "Hand.h"

Hand::Hand(std::vector<std::unique_ptr<Card>> const handCards, const int betAmount) : cards(handCards)
{
    for (std::unique_ptr<Card>& card : cards) 
    {
        score += card->score;
    }
}

void Hand::displayHand() 
{
    for (std::unique_ptr<Card>& card : cards) 
    {
        card->displayCard();
    }
}