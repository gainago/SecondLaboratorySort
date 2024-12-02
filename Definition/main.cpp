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
#include <QApplication>
#include <iostream>
#include "BubbleSorter.h"
#include "MergeSorter.h"
#include "Comporators.h"
#include "UnitTests2.h"
#include "LoadTestsSorted.h"
#include "LoadTestsReversedSorted.h"




int main(int argc, char** argv)
{
    QApplication app(argc, argv);
    //LoadTestsSorted();
    LoadTestsReversedSorted();
    return app.exec();
    
    
   //UnitTestsInt2();
   //UnitTestsPerson2();
}