#include "Node.hpp"

class LinkedList
{
    private:
        Node* head;
        Node* tail;
        int count;
        Node* get(int index);


    public:
        LinkedList();
        void addEnd(Card* c);
        void display();
        int getCount();
        void insertionSortOnDefense();
        void swap(int index1, int index2);
        void swapPayload(int index1, int index2);
        Card* removeFront();
};
