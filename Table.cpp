#include "Table.h"
#include <algorithm>
#include <iostream>

Table::Table(const unsigned int tableBetLimit, const unsigned int tableDeckPenetration, const unsigned int numDecks, const bool tableHitSoft17, const bool tableDoubleAfterSplit)
: betLimit(tableBetLimit), deckPenetration(tableDeckPenetration), decks(numDecks), hitSoft17(tableHitSoft17), doubleAfterSplit(tableDoubleAfterSplit) {}

void Table::addPlayer(Player* player)
{
    players.push_back(player);
}
    

void Table::removePlayer(Player* player)
{
    auto i = std::find(players.begin(), players.end(), player);

    if (i != players.end())
    {
        players.erase(i);
    }
}

void Table::startGame()
{
    Deck tableDeck = Deck(decks);

    for (Player* player : players)
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

    dealer.drawHand(tableDeck, 2);

    for (Player* player : players)
    {
        for (Hand* hand : player->getHands()) 
        {
            bool hit;
            std::cin >> hit;

            while (hit)
            {
                player->hit(tableDeck, hand);

                if (hand->score > 21) 
                {
                    player->looseHand(hand);
                }
                else if (hand->score == 21)
                {
                    player->winHand(hand);
                }
                else
                {
                    std::cin >> hit;
                }
            }
        }
    }

    for (Player* player : players)
    {
        for (Hand* hand : player->getHands())
        {
            (hand->score > dealer.getHand()->score) ? player->winHand(hand) : player->looseHand(hand);
        }
    }
}