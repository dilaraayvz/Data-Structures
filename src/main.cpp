/**
 * @file main.cpp
 * @description Bu class rakamların tutulduğu listeleri tutmak için kullanılan
 *bir ana liste yapısıdır.
 * @course 1. Öğretim B grubu
 * @assignment 1. Ödev
 * @date K24.07.2023
 * @author Dilara Yavuz  dilara.yavuz@ogr.sakarya.edu.tr
 *         İbrahim Özmen
 */
#include <iostream>
#include "BaseList.hpp"
#include "FileOperator.hpp"
#include <fstream>
#include <sstream>
#include <string>
using namespace std;
int main()
{
    FileOperator* fileOperator=new FileOperator();
    fileOperator->start("Sayilar.txt");
    delete fileOperator;
}
