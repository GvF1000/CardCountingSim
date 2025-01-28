#ifndef DECK_H
#define DECK_H

#include <vector>
#include <unordered_map>
#include "Card.h"

class Deck
{
private:
    int numDecks;
    std::vector<Card> cardDeck;
    std::string suites[4] = {"Club", "Heart", "Diamond", "Spade"};
    std::string ranks[13] = {"Ace", "King", "Queen", "Jack", "10", "9", "8", "7", "6", "5", "4", "3", "2"};
    std::unordered_map<std::string, int> cardsLeft;
    int cardsPlayed = 0;

    void fillDeck();

public:
    void shuffleDeck();

    Deck(int decks = 1);

    void moveBackCards(const int numCards);

    void displayDeck();

    std::vector<Card> drawCards(const int numCards);

    int checkCardsPlayed();
};

#endif