#ifndef FileOperator_hpp
#define FileOperator_hpp
#include <iostream>
#include "BaseList.hpp"
#include <fstream>
#include <sstream>
#include <string>
class FileOperator
{
public:
    void createListsFromFile(string fileName);
    void start(string fileName);
    FileOperator();
    ~FileOperator();
    BaseList *baseList;
    
};

#endif