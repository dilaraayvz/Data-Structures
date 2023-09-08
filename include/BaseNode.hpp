#ifndef BaseNode_hpp
#define BaseNode_hpp
#include "LinkedList.hpp"
using namespace std;
class BaseNode
{
public:
    BaseNode(LinkedList* listA, LinkedList* listB);
    LinkedList* listA;
    LinkedList* listB;
    BaseNode* next;
};
#endif