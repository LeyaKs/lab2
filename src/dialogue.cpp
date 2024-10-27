/**
 * \file
 * \brief File with dialogue functions
 */

#include <iostream>
#include "dialogue.h"
#include "card.h"
#include "input.h"

#define MAX_SIZE 52



unsigned int createRandomDeckDialogue() {
    unsigned int count_v;
    std::cout << "Enter the number of cards from 1 to " << MAX_SIZE <<  std::endl;
    count_v = get_int(1, MAX_SIZE);
    return count_v;
}



Card Card::inputCard() {
    unsigned int rank;
    int suit;
    std::cout << "Input rank from 1 to 13" << std::endl;
    rank = get_int(1, 13);
    std::cout << "Input suit: 0 - Hearts, 1 - Diamonds, 2 - Clubs, 3 - Spades" << std::endl;
    suit = get_int(0, 3);
    return Card(rank, Card::suits[suit]);
}



void Card::outputCard() {
    std::cout << "Card's rank:\t" << rank << std::endl;
    std::cout << "Card's suit:\t" << suit << std::endl;
    std::cout << "Card: " << rank <<  " " << suit << std::endl;
}