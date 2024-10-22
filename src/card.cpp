/**
 * \file
 * \brief File with class card
 * 
 * This file contains the definition of the class card and the main
functions used in it
 */


#include <cstring>
#include "card.h"

using std::cout;
using std::cin;
using std::string;
using std::endl;


std::string Card::suits[] = {"Hearts", "Diamonds", "Clubs", "Spades"};

/**
     * \brief Creating a random card
     * \param none
     * \return new random Card
     */

Card Card::createRandomCard() {
    unsigned int rank = rand() % 13 + 1;
    int suit = rand() % 4;
    return Card(rank, Card::suits[suit]);
}



bool Card::operator == (const Card &card1) const {
    return (rank == card1.rank && suit == card1.suit);
}

bool Card::operator < (const Card &card1) const {
    return (rank < card1.rank);
}

std::istream & operator >> (std::istream &s, Card &card1) {
    int rank;
    std::string suit;
    s >> rank >> suit; 
    card1 = Card(rank, suit);
    if(s.bad()) s.setstate(std::ios::failbit);
    return s;
}

std::ostream & operator << (std::ostream &s, Card &card1) {
    s << card1.getRank() << "\n";
    s << card1.getSuit();
    return s;
}



/**
     * \brief Creating a string with beautiful style
     * \param none
     * \return a string in a pretty format
     */

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