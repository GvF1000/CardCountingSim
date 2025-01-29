#include "Player.h"

Player::Player(const std::string playerName, const int palyerBalance) : name(playerName), balance(palyerBalance) {}

void Player::drawHands(Deck& deck, const int numCards, const int betamount)
{
    Hand* hand = new Hand(deck.drawCards(numCards));

    hands.push_back(hand);
}

void Player::resetHands()
{
    hands = {};
}

void Player::winHand(const Hand hand) 
{
    balance += hand.betAmount;
}

void Player::looseHand(const Hand hand) 
{
    balance -= hand.betAmount;
}

std::vector<Hand*> Player::getHands() 
{
    return hands;
}

void Player::displayHands()
{
    for (Hand* hand : hands) {hand->displayHand();}
}