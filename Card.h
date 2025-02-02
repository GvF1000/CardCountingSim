#ifndef CARDH_H
#define CARD_H

#include <string>

struct Card
{
private:
    std::string rank;
    std::string suite;
    bool faceCard;
    int score;

public:
    Card(const std::string r, const std::string s);
    const int getScore();
    void displayCard();
};

#endif