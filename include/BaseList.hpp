#ifndef BaseList_hpp
#define BaseList_hpp
#include "BaseNode.hpp"
class BaseList
{
public:
    BaseNode *head;
    BaseList();
    ~BaseList();
    void addNewRowNode();
    void add(int value1, int value2);
    BaseNode *findPenultimate();
    int getSize();
    void changePositions(int position1, int position2);
    void getAverageListA();
    void getAverageListB();
    BaseNode* getNodeByIndex(int index);
};
#endif