#include <iostream>
#include <string>
#include "Deck.hpp"
#include "Hand.hpp"

using namespace std;

int main(int argc, char** argv)
{
    Deck* theDeck = new Deck();
    Hand* h1 = new Hand();
    Hand* h2 = new Hand();
    theDeck->shuffle();
    //theDeck->display();
    
    for(int i = 0; i < 5; i++)
    {
        h1->addCard(theDeck->dealCard());
        h2->addCard(theDeck->dealCard());
    }

    h1->display();
    h2->display();

    return 0;
}