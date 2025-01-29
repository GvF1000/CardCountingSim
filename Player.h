#ifndef PLAYER_H
#define PLAYER_H

#include "Hand.h"
#include "Deck.h"

class Player
{
private:
    std::vector<Hand*> hands;
    std::string name;
    int balance;

public:
    Player(const std::string playerName, const int palyerBalance = 0);

    void drawHands(Deck& deck, const int numCards, int betamount);

    void resetHands();

    void winHand(const Hand hand);

    void looseHand(const Hand hand);

    std::vector<Hand*> getHands();

    void displayHands();

};

#endif