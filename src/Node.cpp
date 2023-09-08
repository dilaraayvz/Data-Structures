/** 
* @file Node.cpp
* @description Bu class rakamların tutulduğu listeleri tutmak için kullanılan
*bir ana liste yapısıdır.
* @course 1. Öğretim B grubu
* @assignment 1. Ödev
* @date K24.07.2023
* @author Dilara Yavuz  dilara.yavuz@ogr.sakarya.edu.tr
*         İbrahim Özmen
*/
#include"Node.hpp"
#include <iostream>
using namespace std;
Node::Node(int data){
this->data=data;
this->next=0;
}