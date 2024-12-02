// #include "QuickSorter.h"
// #include "BubbleSorter.h"
// #include "PiramidSorter.h"
// #include "MergeSorter.h"
// #include "InsertionSorter.h"
// #include "ShellSorter.h"
// #include "BitonicSorter.h"
// #include "ListSequence.h"
// #include "ArraySequence.h"
// #include "DynamicArray.h"
// #include "Person.h"
 //#include "GetNamesAndSournamesToMyString.h" 
 #include "MyString.h"
// #include "WriteIntToFile.h"
 //#include "WritePersonToFile.h"
//#include <iostream>
// #include <fstream>
//#include "UnitTests.h"
//#include "Sequence.h"
//#include "ArraySequence.h"
//#include "WriteIntToFile.h"
#include "ArraySequence.h"
//#include  "FileTest.h"
//#include "Comporators.h"
//#include "BubbleSorter.h"
//#include "LoadTestDynamicArrayIntFile.h"
//#include "LoadTestFromFilePerson.h"
//#include "StartLoadTests.h"
//#include "UnitTests.h"
//#include <QApplication>
#include <iostream>
#include "BubbleSorter.h"
#include "MergeSorter.h"
#include "Comporators.h"
#include "UnitTests2.h"




int main(int argc, char** argv)
{
    //int arr[12] = {1, 3, 0, 2211, -3, -4, -7, 0, 0, 0, 1, 5};
    //Sequence<int>* seq = new MutableArraySequence<int>(arr, 12);
    //QuickSorter<int> QSorter(cmp);
    //QSorter.Sort(seq);
    //BubbleSorter<int> BSorter(cmp);
    //BSorter.Sort(seq);
   // PiramidSorter<int> PSorter(cmp);
    //PSorter.Sort(seq);
    //MergeSorter<int> mSorter(cmp);
    //mSorter.Sort(seq);
    //InsertionSorter<int> iSorter(cmpInt);
    //iSorter.Sort(seq);
    //ShellSorter<int> sSorter(cmpInt);
    //sSorter.Sort(seq);
    //BitonicSorter<int> bSorter(cmpInt);
    //bSorter.Sort(seq);
    //Person p1;
    //std::cin >> p1;
    //MyString str;
    //std::cin >> str;
    //std::cout << str;
    //std::cout << p1;
    //Sequence<int>* seq2 = seq->GetNewSequence(35);
    //delete seq2;
    //delete seq;
    // DynamicArray<MyString>* arrNames = GetSurnamesToMyString();
    // for(int i = 0; i < arrNames->GetCapacity(); i++)
    // {
    //     std::cout << arrNames->Get(i) << std::endl << arrNames->Get(i).GetLength();
    // }
    // delete arrNames;
    //MyString string = MyString::IntToMyString(-100);

    //td::cout << string;
    //WriteIntToFile(100500);
    /*DynamicArray<MyString> *Names = nullptr;
    DynamicArray<MyString> *Surnames = nullptr;
    Names = GetNamesToMyString();
    Surnames = GetSurnamesToMyString();*/
    /*for(int i = 32; i <= 1000000; i*=2)
    {
        WriteIntToFile(i);
       try{
        
        //WritePersonToFile(i, Names, Surnames);
        }
        catch(char const* sh)
        {
            std::cout << sh;
        }
    }*/
        /*try{
        //Names = GetNamesToMyString();
        //Surnames = GetSurnamesToMyString();
        //WritePersonToFile(99882960, Names, Surnames);
        //delete Names;
        //delete Surnames;
        WriteIntToFile(i);
        }
        catch(char const* sh)
        {
            std::cout << sh;
        }*/
    
   //std::cout << argv[0];
    //UnitTests();
    //UnitTests();
    //std::cout << "HELLO NAHUI" << std::endl;
    /*Sequence<Person*> *seq = new MutableArraySequence<Person*>;
    MyString strName("GeneratedPerson1000");
    BubbleSorter<Person*> sort(cmpPointerPerson);
    double time;
    try{
        time = LoadTestFromFilePerson(strName, seq, &sort);
        //time = LoadTestDynamicArrayIntFile(strName);
    }
    catch(const char * str)
    {
        std:: cout << str;
    }
    delete seq;

     std::cout << std::endl << "time : " << time << std::endl;*/
   //QApplication a(argc, argv);
    
    //StartLoadTests();
   
    //return a.exec();
    /*int arr[5] = {1, 2, 3, -1, -100};
    MutableArraySequence<int> seq(arr, 5);

    Sequence<int>* ptr = new MutableArraySequence<int>(arr, 5);

    MergeSorter<int> mSorter(cmpInt);
    mSorter.Sort((*ptr));

    for(int i = 0; i < ptr->GetLength(); i++)
    {
        std::cout << ptr->Get(i) << std::endl;
    }*/
   //UnitTestsInt2();
   UnitTestsPerson2();
    /*while(1){
    char buf[41];
    std::cout << "input string" << std::endl;
    std::cin >>buf;
    double d = foo(buf);
    std::cout << "double is = " << d << std::endl;

    }*/

    

}