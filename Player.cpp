#include "Player.h"

Player::Player(const std::string& playerName, const int playerBalance) : name(playerName), balance(playerBalance) {}

void Player::drawCards(Deck& deck, const int& numCards, const int& handBetAmount)
{
    std::vector<std::unique_ptr<Card>> drawnCards = deck.drawCards(numCards);
    auto hand = std::make_unique<Hand>(std::move(drawnCards), handBetAmount);

    hands.push_back(std::move(hand));
}

void Player::hit(Deck& deck, std::unique_ptr<Hand>& hand)
{
    std::unique_ptr<Card> newCard = std::move(deck.drawCards(1)[0]);
    hand->cards.push_back(std::move(newCard));
    hand->score += hand->cards.back()->score;
}

void Player::resetHands()
{
    hands = {};
}

void Player::removeHand(Deck& deck, std::unique_ptr<Hand>& hand)
{

    auto i = std::find_if
    (
        hands.begin(), hands.end(), 
        [&hand](const std::unique_ptr<Hand>& h) 
        {
            return h.get() == hand.get();
        }
    );

    if (i != hands.end()) 
    {
        deck.returnHand(std::move(*i));
        hands.erase(i);
    }
}

void Player::winHand(Deck& deck, std::unique_ptr<Hand>& hand) 
{
    balance += hand->betAmount;
    removeHand(deck, std::move(hand));
}

void Player::loseHand(Deck& deck, std::unique_ptr<Hand>& hand) 
{
    balance -= hand->betAmount;
    removeHand(deck, std::move(hand));
}

std::vector<std::unique_ptr<Hand>>& Player::getHands() 
{
    return hands;
}

void Player::displayHands()
{
    for (const std::unique_ptr<Hand>& hand : hands) {hand->displayHand();}
}