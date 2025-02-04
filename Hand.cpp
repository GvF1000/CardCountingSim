#include "Hand.h"

Hand::Hand(std::vector<std::unique_ptr<Card>>& handCards, int handBetAmount) : cards(std::move(handCards)), betAmount(handBetAmount)
{
    calculateScore();
}

const std::vector<std::unique_ptr<Card>>& Hand::getCards() const
{
    return cards;
}

int Hand::calculateScore()
{
    score = 0;
    for (const std::unique_ptr<Card>& card : cards) 
    {
        score += card->getScore();
    }
}

void Hand::addCard(std::unique_ptr<Card>& card)
{
    cards.push_back(std::move(card));
    score += cards.back()->getScore();
}

int Hand::getScore() const
{
    return score;
}

int Hand::getBetAmount() const
{
    return betAmount;
}

void Hand::displayHand() const
{
    for (const std::unique_ptr<Card>& card : cards) 
    {
        card->displayCard();
    }
}