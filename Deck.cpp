#include "Deck.h"
#include <random>
#include <iostream>

void Deck::fillDeck()
{
    for (int i = 0; i < numDecks; i++)
    {
        for (const std::string rank : ranks)
        {
            for (const std::string suite : suites) 
            {
                cardDeck.push_back(Card(rank, suite));
            }
        }

    }
}

void Deck::shuffleDeck()
{
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(cardDeck.begin(), cardDeck.end(), g);

    for (std::string rank : ranks) {cardsLeft[rank] = (4 * numDecks);}
    cardsPlayed = 0;
}

Deck::Deck(int decks) : numDecks(decks)
{
    fillDeck();
    shuffleDeck();
}

void Deck::moveBackCards(const int numCards)
{ 
    if (numCards > cardDeck.size())
    {
        std::cerr << "Cannot move more cards than available in the deck!\n";
        return;
    }

    for (int i = 0; i < numCards; ++i)
    {
        cardsLeft[cardDeck[i].rank] -= 1;
    }

    std::rotate(cardDeck.begin(), cardDeck.begin() + numCards, cardDeck.end());
    cardsPlayed += numCards;
}

void Deck::displayDeck()
{
    for (Card card : cardDeck)
    {
        card.displayCard();
        std::cout << std::endl;
    }
}

std::vector<Card> Deck::drawCards(const int numCards)
{
    std::vector<Card> cards;

    if (numCards > cardDeck.size()) 
    {
        std::cerr << "Insufficient cards in the deck. Only " << cardDeck.size() << " cards left.\n";
        return cards;
    }

    for (int i = 0; i < numCards; ++i)
    {
        cards.push_back(cardDeck[i]);
    }

    moveBackCards(numCards);
    return cards;
}