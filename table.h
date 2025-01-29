#ifndef TABLE_H
#define TABLE_H

#include "Player.h"
#include "Dealer.h"

class Table
{
private:
    std::vector<Player*> players;
    Dealer dealer;
    unsigned int decks;
    unsigned int betLimit;
    unsigned int deckPenetration;
    bool hitSoft17;
    bool doubleAfterSplit;

public:
    Table(const unsigned int tableBetLimit, const unsigned int tableDeckPenetration, const unsigned int numDecks, const bool tableHitSoft17, const bool tableDoubleAfterSplit);

    void addPlayer(Player* player);

    void removePlayer(Player* player);

    void startGame();
};

#endif