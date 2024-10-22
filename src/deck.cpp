/**
 * \file
 * \brief File with class deck
 * 
 * This file contains the definition of the class deck and the main
functions used in it
 */

#include "deck.h"
#include "dialogue.h"
#include <algorithm>

/**
 * \brief Number of cards in the full deck
 */
#define MAX_SIZE 52


/**
     * \brief Deck output
     * \param none
     * \return none
     */

void Deck::outputDeck() {
    for (unsigned int i = 0; i < count; i++) {
        std::cout << deck[i].prettyFormat() << std::endl;
    }
}


/**
     * \brief Creating a random deck
     * \param none
     * \return new random Deck
     */
Deck Deck::createRandomDeck() {
    unsigned int currSize = 0;
    Deck deck1 = Deck();
    if (deck1.count == deck1.capacity) deck1.resize();
    deck1.count = createRandomDeckDialogue();
    while(currSize < deck1.count) {
            Card cardName = Card::createRandomCard();
            if ((currSize == 0) || (std::find(deck1.deck, deck1.deck + currSize, cardName)  == (deck1.deck + currSize))) {
                deck1.deck[currSize] = cardName;
                currSize++;
            } 
    }
    return deck1;
}

/**
     * \brief Creating a full deck
     * \param none
     * \return new full Deck
     * 
     * Using MAX_SIZE to create full deck
     */
Deck Deck::createFullDeck() {
    unsigned int currSize = 0;
    Deck deck1 = Deck();
    if (deck1.count == deck1.capacity) deck1.resize();
    deck1.count = MAX_SIZE;
    for (int i = 0; i < 13; i++) {
        for (int j = 0; j < 4; j++) {
            deck1.deck[currSize] = Card(i + 1, Card::suits[j]);
            currSize++;
        }
    }
    return deck1;
}



void Deck::operator >> (Deck &deck1) {
    if (count == capacity)
        resize();
    deck[count] = deck1.deck[deck1.count - 1];
    count++;
    deck1.count -= 1;
}

Card& Deck::operator [] (unsigned int index) {
    return deck[index];
}

void Deck::operator + (Deck &deck1) {
    while (count + deck1.count > capacity) { 
        resize();
    }
    Card *newDeck = new Card[count + deck1.count];
    std::copy(deck, deck + count, newDeck);
    std::copy(deck1.deck, deck1.deck + deck1.count, newDeck + count);
    delete[] deck; 
    deck = newDeck;
    count += deck1.count;
}

Deck& Deck::operator = (Deck &deck1) {
    if (count == capacity) resize();
    Card* newDeck = new Card[deck1.count];
    std::copy(deck1.deck, deck1.deck + deck1.count, newDeck);
    delete[] deck;
    deck = newDeck;
    count = deck1.count;
    deck1.deck = nullptr;
    return *this;
}

Deck& Deck::operator=(Deck &&deck1) {
    std::swap(deck1.deck, deck);
    std::swap(deck1.count, count);
    return *this;
}


std::istream & operator >> (std::istream &s, Deck &deck1) {
    unsigned int  count = 0, currSize = 0;
    std::string suit;
    s >> count;
    Card *newDeck = new Card[count];
    for (unsigned int i = 0; i < count; ++i) {
        Card card;
        s >> card;
        newDeck[currSize] = card;
        currSize++;
    }
    delete[] deck1.deck;
    deck1.deck = newDeck;
    deck1.count = count;
    if(s.bad()) s.setstate(std::ios::failbit);
    return s;
}

std::ostream & operator << (std::ostream &s, Deck &deck1) {
    std::for_each (deck1.deck, deck1.deck + deck1.count, [&s](Card &card){
        s << card;
    });
    return s;
}



/**
     * \brief Adding a new random card
     * \param none
     * \return none
     * 
     * If we don't have enough space in the deck, we expand it
     */

void Deck::addRandomCard() {
    if (count == capacity)
        resize();
    Card cardName = Card::createRandomCard();
    deck[count] = cardName;
    count++;
}


/**
     * \brief Deleting a card by index
     * \param index
     * \return none
     * 
     * If we have a lot of space in the deck, reduce it
     */
void Deck::removeCard(int index) {
    for (unsigned int i = index; i < count - 1; i++) {
        deck[i] = deck[i + 1];
    }
    count--;
}

void Deck::sortDeck() {
    std::sort(deck, deck + count, [](const Card &card1, const Card &card2) {
         return card1.getSuit() != card2.getSuit() ? card1.getSuit() < card2.getSuit() : card1.getRank() < card2.getRank();});
}

void Deck::shuffleDeck() {
    std::random_shuffle(deck, deck + count);
}

bool Deck::checkingDups() {
    for (unsigned int i = 0; i < count; i++) {
        for (unsigned int j = i + 1; j < count; j++) {
        if (deck[i].getRank() == deck[j].getRank() && deck[i].getSuit() == deck[j].getSuit()) {
            return true; 
        } 
        }
    }
  return false;
}



Deck Deck::groupSuits(std::string suitName) {
    Deck newDeck = Deck();
    std::for_each(deck, deck + count, [&suitName, &newDeck] (Card &card) {
        if (card.getSuit() == suitName) {
            if (newDeck.count == newDeck.capacity)
                    newDeck.resize();
            newDeck[newDeck.count] = card;
            (newDeck.count)++;
        }
    });
    return newDeck;
}


void Deck::resize() {
        capacity += 52;
        Card* newDeck = new Card[capacity]; 
        std::copy(deck, deck + count, newDeck); 
        delete[] deck;
        deck = newDeck;
}