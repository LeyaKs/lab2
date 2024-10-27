# Description of the project
### This project consists of two classes, a card and a deck. The first describes the functions for working with the card, the second describes the actions on the deck.

# Description of the repository

## main.cpp ## ------- the base file for using classes<br>
## src ## ------- the folder with the rest of the auxiliary files<br>
## card.h ## ------- description of the card class<br>
## card.cpp ## ------- implementation of card class functions
## deck.h ## ------- description of the deck class<br>
## deck.cpp ## ------- implementation of deck class functions<br>
## dialogue.h ## -------description of functions for communicating with the user<br>
## dialogue.cpp ## ------- implementation of functions for communication with the user<br>
## input.h ## -------description of input functions<br>
## input.cpp ## ------- implementation of input functions<br>
## test.cpp ## ------- checking the correctness of the functions<br>

# Program launch

## To run this project, you need to run the script from the root directory of the project:
```
cd build
cmake .
make
./lab2
```

# Test launch
## To run the tests and see the coverage for the developed classes, you need to run the following script from the root directory of the project:
```
cd src
g++ --coverage *.cpp -o tests
./tests
gcovr
```
## The last command is executed only after passing the tests
