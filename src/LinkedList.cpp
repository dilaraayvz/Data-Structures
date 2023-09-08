/** 
* @file LinkedList.cpp
* @description Bu class rakamların tutulduğu listeleri tutmak için kullanılan
*bir ana liste yapısıdır.
* @course 1. Öğretim B grubu
* @assignment 1. Ödev
* @date K24.07.2023
* @author Dilara Yavuz  dilara.yavuz@ogr.sakarya.edu.tr
*         İbrahim Özmen
*/
#include "LinkedList.hpp"
#include <iostream>
using namespace std;
LinkedList::LinkedList()
{
    head = 0;
}
LinkedList::~LinkedList()
{
    Node *temp = head;
    while (temp != 0)
    {
        Node *deleted = temp;
        temp = temp->next;
        delete deleted;
    }
}

void LinkedList::add(int data)
{
    Node *newNode = new Node(data);

    if (head == 0)
    {
        head = newNode;
        return;
    }
    Node *temp = head;
    while (temp->next != 0)
        temp = temp->next;

    temp->next = newNode;
}
Node *LinkedList::findPenultimate()
{
    if (head == 0)
        return 0;
    if (head->next == 0)
        return head;

    Node *temp = head;
    while (temp->next->next != 0)
        temp = temp->next;
    return temp;
}
int LinkedList::getSize()
{
    int length = 1;
    for (Node *itr = head->next; itr != NULL; itr = itr->next)
    {
        length++;
    }
    return length;
}