#include "Dealer.h"

void Dealer::drawCards(Deck& deck, const int numCards)
{
    std::vector<std::unique_ptr<Card>> drawnCards = deck.drawCards(numCards);
    hand = std::make_unique<Hand>(std::move(drawnCards));
}

void Dealer::resetHand()
{
    hand->cards.clear();
}

void Dealer::displayHand() 
{
    hand->displayHand();
}

void Dealer::hit(Deck& deck)
{
    std::unique_ptr<Card> newCard = std::move(deck.drawCards(1)[0]);
    hand->cards.push_back(std::move(newCard));
    hand->score += hand->cards.back()->score;
}

std::unique_ptr<Hand>& Dealer::getHand()
{
    return hand;
}