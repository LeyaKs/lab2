#include <cstring>
#include "card.h"
#include "exceptions.h"

using std::cout;
using std::cin;
using std::string;
using std::endl;


std::string Card::suits[] = {"Hearts", "Diamonds", "Clubs", "Spades"};


Card Card::createRandomCard() {
    unsigned int rank = rand() % 13 + 1;
    int suit = rand() % 4;
    return Card(rank, Card::suits[suit]);
}


Card Card::inputCard() {
    unsigned int rank;
    int suit;
    std::cout << "Input rank from 1 to 13" << std::endl;
    do {
        std::cin >> rank;
    } while (rank < 1 || rank > 13);
    std::cout << "Input suit: 0 - Hearts, 1 - Diamonds, 2 - Clubs, 3 - Spades" << std::endl;
    do {
        std::cin >> suit;
    } while (suit < 0 || suit > 3);
    return Card(rank, Card::suits[suit]);
}



void Card::outputCard() {
    std::cout << "Card's rank:\t" << rank << std::endl;
    std::cout << "Card's suit:\t" << suit << std::endl;
    std::cout << "Card: " << rank <<  " " << suit << std::endl;
}




bool Card::operator == (const Card &card1) const {
    if (suit != card1.suit)
        throw Exception("Unequal suits");
    return (rank == card1.rank);
}

bool Card::operator < (const Card &card1) const {
    if (suit != card1.suit)
        throw Exception("Unequal suits");
    return (rank < card1.rank);
}

std::istream & operator >> (std::istream &s, Card &card1) {
    int rank;
    std::string suit;
    s >> rank >> suit; 
    card1 = Card(rank, suit);
    if(s.bad()){
        s.setstate(std::ios::failbit);
    }
    return s;
}

std::ostream & operator << (std::ostream &s, Card &card1) {
    s << card1.getRank();
    s << card1.getSuit();
    return s;
}




std::string Card::prettyFormat() {
    std::string ranks[] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"}; 
    std::string suitName;
    if (suit == "Hearts") {
            suitName = "♥";
        } else if (suit == "Diamonds") {
            suitName = "♦";
        } else if (suit == "Clubs") {
            suitName = "♧";
        } else if (suit == "Spades") {
            suitName = "♤";
        }
    // cout << "♠ ♥ ♦ ♣ ♤ ♡ ♢ ♧" << std::endl;
    return ranks[rank - 1] + suitName;
}