#include "Card.h"
#include <iostream>

Card::Card(const std::string r, const std::string s) : rank(r), suite(s) 
{
    faceCard = (rank == "King" || rank == "Queen" || rank == "Jack");
    if (faceCard) {score = 10;}
    else if (rank == "Ace") {score = 11;}
    else {score = std::stoi(rank);}
}

int Card::getScore() const
{
    return score;
}

const std::string& Card::getRank() const
{
    return rank;
}

const std::string& Card::getSuite() const
{
    return suite;
}

void Card::displayCard()
{
    std::cout << "Rank: " << rank << "\n";
    std::cout << "Suite: " << suite << "\n";
    std::cout << "Score: " << score << "\n";
}