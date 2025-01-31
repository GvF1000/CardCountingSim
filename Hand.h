#ifndef HAND_H
#define HAND_H

#include <vector>
#include <memory>
#include "Card.h"

struct Hand
{
    int score = 0;
    int betAmount = 0;
    std::vector<std::unique_ptr<Card>> cards;

    Hand(std::vector<std::unique_ptr<Card>>& const handCards = {}, const int betAmount = 0);
    void addCard(std::unique_ptr<Card>& card);
    void displayHand();
};

#endif