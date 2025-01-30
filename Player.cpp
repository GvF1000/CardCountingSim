#include "Player.h"

Player::Player(const std::string& playerName, const int playerBalance) : name(playerName), balance(playerBalance) {}

void Player::drawCards(Deck& deck, const int& numCards, const int& handBetAmount)
{
    std::unique_ptr<Hand> hand = std::make_unique<Hand>(deck.drawCards(numCards));
    hand->betAmount += handBetAmount;

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

void Player::removeHand(Hand* hand)
{
    auto i = std::find_if
    (
        hands.begin(), hands.end(), 
        [&hand](const std::unique_ptr<Hand>& h) 
        {
            return h.get() == hand;
        }
    );

    if (i != hands.end()) 
    {
        hands.erase(i);
    }
}

void Player::winHand(Hand* hand) 
{
    balance += hand->betAmount;
    removeHand(hand);
}

void Player::looseHand(Hand* hand) 
{
    balance -= hand->betAmount;
    removeHand(hand);
}

std::vector<std::unique_ptr<Hand>>& Player::getHands() 
{
    return hands;
}

void Player::displayHands()
{
    for (std::unique_ptr<Hand>& hand : hands) {hand->displayHand();}
}