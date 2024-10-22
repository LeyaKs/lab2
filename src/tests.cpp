#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <sstream>
#include "deck.h"
#include "card.h"
#include "exception"
#include "dialogue.h"
#include <iostream>

TEST_CASE("Deck") {
    SECTION("Output") {
        Card *cards = new Card[4];
        cards[0] = Card(1, "Hearts");
        cards[1] = Card(10, "Clubs");
        cards[2] = Card(1, "Diamonds");
        cards[3] = Card(10, "Spades");
        Deck deck1(4, cards);
        auto stdoutBuffer = std::cout.rdbuf();
        std::ostringstream oss;
        std::cout.rdbuf(oss.rdbuf());
        deck1.outputDeck();
        std::cout.rdbuf(stdoutBuffer);
        REQUIRE(oss.str() == "2♥\nJ♧\n2♦\nJ♤\n");
    }
    SECTION("Random deck") {
        std::stringstream ss;
        ss << "3";
        std::cin.rdbuf(ss.rdbuf());
        Deck deck1 = Deck::createRandomDeck();
        std::set<Card> uniqueCards(deck1.getDeck(), deck1.getDeck() + deck1.getCount());
        REQUIRE(uniqueCards.size() == deck1.getCount());
    }
    SECTION("Full deck") {
        Deck deck = Deck::createFullDeck();
        std::set<Card> expectedCards;
        for (int rank = 1; rank <= 13; ++rank) {
            for (int suit = 0; suit < 4; ++suit) {
                expectedCards.insert(Card(rank, Card::suits[suit]));
            }
        }
        std::set<Card> actualCards(deck.getDeck(), deck.getDeck() + deck.getCount());
        REQUIRE(actualCards == expectedCards);
    }
    SECTION("Add random card") {
        Deck deck;
        unsigned int size = deck.getCount();
        deck.addRandomCard();
        REQUIRE(size == deck.getCount() - 1);
    }
    SECTION("Remove card") {
        Deck deck = Deck::createFullDeck();
        deck.removeCard(0);
        REQUIRE(deck.getCount() == 51);
        REQUIRE(deck.getDeck()[0] == Card(1, "Diamonds"));      
    }
    SECTION("Sort deck") {
        Card *cards = new Card[3];
        cards[0] = Card(5, "Hearts");
        cards[1] = Card(6, "Hearts");
        cards[2] = Card(2, "Hearts");
        Deck deck(3, cards);
        deck.sortDeck();
        REQUIRE(deck.getDeck()[0] == Card(2, "Hearts"));
        REQUIRE(deck.getDeck()[1] == Card(5, "Hearts"));
        REQUIRE(deck.getDeck()[2] == Card(6, "Hearts"));
    }
    SECTION("Shuffle") {
        Deck deck = Deck::createFullDeck();
        Deck originalDeck = deck; 
        deck.shuffleDeck(); 
        bool isShuffled = false;
        for (size_t i = 0; i < deck.getCount(); ++i) {
            if (!(deck[i] == originalDeck[i])) {
            isShuffled = true;
            break; 
        }
        }
        REQUIRE(isShuffled);
    }
    SECTION("Duplicates") {
        Card *cards = new Card[3];
        cards[0] = Card(5, "Hearts");
        cards[1] = Card(5, "Hearts");
        cards[2] = Card(2, "Hearts");
        Deck deck(3, cards);
        bool check = deck.checkingDups();
        REQUIRE(check == true);
        deck.removeCard(0);
        check = deck.checkingDups();
        REQUIRE(check == false);
    }
    SECTION("Group") {
        Card *cards = new Card[3];
        cards[0] = Card(5, "Hearts");
        cards[1] = Card(5, "Clubs");
        cards[2] = Card(3, "Hearts");
        Deck deck(3, cards);
        Deck deck1 = deck.groupSuits("Hearts");
        REQUIRE(deck1.getCount() == 2);
        REQUIRE(deck1.getDeck()[0] == Card(5, "Hearts"));
        REQUIRE(deck1.getDeck()[1] == Card(3, "Hearts"));
    }
}

TEST_CASE("Operators") {
    SECTION(">>") {
        Deck deck1 = Deck::createFullDeck();
        Deck deck2;
        deck2 >> deck1;
        REQUIRE(deck1.getCount() == 51);
        REQUIRE(deck2.getCount() == 1);
        REQUIRE(deck2.getDeck()[0] == Card(13, "Spades"));
    }
    SECTION("[]") {
        Deck deck = Deck::createFullDeck();
        REQUIRE(deck[0] == Card(1, "Hearts"));
    }
    SECTION("+") {
        Deck deck1 = Deck::createFullDeck();
        Deck deck2 = Deck::createFullDeck();
        deck1 + deck2;
        REQUIRE(deck1.getDeck()[0] == Card(1, "Hearts"));
        REQUIRE(deck1.getDeck()[52] == Card(1, "Hearts"));
    }
    SECTION("copy =") {
        Card *cards = new Card[3];
        cards[0] = Card(5, "Hearts");
        cards[1] = Card(5, "Clubs");
        Deck deck1(2, cards);
        Deck deck2 = Deck::createFullDeck();
        deck1 = deck2;
        REQUIRE(deck1.getCount() == 52);
        REQUIRE(deck1.getDeck()[0] == Card(1, "Hearts"));
    }
    SECTION("move =") {
        Card *cards = new Card[3];
        cards[0] = Card(5, "Hearts");
        cards[1] = Card(5, "Clubs");
        Deck deck1(2, cards);
        Deck deck2 = Deck::createFullDeck();
        deck1 = std::move(deck2);
        REQUIRE(deck1.getCount() == 52);
        REQUIRE(deck1.getDeck()[0] == Card(1, "Hearts"));
    }
    SECTION(">>") { 
        Deck deck;
        unsigned int count = 0;
        Card card(2, "Hearts");
        std::stringstream ss; 
        ss << 1 << "\n" << card << "\n";        
        ss >> deck;
        REQUIRE(deck.getCount() == 1); 
        REQUIRE(deck.getDeck()[0] == Card(2, "Hearts")); 
    }
    SECTION("<<") {
        Card *cards = new Card[1];
        cards[0] = Card(2, "Hearts");
        Deck deck(1, cards);
        std::stringstream ss;
        ss << deck;
        std::string expectedOutput = "2\nHearts";
        REQUIRE(ss.str() == expectedOutput);
        delete[] cards;
    }
}