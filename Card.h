#ifndef CARDH_H
#define CARD_H

#include <string>

struct Card
{
    std::string rank;
    std::string suite;
    bool faceCard;
    int score;

    Card(const std::string r, const std::string s);
    void displayCard();
};

#endif