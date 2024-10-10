#pragma once

#include <vector>
#include "card.h"

class Deck {
    std::vector<Card> deck;
    unsigned int count;
    public:
        Deck() {}
        Deck(unsigned int count1, std::vector<Card> deck1) {
            count = count1;
            deck = std::move(deck1);
        }
        Deck(const Deck& deck1) : deck(deck1.deck), count(deck1.count) {}


        static Deck createRandomDeck();
        static Deck createFullDeck();
        void outputDeck();

        void operator >> (Deck&);
        Card &operator [] (int);
        void operator + (Deck&);
        Deck& operator = (Deck&);
        friend std::istream & operator >>(std::istream&, Deck&);
        friend std::ostream & operator <<(std::ostream&, Deck&);



        void addRandomCard();
        void removeCard(int);
        void sortDeck();
        void shuffleDeck();
        bool checkingDups();
        Deck groupSuits(std::string);
};