#include <iostream>
#include "./src/card.h"
#include "./src/deck.h"

using std::cout;
using std::cin;
using std::string;
using std::endl;

int main() {
  Deck deck1 = Deck::createRandomDeck();
  Deck deck2 = Deck::createRandomDeck();
  deck1.outputDeck();
  cout<< endl;
  deck2.outputDeck();
  deck1 + deck2;
  cout<< endl;
  deck1.outputDeck();
  cout<< endl;
  deck2.outputDeck();
  return 0;
}