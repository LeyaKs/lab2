#include "deck.h"
#include "deck.h"
#include "exceptions.h"

void Deck::outputDeck() {
    for (unsigned int i = 0; i < count; i++) {
        std::cout << deck[i].prettyFormat() << std::endl;
    }
}

Deck Deck::createRandomDeck() {
    unsigned int count_v = 0;
    std::vector<Card> deck1;
    std::cout << "Enter the number of cards" << std::endl;
    std::cin >> count_v;
    if (count_v < 1 || count_v > 52)
        throw Exception{"Wrong size of deck"};
    while(deck1.size() < count_v) { //for each
            Card cardName = Card::createRandomCard();
            if (std::find_if(deck1.begin(), deck1.end(), [cardName](const Card& card) {
                return (card.getRank() == cardName.getRank()) && (card.getSuit() == cardName.getSuit());
            }) == deck1.end()) {
                deck1.push_back(cardName);
            } 
    }
    return Deck(count_v, deck1);
}


Deck Deck::createFullDeck() {
    std::vector<Card> deck1;
    for (int i = 0; i < 13; i++) {
        for (int j = 0; j < 4; j++) {
            deck1.push_back(Card(i + 1, Card::suits[j]));
        }
    }
    return Deck(52, deck1);
}



void Deck::operator >> (Deck &deck1) {
    if (deck1.deck.empty())
        throw Exception("Deck is empty");
    deck.push_back(deck1.deck.back());
    deck1.deck.pop_back();
    count++;
    deck1.count -= 1;
}

Card& Deck::operator [] (int index) {
    return deck[index];
}

void Deck::operator + (Deck &deck1) {
    deck.insert(deck.end(), deck1.deck.begin(), deck1.deck.end());
    count += deck1.count;
}

Deck& Deck::operator=(Deck &deck1) {
    deck = deck1.deck;
    count = deck1.count;
    return *this;
}

std::istream & operator >> (std::istream &s, Deck &deck1) {
    int  count;
    std::string suit;
    s >> count;
    for (int i = 0; i < count; i++) { //for each
        // s >> rank >> suit;
        // deck1.deck.push_back(Card(rank, suit));
        std::cin >> deck1.deck[i];
        (deck1.count)++;

    } 
    if(s.bad()){
        s.setstate(std::ios::failbit);
    }
    return s;
}

std::ostream & operator << (std::ostream &s, Deck &deck1) {
    for (unsigned int i = 0; i < deck1.count; i++) {
        std::cout << deck1.deck[i];
        // s << deck1.deck[i].getRank();
        // s << deck1.deck[i].getSuit();
    }
    return s;
}





void Deck::addRandomCard() {
    Card cardName = Card::createRandomCard();
    deck.push_back(cardName);
    count++;
}

void Deck::removeCard(int index) {
    deck.erase(deck.begin() + index);
    count--;
}

void Deck::sortDeck() {
    std::sort(deck.begin(), deck.end(), [](const Card &card1, const Card &card2) {
         return card1.getSuit() != card2.getSuit() ? card1.getSuit() < card2.getSuit() : card1.getRank() < card2.getRank();});
}

void Deck::shuffleDeck() {
    std::random_shuffle(deck.begin(), deck.end());
}

bool Deck::checkingDups() {
  for (unsigned int i = 0; i < count; i++) {//for each
    for (unsigned int j = i + 1; j < count; j++) {
      if (deck[i].getRank() == deck[j].getRank() && deck[i].getSuit() == deck[j].getSuit()) {
        return true; 
      } 
    }
  }
  return false;
}


Deck Deck::groupSuits(std::string suitName) {
    Deck newDeck;
    for (unsigned int i = 0; i < count; i++) {//find func or for each
        if (deck[i].getSuit() == suitName) {
            newDeck.deck.push_back(deck[i]);
            (newDeck.count)++;
        }
    }
    return newDeck;
}