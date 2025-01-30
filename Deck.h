#ifndef DECK_H
#define DECK_H

#include <vector>
#include <unordered_map>
#include "Card.h"
#include <memory>

class Deck
{
private:
    int numDecks;
    std::vector<std::unique_ptr<Card>> cardDeck;
    std::string suites[4] = {"Club", "Heart", "Diamond", "Spade"};
    std::string ranks[13] = {"Ace", "King", "Queen", "Jack", "10", "9", "8", "7", "6", "5", "4", "3", "2"};
    std::unordered_map<std::string, int> cardsLeft;
    int cardsPlayed = 0;

    void fillDeck();

public:
    Deck(int decks = 1);

    void shuffleDeck();

    std::vector<std::unique_ptr<Card>> drawCards(const int numCards);

    void moveBackCards(const int numCards);

    int getCardsPlayed();

    int getDeckSize();

    void displayDeck();

    void displayCardsLeft();
};

#endif