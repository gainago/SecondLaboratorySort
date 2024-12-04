// #include "ListSequence.h" //uncomment to generate data
// #include "ArraySequence.h"
// #include "DynamicArray.h"
//#include "Person.h"
//#include "MyString.h"
#include "GetNamesAndSournamesToMyString.h" 
#include "GenerateArraySequencePerson.h"
#include "WriteIntToFile.h"
#include "WritePersonToFile.h"
#include "ArraySequence.h"
#include "StartLoadTestsPersonFromFile.h"
#include "StartLoadTestsIntFromFile.h"
#include <QApplication>
#include "UnitTests2.h"
#include "LoadTestsSorted.h"
#include "LoadTestsReversedSorted.h"
#include "ShowPlotLoadTestsAllSorters.h"




int main(int argc, char** argv)
{

    UnitTestsInt2();  //Tests
    UnitTestsPerson2();
    /*DynamicArray<MyString>* names = GetNamesToMyString(); //Uncumment to create data 
                                                                //Commment after that because it takes 2.3 GB memory
    DynamicArray<MyString>* surnames = GetSurnamesToMyString();
    for(int i = 0; i <= 1000000; i+=50000)
    {
        WritePersonToFile(i, names, surnames);
    }

    for(int i = 1; i <= 1000000; i*=2)
    {
        WritePersonToFile(i, names, surnames);
    }

    delete names;
    delete surnames;
    for(int i = 0; i <= 1000000; i+=50000)
    {
        WriteIntToFile(i);
    }
    for(int i = 1; i <= 1000000; i*=2)
    {
        WriteIntToFile(i);
    }*/

   

     QApplication app(argc, argv);
     //StartLoadTestsPersonFromFile();
     //StartLoadTestsIntFromFile();

     //ShowPlotLoadTestsAllSorters(); //All Sorters but not to BitonicSort see Bitonic Sort in StartLoadTestsIntFromFile
     
     //LoadTestsSorted();              //Thees two functions fot int
     //LoadTestsReversedSorted();
     
     return app.exec();
    
    
   
}