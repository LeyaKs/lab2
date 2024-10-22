/**
 * \file
 * \brief Header file with description of functions of class deck
 */


#pragma once

#include <vector>
#include "card.h"

#define MAX_SIZE 52

/**
 * \class
 * \brief Class Deck with functions
 * 
 * Contains the count, capacity, array of cards, constructors, destructors, functions and operators
 */
class Deck {
    Card *deck;
    unsigned int count;
    unsigned int capacity;
    public:
        Deck() {
            count = 0;
            capacity = 0;
            deck = new Card[0];
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

    /**
     * \brief Creating a random deck
     * \return new random Deck
     */
        static Deck createRandomDeck();

    /**
     * \brief Creating a full deck
     * \return new full Deck
     * 
     * Using MAX_SIZE to create full deck
     */
        static Deck createFullDeck();

    /**
         * \brief Deck output
         */
        void outputDeck();


    /**
         * \brief The operator of transferring a card from one deck to another
         * \param The deck from which to catch a card
         */
        void operator >> (Deck&);


    /**
         * \brief The operator for taking an element by index
         * \param Index
         * \return Card with our index
         */
        Card &operator [] (unsigned int);


    /**
         * \brief The operator for adding two decks
         * \param Deck, which we need o add
         * \return New deck, result of sum
         */
        void operator + (Deck&);

    /**
         * \brief The copying operator
         * \param The deck to be copied
         * \return New deck, result of sum
         */ 
        Deck& operator = (Deck&);
        Deck& operator=(Deck&&);
        friend std::istream & operator >>(std::istream&, Deck&);
        friend std::ostream & operator <<(std::ostream&, Deck&);


    /**
         * \brief Adding a new random card
         * 
         * If we don't have enough space in the deck, we expand it
         */
        void addRandomCard();

    /**
         * \brief Deleting a card by index
         * \param index
         * 
         * If we have a lot of space in the deck, reduce it
         */
        void removeCard(int);

        /**
             * \brief Sorting deck
             */
        void sortDeck();

        /**
             * \brief Shuffle deck
             */
        void shuffleDeck();

        /**
             * \brief Checking duplicates in deck
             * \return bool value
             */
        bool checkingDups();

        /**
             * \brief Grouping the deck by suit
             * \param name of suit
             * \return A group of cards of the same suit
             */
        Deck groupSuits(std::string);

        /**
             * \brief Resize deck, adding memory
             */
        void resize();

        /**
             * \brief Resize deck, reduce array
             */
        void reduce();

        /**
             * \brief Get the number of cards
             * \return Count
             */
        unsigned int getCount() const { return count; }

        /**
             * \brief Get deck
             * \return Array of cards
             */
        Card *getDeck() const { return deck; }

        ~Deck() {
            delete[] deck;
        }
};