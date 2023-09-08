/** 
* @file FileOperator.cpp
* @description Bu class rakamların tutulduğu listeleri tutmak için kullanılan
*bir ana liste yapısıdır.
* @course 1. Öğretim B grubu
* @assignment 1. Ödev
* @date K24.07.2023
* @author Dilara Yavuz  dilara.yavuz@ogr.sakarya.edu.tr
*         İbrahim Özmen
*/
#include "FileOperator.hpp"
FileOperator::FileOperator(){
    this->baseList=0;
}
FileOperator::~FileOperator(){
    delete baseList; 
}
void FileOperator::createListsFromFile(string fileName){
 ifstream file(fileName); // dosyayı aç
    if (!file)
    {
        cerr << "Text file couldn't open!\n";
        return;
    }
    baseList = new BaseList(); // Sayıların gösterileceği ana bir liste oluşturuldu

    string row;                // her satır için bir string değişkeni
    int rowNo = 0;             // hangi satırda olduğumuzu tutan bir sayaç
    while (getline(file, row)) // dosyadan bir satır oku
    {
        baseList->addNewRowNode();

        stringstream ss(row); // string'i stringstream'e dönüştür
        int number;           // her sayı için bir int değişkeni
        // int sum = 0; // her satırın toplamını tutan bir değişken
        while (ss >> number) // stringstream'den bir sayı oku
        {
            int onlarBasamagi = number / 10;
            int birlerBasamagi = number % 10;
            baseList->add(onlarBasamagi, birlerBasamagi);
        }
        rowNo++; // satır sayısını arttır
    }
}

void FileOperator::start(string fileName){
    createListsFromFile(fileName);
    string konumA="";
    string konumB="";
    cout<<"Konum A: ";
    cin>>konumA;
    cout<<endl<<"Konum B:";
    cin>>konumB;
    baseList->changePositions(stoi(konumA), stoi(konumB));
    cout<<endl<<endl;
    baseList->getAverageListA();
    baseList->getAverageListB();
}