
#include "Comporators.h"
#include "BubbleSorter.h"
#include "QuickSorter.h"
#include "PiramidSorter.h"
#include "ShellSorter.h"
#include "InsertionSorter.h"
#include "MergeSorter.h"
#include "MyString.h"
#include "Sequence.h"
#include "ArraySequence.h"
#include "LoadTestFromFilePerson.h"
#include "realtimeplot.h"
//#include "fstream"
#include "BitonicSorter.h"
#include "Person.h"
#include "realtimeplot.h"
#include <QLabel>
#include <QVBoxLayout>

//можно было бы сделать нагрузочные тесты шаблонные и передавать в них строки,
//но на мой взгляд это затруднит читаемость кода
void StartLoadTestsPersonFromFile()
{

    //BubbleSorter<Person*> bSorter(cmpPointerPerson);
    QuickSorter<Person*> qSorter(cmpPointerPerson);
    PiramidSorter<Person*> pSorter(cmpPointerPerson);
    ShellSorter<Person*> sSorter(cmpPointerPerson);
    //InsertionSorter<Person*> iSorter(cmpPointerPerson);
    MergeSorter<Person*> mSorter(cmpPointerPerson);
    BitonicSorter<Person*> biSorter(cmpPointerPerson);

    Sequence<Person*> *seq = new MutableArraySequence<Person*>;
    //std::ofstream ofs("Time Functions2"); //unomment if you want to get data to file
    QWidget* wg = new QWidget;
    QVBoxLayout* vLayout = new QVBoxLayout;
    QLabel* labelTitle = new QLabel("LoadTestsPerson. Bubble Sort: blue\t Merge Sort: magenta\t Quick Sort:red\t Piramid Sort:black\t\
    Insertion Sort:cyan(light blue)\t Shell Sort: green");

    vLayout->addWidget(labelTitle);
    RealTimePlot *rTimePlot = new RealTimePlot;
    vLayout->addWidget(rTimePlot);
    wg->setLayout(vLayout);
    wg->show();
    QPalette p = rTimePlot->palette();
    p.setColor(QPalette::Window, Qt::darkGray);
    rTimePlot->setPalette(p);
    rTimePlot->show();

    for(int i = 0; i <= 1000000; i+=50000)                                       
    {
        std::cout << i << std::endl;
        MyString fileName("GeneratedPerson");
        fileName = fileName + MyString::IntToMyString(i);
        double timeBubble = 0;
        double timeQuick = 0;
        double timePiramid = 0;
        double timeShell = 0;
        double timeInsertion = 0;
        double timeMerge = 0;
        double timeBitonic = 0;

            //timeInsert = LoadTestFromFileInt(fileName, seq, &iSorter);
            //timeBubble = LoadTestFromFileInt(fileName, seq, &bSorter);
            
            timeQuick = LoadTestFromFilePerson(fileName, seq, &qSorter);
            timeMerge = LoadTestFromFilePerson(fileName, seq, &mSorter);
            timePiramid = LoadTestFromFilePerson(fileName, seq, &pSorter);
            timeShell = LoadTestFromFilePerson(fileName, seq, &sSorter);
            
        
        /*ofs << "Count Of Elements:\n" << i << "\n"  
        << "timeBubble:\n" << timeBubble << "\n"
        << "timeInsert:\n" << timeInsert << "\n"
        << "timeQuick:\n" << timeQuick << "\n"
        << "timeMerge:\n" << timeMerge << "\n"   
        << "timePiramid:\n" << timePiramid << "\n" 
        << "timeShell\n" << timeShell << "\n" << std::endl;  */
        //if(timeQuick > 1e-8 || timeBitonic > 1e-8 )
            rTimePlot->setData( i, timeBubble, timeInsertion, timeMerge, timeQuick, timePiramid, timeShell, timeBitonic);
        // std::cout << "Count Of Elements:\n" << i << "\n" 
        // << "timeBubble:\n" << timeBubble << "\n"
        // << "timeInsert:\n" << timeInsert << "\n"
        // << "timeQuick:\n" << timeQuick << "\n"  
        // << "timeMerge:\n" << timeMerge << "\n" 
        // << "timePiramid:\n" << timePiramid << "\n" 
        // << "timeShell\n" << timeShell << "\n" << std::endl;

    }

    for(int i = 1; i <= 1000000; i*=2)
    {
        std::cout << i << std::endl;
        MyString fileName("GeneratedPerson");
        fileName = fileName + MyString::IntToMyString(i);
        double timeBubble = 0;
        double timeQuick = 0;
        double timePiramid = 0;
        double timeShell = 0;
        double timeInsertion = 0;
        double timeMerge = 0;
        double timeBitonic = 0;
            
                timeBitonic = LoadTestFromFilePerson(fileName, seq, &biSorter);
            
        /*ofs << "Count Of Elements:\n" << i << "\n" 
        << "timeBubble:\n" << timeBubble << "\n"
        << "timeInsert:\n" << timeInsert << "\n"
        << "timeQuick:\n" << timeQuick << "\n"
        << "timeMerge:\n" << timeMerge << "\n"   
        << "timePiramid:\n" << timePiramid << "\n" 
        << "timeShell\n" << timeShell << "\n" << std::endl;  */
        //if(timeQuick > 1e-8 || timeBitonic > 1e-8 )
        //std::cout << "Count Of Elements:\n" << i << "\n" 
        //<< "timeBitonic:\n" << timeBitonic << std::endl;

            rTimePlot->setData( i, timeBubble, timeInsertion, timeMerge, timeQuick, timePiramid, timeShell, timeBitonic);

        //std::cout << "Count Of Elements:\n" << i << "\n" 
        //<< "timeBitonic:\n" << timeBitonic << std::endl;
        

    }
    
    delete seq;
}