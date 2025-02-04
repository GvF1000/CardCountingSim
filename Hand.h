#ifndef HAND_H
#define HAND_H

#include <vector>
#include <memory>
#include "Card.h"

class Hand
{
private:
    int score = 0;
    int betAmount = 0;
    std::vector<std::unique_ptr<Card>> cards;

    int calculateScore();
public:
    Hand(std::vector<std::unique_ptr<Card>>& handCards = {}, int betAmount = 0);
    const std::vector<std::unique_ptr<Card>>& getCards() const;
    int getScore() const;
    int getBetAmount() const;
    void addCard(std::unique_ptr<Card>& card);
    void displayHand() const;
};

#endif