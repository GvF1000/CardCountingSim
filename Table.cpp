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
}

void Table::processDealerActions()
{
    const std::unique_ptr<Hand>& dealerHand = dealer.getHand();
    while (dealerHand->getScore() < 17)
    {
        dealer.hit(tableDeck);
    }
}

bool Table::isBust(const int score)
{
    return score > 21;
}

bool Table::isTie(const int playerScore, const int dealerScore)
{
    return playerScore == dealerScore;
}

bool Table::isPlayerWinning(const int playerScore, const int dealerScore)
{
    return playerScore > dealerScore;
}

void Table::evaluateHandOutcome(const std::unique_ptr<Player>& player, const std::unique_ptr<Hand>& playerHand, int dealerHandScore)
{
    const int playerHandScore = playerHand->getScore();
    const int handBetAmount = playerHand->getBetAmount();

    if (isBust(playerHandScore))
    {
        player->loseHand(tableDeck, handBetAmount);
    }
    else if (isBust(dealerHandScore))
    {
        player->winHand(tableDeck, handBetAmount);
    }
    else if (isTie(playerHandScore, dealerHandScore))
    {
        player->tieHand(tableDeck, handBetAmount);
    }
    else if (isPlayerWinning(playerHandScore, dealerHandScore))
    {
        player->winHand(tableDeck, handBetAmount);
    }
    else
    {
        player->loseHand(tableDeck, handBetAmount);
    }
}

void Table::returnPlayersHands()
{
    for (const std::unique_ptr<Player>& player : players)
    {
        player->resetHands(tableDeck);
    }
}

void Table::affirmPlayers() {
    players.erase
    (
        std::remove_if
        (
            players.begin(), players.end(), 
            [](const std::unique_ptr<Player>& player) 
            {
                bool choice;
                std::cin >> choice;
                return !choice;
            }
        ),
        players.end()
    );
}

void Table::startGame()
{
    while (!players.empty())
    {
        dealInitialCards();

        processPlayerActions();

        processDealerActions();

        const int dealerHandScore = dealer.getHand()->getScore();
        for (const std::unique_ptr<Player>& player : players)
        {
            for (const std::unique_ptr<Hand>& hand : player->getHands())
            {
                evaluateHandOutcome(player, hand, dealerHandScore);
            }
        }

        returnPlayersHands();

        affirmPlayers();
    }
}