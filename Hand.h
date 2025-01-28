#ifndef HAND_H
#define HAND_H

#include <vector>
#include "Card.h"

struct Hand
{
    int score = 0;
    int betAmount = 0;
    std::vector<Card> cards;

    Hand(std::vector<Card> const handCards = {}, const int betAmount = 0);
    void displayHand();
};

#endif