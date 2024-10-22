/**
 * \file 
 * \brief Main file
 */

#include <iostream>
#include "./src/card.h"
#include "./src/deck.h"
#include "./src/dialogue.h"

using std::cout;
using std::cin;
using std::string;
using std::endl;
int main() {
    srand(time(0));
    try {
        Card card;
        card.inputCard();
        Deck deck1 = Deck::createRandomDeck();
        deck1.outputDeck();
    }
    catch(const std::runtime_error& e) {
        std::wcerr << "Input failed: " << e.what() << std::endl;
    }
    catch(const std::exception& e) {
        std::wcerr << e.what() << std::endl;
    }
    return 0;
    }
