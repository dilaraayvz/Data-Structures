#ifndef LinkedList_hpp
#define LinkedList_hpp
#include "Node.hpp"
class LinkedList
{
public:
    LinkedList();
    ~LinkedList();
    void add(int data);
    Node *findPenultimate();
    int getSize();
    Node *head;
    
};

#endif