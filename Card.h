#ifndef CARDH_H
#define CARD_H

#include <string>

class Card
{
private:
    std::string rank;
    std::string suite;
    bool faceCard;
    int score;

public:
    Card(const std::string r, const std::string s);
    int getScore() const;
    const std::string& getRank() const;
    const std::string& getSuite() const;
    void displayCard();
};

#endif