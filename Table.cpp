#include "Table.h"
#include <algorithm>
#include <iostream>

Table::Table(const unsigned int tableBetLimit, const unsigned int tableDeckPenetration, const unsigned int numDecks, const bool tableHitSoft17, const bool tableDoubleAfterSplit)
: betLimit(tableBetLimit), deckPenetration(tableDeckPenetration), decks(numDecks), hitSoft17(tableHitSoft17), doubleAfterSplit(tableDoubleAfterSplit) {}

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

void Table::startGame()
{
    Deck tableDeck = Deck(decks);

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

    for (std::unique_ptr<Player>& player : players)
    {
        for (std::unique_ptr<Hand>& hand : player->getHands()) 
        {
            bool hit;
            std::cin >> hit;

            while (hit)
            {
                player->hit(tableDeck, hand);

                if (hand->score > 21) 
                {
                    player->loseHand(tableDeck, hand);
                    break;
                }
                else if (hand->score == 21)
                {
                    player->winHand(tableDeck, hand);
                    break;
                }
                else
                {
                    std::cin >> hit;
                }
            }
        }
    }

    while (dealer.getHand()->score < 17)
    {
        dealer.hit(tableDeck);
    }

    int dealerScore = dealer.getHand()->score;

    for (std::unique_ptr<Player>& player : players)
    {
        for (std::unique_ptr<Hand>& hand : player->getHands())
        {
            if (dealerScore > 21)
            {
                player->winHand(tableDeck, hand);
            }
            else
            {
            (hand->score > dealerScore) ? player->winHand(tableDeck, hand) : player->loseHand(tableDeck, hand);
            }
        }
    }
}