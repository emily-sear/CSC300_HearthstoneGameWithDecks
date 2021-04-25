#include "Hand.hpp"
#include <iostream>

Hand::Hand()
{
    this->theCards = new LinkedList();
}

void Hand::addCard(Card* c)
{
    this->theCards->addEnd(c);
}

void Hand::display()
{
    cout << "********* Hand *********" << endl;
    this->theCards->display();
    cout << "********* Hand *********" << endl;
}