#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <random>

struct Card
{
    std::string rank;
    std::string suite;
    bool faceCard;
    int score;

    Card(std::string r, std::string s) : rank(r), suite(s) 
    {
        faceCard = (rank == "King" || rank == "Queen" || rank == "Jack");
        if (faceCard) {score = 10;}
        else if (rank == "Ace") {score = 11;}
        else {score = std::stoi(rank);}
    }

    void displayCard()
    {
        std::cout << "Rank: " << rank << "\n";
        std::cout << "Suite: " << suite << "\n";
        std::cout << "Score: " << score << "\n";
    }

};

class Deck
{
private:
    std::vector<Card> cardDeck;
    std::string suites[4] = {"Club", "Heart", "Diamond", "Spade"};
    std::string ranks[13] = {"Ace", "King", "Queen", "Jack", "10", "9", "8", "7", "6", "5", "4", "3", "2"};
    int cardsPlayed = 0;

    void fillDeck(int Decks)
    {
        for (int i = 0; i < Decks; i++)
        {
            for (std::string suite : suites)
            {
                for (std::string rank : ranks)
                {
                    cardDeck.push_back(Card(rank, suite));
                }
            }
        }
    }

public:
    void shuffleDeck()
    {
        std::random_device rd;
        std::mt19937 g(rd());
        std::shuffle(cardDeck.begin(), cardDeck.end(), g);
    }

    Deck(int numDecks = 1) 
    {
        fillDeck(numDecks);
        shuffleDeck();
    }

    void moveBackCards(int numCards)
    { 
        if (numCards > cardDeck.size())
        {
            std::cerr << "Cannot move more cards than available in the deck!\n";
            return;
        }
        std::rotate(cardDeck.begin(), cardDeck.begin() + numCards, cardDeck.end());
    }

    void displayDeck()
    {
        for (auto card : cardDeck)
        {
            card.displayCard();
        }
    }
};

int main()
{
    Card random = Card("Ace", "Club");
    random.displayCard();
    return 0;
}