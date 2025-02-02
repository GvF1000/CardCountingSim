#ifndef HAND_H
#define HAND_H

#include <vector>
#include <memory>
#include "Card.h"

struct Hand
{
private:
    int score = 0;
    int betAmount = 0;
    std::vector<std::unique_ptr<Card>> cards;

    int calculateScore();

public:
    Hand(std::vector<std::unique_ptr<Card>>& const handCards = {}, const int betAmount = 0);
    const std::vector<std::unique_ptr<Card>>& getCards();
    int getScore();
    int getBetAmount();
    void addCard(std::unique_ptr<Card>& card);
    void displayHand();
};

#endif