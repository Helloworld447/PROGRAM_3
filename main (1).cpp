#include <iostream>
#include <cstdlib>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>

using namespace std;

#include "Deck.h"
#include "Card.h"

// Returns true if vector of Cards passed in contains at least 2 Cards with the same rank.
bool hasPair(const vector<Card> &hand);

// Sends to output stream a hand of Cards on a single line, 
// each Card separated by a comma.
// If the vector is empty, do not output anything.
// Example (vector size of 3): Ace of Spades, Two of Hearts, King of Clubs 
ostream & operator<<(ostream & out, const vector<Card> & hand);

void OutputFile(ofstream & outFS, const string &file, const vector <Card> & hand);

int main() {
    srand(2222);
    string response;
    string file;
    unsigned int cards;
    unsigned int n;
    vector <Card> hand; 
    Deck currDeck;
    Card currCard;
    int count = 0;
    double percentage;
    ofstream outFS;

    cout << "Do you want to output all hands to a file? (Yes/No) " << endl;

    cin >> response;

    if (response == "Yes"){
        cout << "Enter name of output file: " << endl;
        cin >> file;
        

        outFS.open(file);
    }

    cout << "Enter number of cards per hand: " << endl;

    cin >> cards;

    cout << "Enter number of deals (simulations): " << endl;

    cin >> n;

    for (unsigned int i = 0; i < n; i++){
        currDeck.shuffleDeck();
    
        for (unsigned int j = 0; j < cards; j++){
            currCard = currDeck.dealCard();
            hand.push_back(currCard);
        }

        if(hasPair(hand)){
            count += 1;
        }
        if (response == "Yes"){
            OutputFile(outFS, file, hand);
        }

        hand.clear();
    }

    if (response == "Yes"){
        outFS.close();
    }

    percentage = (static_cast<double> (count)/ static_cast<double> (n)) * 100.0;
    
    cout << "Chances of receiving a pair in a hand of " << cards << " cards is: " << percentage << "%" << endl;
    
    return 0;
}

bool hasPair(const vector<Card> & hand){ 
    for (unsigned int i = 0; i < hand.size(); i++){

      for (unsigned int j = i + 1; j < hand.size(); j++){
         if (hand.at(i).getRank() == hand.at(j).getRank()){
            return true;
         }
      }
    }

    return false;
}

ostream & operator<<(ostream & out, const vector<Card> & hand){
    for (unsigned i = 0; i < hand.size(); i++){
        out << hand.at(i);
        if (i < hand.size() - 1){
            out << ", ";
        }
    }

    return out;
}

void OutputFile(ofstream & outFS, const string &file, const vector <Card> & hand){
    if(hasPair(hand)){
        outFS << "Found Pair!! ";
    }
    else{
        outFS << "             ";
    }

    outFS << hand << endl;
}