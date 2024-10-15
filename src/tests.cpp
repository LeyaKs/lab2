#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <sstream>
#include "deck.h"
#include "card.h"
#include "exception"
#include <iostream>

TEST_CASE("Deck") {
    SECTION("Output") {
        Card *cards = new Card[2];
        cards[0] = Card(1, "Hearts");
        cards[1] = Card(10, "Clubs");
        Deck deck1(2, cards);
        auto stdoutBuffer = std::cout.rdbuf();
        std::ostringstream oss;
        std::cout.rdbuf(oss.rdbuf());
        deck1.outputDeck();
        std::cout.rdbuf(stdoutBuffer);
        REQUIRE(oss.str() == "2♥\nJ♧\n");
    }
    SECTION("Random deck") {
        
    }
}