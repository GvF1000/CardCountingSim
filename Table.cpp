#include "Table.h"
#include <algorithm>
#include <iostream>

Table::Table(const unsigned int tableBetLimit, const unsigned int tableDeckPenetration, const unsigned int numDecks, const bool tableHitSoft17, const bool tableDoubleAfterSplit)
: betLimit(tableBetLimit), deckPenetration(tableDeckPenetration), tableDeck(numDecks), hitSoft17(tableHitSoft17), doubleAfterSplit(tableDoubleAfterSplit) {}

void Table::addPlayer(std::unique_ptr<Player>& player)
{
    players.push_back(std::move(player));
}
    
void Table::removePlayer(std::unique_ptr<Player>& player)
{
    auto i = std::find_if
    (
        players.begin(), players.end(),
        [&player](const std::unique_ptr<Player>& p) 
        {
            return p.get() == player.get();
        }
    );

    if (i != players.end())
    {
        players.erase(i);
    }
}

void Table::dealInitialCards()
{
    for (std::unique_ptr<Player>& player : players)
    { 
        int hands;
        std::cin >> hands;

        for (int i = 0; i < hands; ++i) 
        {
            int betAmount;
            std::cin >> betAmount;
            player->drawCards(tableDeck, 2, betAmount);
        }
    }

    dealer.drawCards(tableDeck, 2);
}

void Table::processPlayerActions()
{
    for (std::unique_ptr<Player>& player : players)
    {
        for (std::unique_ptr<Hand>& hand : player->getHands()) 
        {
            bool hit;
            std::cin >> hit;

            while (hit)
            {
                player->hit(tableDeck, hand);

                if (hand->getScore() > 21 || hand->getScore() == 21) 
                {
                    break;
                }
                
                std::cin >> hit;
            }
        }
    }

    const std::unique_ptr<Hand>& dealerHand = dealer.getHand();
    while (dealerHand->getScore() < 17)
    {
        dealer.hit(tableDeck);
    }
}

void Table::startGame()
{
    dealInitialCards();

    processPlayerActions();

    const int dealerScore = dealer.getHand()->getScore();

    for (std::unique_ptr<Player>& player : players)
    {
        for (std::unique_ptr<Hand>& hand : player->getHands())
        {
            const int handScore = hand->getScore();

            if (handScore > 21)
            {
                player->loseHand(tableDeck, hand);
            }
            else if (dealerScore > 21)
            {
                player->winHand(tableDeck, hand);
            }
            else if (dealerScore == handScore)
            {
                player->tieHand(tableDeck, hand);
            }
            else
            {
            (handScore > dealerScore) ? player->winHand(tableDeck, hand) : player->loseHand(tableDeck, hand);
            }
        }
    }
}