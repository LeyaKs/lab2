#pragma once

#include <iostream>


class Card {
    unsigned int rank;
    std::string suit;
    public:
        static std::string suits[];
        Card() {
            rank = 1;
            suit = "Hearts";   
        }

        Card(unsigned int rank_value, std::string suit_value) {
            rank = rank_value;
            suit = suit_value;
        }
        
        static Card createRandomCard();

        unsigned int getRank() const {return rank;}
        std::string getSuit() const {return suit;}

        Card &setRank(const unsigned int rank_value) {
            rank = rank_value;
            return *this;
        }
        Card &setSiut(const std::string suit_value) {
            suit = suit_value;
            return *this;
        }

        Card inputCard();
        void outputCard();

        bool operator == (const Card&) const;
        bool operator < (const Card&) const;
        friend std::istream & operator >>(std::istream&, Card&);
        friend std::ostream & operator <<(std::ostream&, Card&);

        std::string prettyFormat();
};