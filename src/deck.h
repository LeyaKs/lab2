#pragma once

#include <vector>
#include "card.h"

#define MAX_SIZE 52

class Deck {
    Card *deck;
    unsigned int count;
    unsigned int capacity;
    public:
        Deck() {
            count = 0;
            capacity = MAX_SIZE;
            deck = new Card[MAX_SIZE];
        }
        Deck(unsigned int count1, Card *deck1) {
            count = count1;
            capacity = std::max((unsigned int)MAX_SIZE, count);
            deck = new Card[count];
            std::copy(deck1, deck1 + count, deck);
        }

        Deck(const Deck& deck1) {
            count  = deck1.count;
            capacity  = deck1.capacity;
            // capacity = MAX_SIZE;
            deck = new Card[count];
            std::copy(deck1.deck, deck1.deck + count, deck);
        }

        Deck(Deck &&deck1) {
            count = deck1.count;
            capacity  = deck1.capacity;
            deck = deck1.deck;
            deck1.count = 0;
            deck1.deck = nullptr;
        }


        static Deck createRandomDeck();
        static Deck createFullDeck();
        void outputDeck();

        void operator >> (Deck&);
        Card &operator [] (unsigned int);
        void operator + (Deck&);
        Deck& operator = (Deck&);
        Deck& operator=(Deck&&);
        friend std::istream & operator >>(std::istream&, Deck&);
        friend std::ostream & operator <<(std::ostream&, Deck&);



        void addRandomCard();
        void removeCard(int);
        void sortDeck();
        void shuffleDeck();
        bool checkingDups();
        Deck groupSuits(std::string);

        void resize();

        ~Deck() {
            delete[] deck;
        }
};