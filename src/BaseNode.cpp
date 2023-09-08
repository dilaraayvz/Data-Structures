/** 
* @file BaseNode.cpp
* @description Bu class rakamların tutulduğu listeleri tutmak için kullanılan
*bir ana liste yapısıdır.
* @course 1. Öğretim B grubu
* @assignment 1. Ödev
* @date K24.07.2023
* @author Dilara Yavuz  dilara.yavuz@ogr.sakarya.edu.tr
*         İbrahim Özmen
*/
#include"BaseNode.hpp"
#include <iostream>
using namespace std;
BaseNode::BaseNode(LinkedList* listA, LinkedList* listB){
this->listA=listA;
this->listB=listB;
this->next=0;
}