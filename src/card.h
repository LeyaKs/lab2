/**
 * \file
 * \brief Header file with description of functions of class card
 */


#pragma once

#include <iostream>


/**
 * \class
 * \brief Class Card with functions
 * 
 * Contains the rank and suit fields, constructors, destructors, functions and operators
 */

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
        

        /**
             * \brief Creating a random card
             * \param none
             * \return new random Card
             */
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

        /**
             * \brief Output card
             */
        void outputCard();

        /**
             * \brief Getting data to create card 
             * \return New card
             */
        Card inputCard();


        /**
             * \brief Сomparison operator
             * \param Card to compare
             * \return Bool value
             */
        bool operator == (const Card&) const;
        bool operator < (const Card&) const;

        /**
           * \brief Input operator
           */ 
        friend std::istream & operator >>(std::istream&, Card&);

        /**
           * \brief Output operator
           */ 
        friend std::ostream & operator <<(std::ostream&, Card&);

        /**
             * \brief Creating a string with beautiful style
             * \param none
             * \return a string in a pretty format
             */
        std::string prettyFormat();
};