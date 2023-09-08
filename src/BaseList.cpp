/**
 * @file BaseList.cpp
 * @description Bu class rakamların tutulduğu listeleri tutmak için kullanılan
 *bir ana liste yapısıdır.
 * @course 1. Öğretim B grubu
 * @assignment 1. Ödev
 * @date K24.07.2023
 * @author Dilara Yavuz  dilara.yavuz@ogr.sakarya.edu.tr
 *         İbrahim Özmen
 */

#include "BaseList.hpp"
#include <iostream>
#include <string>
using namespace std;

BaseList::BaseList()
{
    this->head = 0;
};
BaseList::~BaseList()
{
    BaseNode *temp = head;
    while (temp != 0)
    {
        BaseNode *deleted = temp;
        temp = temp->next;
        delete deleted;
    }
}

BaseNode *BaseList::getNodeByIndex(int index)
{
    if (index >= 0 && index < getSize())
    {
        BaseNode *temp = head;
        int count = 0;
        if (head == 0)
        {
            cout << "BaseList is empty!";
        }
        while (count != index)
        {
            temp = temp->next;
            count++;
        }
        return temp;
    }
    else
    {
        cout << "Index is out of bound!";
        return 0;
    }
}
// Girilen konum A ve konum B değerleri için onlar ve birler basamağı
// rakamlarının yer değiştirmesi için kullanılan metod
void BaseList::changePositions(int positionA, int positionB)
{
    BaseNode *ptr1 = getNodeByIndex(positionA);
    LinkedList *listA1 = ptr1->listA; // Onlar basamağı
    BaseNode *ptr2 = getNodeByIndex(positionB);
    LinkedList *listB2 = ptr2->listB; // Birler basamağı
    // Listeleri değiştir
    ptr1->listA = listB2;
    ptr2->listB = listA1;
}
// Dosya okuma işlemi yapılırken her yeni satırda yeni bir BaseNode nesnesi üretilmeli
void BaseList::addNewRowNode()
{
    LinkedList *linkedListA = new LinkedList();
    LinkedList *linkedListB = new LinkedList();
    if (head == 0)
    {
        head = new BaseNode(linkedListA, linkedListB);
    }
    else
    {
        BaseNode *temp = head;
        while (temp->next != 0)
        {
            temp = temp->next;
        }
        temp->next = new BaseNode(linkedListA, linkedListB);
    }
}
void BaseList::add(int value1, int value2)
{
    BaseNode *temp = head;
    // insert(getSize(), value1,value2);
    while (temp->next != 0)
    {
        temp = temp->next;
    }
    temp->listA->add(value1);
    temp->listB->add(value2);
}
// sondan bir önceki düğümü bulur
BaseNode *BaseList::findPenultimate()
{
    if (head == 0)
        return 0;
    if (head->next == 0)
        return head;

    BaseNode *temp = head;
    while (temp->next->next != 0)
        temp = temp->next;
    return temp;
}
int BaseList::getSize()
{
    int length = 1;
    for (BaseNode *itr = head->next; itr != NULL; itr = itr->next)
    {
        length++;
    }
    return length;
}

void BaseList::getAverageListA()
{
    double average = 0;
    int count = 0;         // BaseList'teki bağlı liste sayısını tutan değişken
    BaseNode *temp = head; // BaseList'i dolaşmak için geçici pointer
    while (temp != NULL)
    {                      // BaseList'in sonuna gelene kadar
        count++;           // Bağlı liste sayısını arttır
        temp = temp->next; // Sonraki baseList düğümüne ilerle
    }
    int index = 0;     // Bağlı listelerin hangi elemanlarını topladığımızı tutan değişken
    bool done = false; // Tüm bağlı listelerin sonuna gelip gelmediğimizi tutan değişken
    while (!done)
    {                       // Tüm bağlı listelerin sonuna gelene kadar
        done = true;        // Varsayılan olarak done'u true yap
        int sum = 0;        // Toplamı tutan değişken
        int validCount = 0; // Geçerli bağlı liste sayısını tutan değişken
        temp = head;        // BaseList'i dolaşmak için geçici pointer
        while (temp != NULL)
        {                                      // BaseList'in sonuna gelene kadar
            Node *current = temp->listA->head; // Bağlı listenin başlangıç düğümünü tutan pointer
            for (int i = 0; i < index; i++)
            { // İndekse göre ilerle
                if (current != NULL)
                {                            // Bağlı listenin sonuna gelmediysek
                    current = current->next; // Sonraki düğüme ilerle
                }
            }
            if (current != NULL)
            {                         // Bağlı listenin sonuna gelmediysek
                sum += current->data; // Toplama düğümdeki rakamı ekle
                validCount++;         // Geçerli bağlı liste sayısını arttır
                done = false;         // done'u false yap, çünkü daha bitmedi
            }
            temp = temp->next; // Sonraki baseList düğümüne ilerle
        }
        if (!done)
        { // Eğer bitmediysek
            average += (double)sum / validCount;
            // Ortalamayı hesapla, geçerli bağlı liste sayısına böl
            index++; // İndeksi arttır
        }
    }
    cout << "Ust: " << average << endl; // Ortalamayı yazdır
}
void BaseList::getAverageListB()
{
    double average = 0;
    int count = 0;
    BaseNode *temp = head;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    int index = 0;
    bool done = false;
    while (!done)
    {
        done = true;
        int sum = 0;
        int validCount = 0;
        temp = head;
        while (temp != NULL)
        {
            Node *current = temp->listB->head;
            for (int i = 0; i < index; i++)
            { // İndekse göre ilerle
                if (current != NULL)
                {
                    current = current->next;
                }
            }
            if (current != NULL)
            {
                sum += current->data;
                validCount++;
                done = false;
            }
            temp = temp->next;
        }
        if (!done)
        {
            average += (double)sum / validCount;
            index++;
        }
    }
    cout << "Alt: " << average << endl;
}