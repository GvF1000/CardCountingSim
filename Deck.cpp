#include "Deck.h"
#include <random>
#include <iostream>

void Deck::fillDeck()
{
    cardDeck.clear();

    for (int i = 0; i < numDecks; i++)
    {
        for (const std::string& rank : ranks)
        {
            for (const std::string& suite : suites) 
            {
                cardDeck.push_back(std::make_unique<Card>(rank, suite));
            }
        }

    }
}

void Deck::shuffleDeck()
{
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(cardDeck.begin(), cardDeck.end(), g);

    for (std::string& rank : ranks) {cardsLeft[rank] = (4 * numDecks);}
    cardsPlayed = 0;
}

Deck::Deck(int decks) : numDecks(decks)
{
    fillDeck();
    shuffleDeck();
}

void Deck::returnHand(std::unique_ptr<Hand>& hand)
{ 
    for (const std::unique_ptr<Card>& card : hand->getCards())
    {
        cardsLeft[card->getRank()] += 1;
    }

    cardDeck.insert(cardDeck.end(), 
                std::make_move_iterator(hand->getCards().begin()),
                std::make_move_iterator(hand->getCards().end()));

    hand.reset();
}

void Deck::displayDeck() const
{
    for (const std::unique_ptr<Card>& card : cardDeck)
    {
        card->displayCard();
        std::cout << "\n";
    }
}

std::vector<std::unique_ptr<Card>> Deck::drawCards(const int numCards)
{
    std::vector<std::unique_ptr<Card>> cards;

    if (numCards > cardDeck.size()) 
    {
        std::cerr << "Insufficient cards in the deck. Only " << cardDeck.size() << " cards left.\n";
        return cards;
    }

    for (int i = 0; i < numCards; ++i)
    {
        cards.push_back(std::move(cardDeck.front()));
        cardDeck.erase(cardDeck.begin());
    }

    for (int i = 0; i < numCards; ++i)
    {
        cardsLeft[cards[i]->getRank()] -= 1;
    }

    return cards;
}

int Deck::getCardsPlayed() const
{
    return cardsPlayed;
}

void Deck::displayCardsLeft() const
{
    for (const auto& pair : cardsLeft)
    {
        std::cout << pair.first << " : " << pair.second << "\n\n";
    }
}

int Deck::getDeckSize() const
{
    return (cardDeck.size());
}