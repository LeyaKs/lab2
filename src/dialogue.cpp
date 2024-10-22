#include <iostream>
#include "dialogue.h"
#include "card.h"

#define MAX_SIZE 52

unsigned int createRandomDeckDialogue() {
    unsigned int count_v;
    std::cout << "Enter the number of cards from 1 to " << MAX_SIZE <<  std::endl;
    std::cin >> count_v;
    while (count_v < 1 || count_v > MAX_SIZE) {
            std::cout << "Try again" << std::endl;
            std::cin >> count_v;
    }
    return count_v;
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