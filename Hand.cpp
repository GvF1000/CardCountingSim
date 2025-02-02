#include "Hand.h"

Hand::Hand(std::vector<std::unique_ptr<Card>>& const handCards, const int betAmount) : cards(handCards)
{
    calculateScore();
}

const std::vector<std::unique_ptr<Card>>& Hand::getCards()
{
    return cards;
}

int Hand::calculateScore()
{
    score = 0;
    for (const std::unique_ptr<Card>& card : getCards()) 
    {
        score += card->getScore();
    }
}

void Hand::addCard(std::unique_ptr<Card>& card)
{
    cards.push_back(std::move(card));
    score += cards.back()->getScore();
}

int Hand::getScore()
{
    return score;
}

void Hand::displayHand() 
{
    for (std::unique_ptr<Card>& card : cards) 
    {
        card->displayCard();
    }
}