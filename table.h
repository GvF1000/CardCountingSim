#ifndef TABLE_H
#define TABLE_H

#include "Player.h"
#include "Dealer.h"

class Table
{
private:
    std::vector<std::unique_ptr<Player>> players;
    Dealer dealer;
    Deck tableDeck;
    unsigned int betLimit;
    unsigned int deckPenetration;
    bool hitSoft17;
    bool doubleAfterSplit;

    void dealInitialCards();
    void processPlayerActions();
    void processDealerActions();
    bool isBust(const int score);
    bool isTie(const int playerScore, const int dealerHandScore);
    bool isPlayerWinning(const int playerScore, const int dealerScore);
    void evaluateHandOutcome(const std::unique_ptr<Player>& player, const std::unique_ptr<Hand>& hand, int dealerScore);
    void returnPlayersHands();
    void affirmPlayers();
public:
    Table(const unsigned int tableBetLimit, const unsigned int tableDeckPenetration, const unsigned int numDecks, const bool tableHitSoft17, const bool tableDoubleAfterSplit);

    void addPlayer(std::unique_ptr<Player>& player);

    void removePlayer(std::unique_ptr<Player>& player);

    void startGame();
};

#endif