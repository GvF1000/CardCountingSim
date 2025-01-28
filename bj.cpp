#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <random>
#include <unordered_map>
struct Card
{
    std::string rank;
    std::string suite;
    bool faceCard;
    int score;

    Card(const std::string r, const std::string s) : rank(r), suite(s) 
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
    int numDecks;
    std::vector<Card> cardDeck;
    std::string suites[4] = {"Club", "Heart", "Diamond", "Spade"};
    std::string ranks[13] = {"Ace", "King", "Queen", "Jack", "10", "9", "8", "7", "6", "5", "4", "3", "2"};
    std::unordered_map<std::string, int> cardsLeft;
    int cardsPlayed = 0;

    void fillDeck()
    {
        for (int i = 0; i < numDecks; i++)
        {
            for (const std::string rank : ranks)
            {
                for (const std::string suite : suites) 
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

        for (std::string rank : ranks) {cardsLeft[rank] = (4 * numDecks);}
        cardsPlayed = 0;
    }

    Deck(int decks = 1) : numDecks(decks)
    {
        fillDeck();
        shuffleDeck();
    }

    void moveBackCards(const int numCards)
    { 
        if (numCards > cardDeck.size())
        {
            std::cerr << "Cannot move more cards than available in the deck!\n";
            return;
        }

        for (int i = 0; i < numCards; ++i)
        {
            cardsLeft[cardDeck[i].rank] -= 1;
        }

        std::rotate(cardDeck.begin(), cardDeck.begin() + numCards, cardDeck.end());
        cardsPlayed += numCards;
    }

    void displayDeck()
    {
        for (Card card : cardDeck)
        {
            card.displayCard();
            std::cout << std::endl;
        }
    }

    std::vector<Card> drawCards(const int numCards)
    {
        std::vector<Card> cards;

        if (numCards > cardDeck.size()) 
        {
            std::cerr << "Insufficient cards in the deck. Only " << cardDeck.size() << " cards left.\n";
            return cards;
        }

        for (int i = 0; i < numCards; ++i)
        {
            cards.push_back(cardDeck[i]);
        }

        moveBackCards(numCards);
        return cards;
    }
};
struct Hand
{
    int score = 0;
    int betAmount = 0;
    std::vector<Card> cards;

    Hand(std::vector<Card> const handCards = {}, const int betAmount = 0) : cards(handCards)
    {
        for (Card card : cards) {score += card.score;}
    }

    void displayHand() {for (Card card : cards) {card.displayCard();}}
};
class Player
{
private:
    std::vector<Hand> hands;
    std::string name;
    int balance;

public:
    Player(const std::string playerName, const int palyerBalance = 0) : name(playerName), balance(palyerBalance) {}

    void drawHands(Deck& deck, const int numCards, const int numHands)
    {
        for (int i = 0; i < numHands; ++i)
        {
            Hand hand = Hand(deck.drawCards(numCards));

            hands.push_back(hand);
        }
    }

    void resetHands()
    {
        hands = {};
    }

    void winHand(const Hand hand) {balance += hand.betAmount;}

    void looseHand(const Hand hand) {balance -= hand.betAmount;}

    void displayHands()
    {
        for (Hand hand : hands) {hand.displayHand();}
    }
};
class Dealer
{
private:
    Hand hand;

public:
    void drawHand(Deck& deck, const int numCards)
    {
        hand = Hand(deck.drawCards(numCards));
    }

    void resetHand()
    {
        hand = Hand();
    }

    void displayHand() {hand.displayHand();}
};

int main()
{
    Deck myDeck = Deck(1);
    return 0;
}