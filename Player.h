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

    void drawCards(Deck& deck, const int numCards, const int handBetAmount = 0);

    void hit(Deck& deck, Hand* hand);

    void resetHands();

    void winHand(Hand* hand);

    void looseHand(Hand* hand);

    void removeHand(Hand* hand);

    std::vector<Hand*> getHands();

    void displayHands();

};

#endif