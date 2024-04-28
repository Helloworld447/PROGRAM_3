#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#include "Deck.h"

Deck::Deck(){
    char temp;
    vector <Card> v;
    
    for (int i = 0; i < 4; i++){
        if (i == 0){
            temp = 'c';
        }
        else if (i == 1){
            temp = 'd';
        }
        else if (i == 2){
            temp = 'h';
        }
        else{
            temp = 's';
        }
        for (int j = 1; j < 14; j++){           
            Card currCard(temp, j);
            v.push_back(currCard);
        }
    }

    for (int i = v.size() - 1; i > -1; i--){
        theDeck.push_back(v.at(i));
    }

}

Card Deck::dealCard(){
    Card required; 
    required = theDeck.back();
    dealtCards.push_back(required);
    theDeck.pop_back();

    return required;
}

void Deck::shuffleDeck(){
    for (unsigned i = 0; i < dealtCards.size(); i++){
        theDeck.push_back(dealtCards.at(i));
    }
    dealtCards.clear();

    random_shuffle(theDeck.begin(), theDeck.end());
}

unsigned Deck::deckSize() const{
    return theDeck.size();
}