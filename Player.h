#ifndef PLAYER_H
#define PLAYER_H

#include "Hand.h"
#include "Deck.h"

class Player
{
private:
    std::vector<std::unique_ptr<Hand>> hands;
    std::string name;
    int balance;

public:
    Player(const std::string& playerName, const int playerBalance = 0);

    void drawCards(Deck& deck, const int& numCards, const int& handBetAmount = 0);

    void hit(Deck& deck, std::unique_ptr<Hand>& hand);

    void resetHands();

    void winHand(Deck& deck, std::unique_ptr<Hand>& hand);

    void loseHand(Deck& deck, std::unique_ptr<Hand>& hand);

    void removeHand(Deck& deck, std::unique_ptr<Hand>& hand);

    std::vector<std::unique_ptr<Hand>>& getHands();

    void displayHands();

};

#endif