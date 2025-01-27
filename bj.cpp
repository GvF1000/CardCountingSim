#include <iostream>
#include <string>

struct Card
{
    char rank;
    std::string suite;
    bool faceCard;

    Card(char r, std::string s) : rank(r), suite(s) 
    {
        faceCard = (rank == 'K' || rank == 'Q' || rank == 'J');
    }

    void displayCard()
    {
        std::cout << "Rank: " << rank << "\n";
        std::cout << "Suite: " << suite << "\n";
    }

};


int main()
{
    Card random = Card('K', "Club");
    random.displayCard();
    return 0;
}