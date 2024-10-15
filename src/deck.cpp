#include "deck.h"
#include "deck.h"
#include "exceptions.h"
#include <algorithm>

#define MAX_SIZE 52

void Deck::outputDeck() {
    for (unsigned int i = 0; i < count; i++) {
        std::cout << deck[i].prettyFormat() << std::endl;
    }
}

Deck Deck::createRandomDeck() {
    unsigned int count_v = 0, currSize = 0;
    Deck deck1 = Deck();
    std::cout << "Enter the number of cards from 1 to " << MAX_SIZE <<  std::endl;
    std::cin >> count_v;
    while (count_v < 1 || count_v > MAX_SIZE) {
            std::cout << "Try again" << std::endl;
            std::cin >> count_v;
    }
    deck1.count = count_v;
    while(currSize < count_v) {
            Card cardName = Card::createRandomCard();
            if ((currSize == 0) || (std::find(deck1.deck, deck1.deck + currSize, cardName)  == (deck1.deck + currSize))) {
                deck1.deck[currSize] = cardName;
                currSize++;
            } 
    }
    return deck1;
}


Deck Deck::createFullDeck() {
    unsigned int currSize = 0;
    Deck deck1 = Deck();
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
    // if (deck1.deck == nullptr)
        // throw Exception("Deck is empty");
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
    // delete[] deck1.deck;
    deck = newDeck;
    count += deck1.count;
    // deck1.deck = nullptr;
}

Deck& Deck::operator=(Deck &deck1) {
    delete[] deck;
    deck = deck1.deck;
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
        std::cin >> card;
        newDeck[currSize] = card;
        currSize++;
    }
    delete[] deck1.deck;
    deck1.deck = newDeck;
    deck1.count = count;
    if(s.bad()){
        s.setstate(std::ios::failbit);
    }
    return s;
}

std::ostream & operator << (std::ostream &s, Deck &deck1) {
    std::for_each (deck1.deck, deck1.deck + deck1.count, [](Card &card){
        std::cout << card;
    });
    return s;
}





void Deck::addRandomCard() {
    if (count == capacity)
        resize();
    Card cardName = Card::createRandomCard();
    deck[count] = cardName;
    count++;
}

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
        capacity *= 2;
        Card* newDeck = new Card[capacity]; 
        std::copy(deck, deck + count, newDeck); 
        delete[] deck;
        deck = newDeck;
}