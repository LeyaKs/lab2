#include <iostream>
#include "./src/card.h"
#include "./src/deck.h"

using std::cout;
using std::cin;
using std::string;
using std::endl;
int main() {
  Deck deck1 = Deck::createRandomDeck();
  deck1.outputDeck();
  Deck deck2 = deck1.groupSuits("Hearts");
  cout << endl;
  deck2.outputDeck();
  return 0;
}
