#include <iostream>
#include <cctype> //for tolower

using namespace std;

#include "Card.h"

Card::Card(){
    suit = 'c';
    rank = 2;
}

Card::Card(char s, int r){
    s = tolower(s);

    if (s == 'c' || s == 'h' || s == 's' || s == 'd'){
        suit = s;
    }
    else {
        suit = 'c';
    }

    if (r < 14 && r > 0){
        rank = r;
    }
    else {
        rank = 2;
    }
}

char Card::getSuit() const{
    return suit;
}

int Card::getRank() const{
    return rank;
}

ostream & operator <<(ostream & out, const Card & currCard){
    if (currCard.rank > 1 && currCard.rank < 11){
        out << currCard.rank;
    }
    else if(currCard.rank == 1){
        out << "Ace";
    }
    else if(currCard.rank == 11){
        out << "Jack";
    }
    else if(currCard.rank == 12){
        out << "Queen";
    }
    else {
        out << "King";
    }
    
    out << " of ";

    if (currCard.suit == 'c'){
        out << "Clubs";
    } 
    else if (currCard.suit == 's'){
        out << "Spades";
    } 
    else if (currCard.suit == 'h'){
        out << "Hearts";
    } 
    else{
        out << "Diamonds";
    } 

    return out;
}