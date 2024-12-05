
#include "Comporators.h"
//#include "BubbleSorter.h"
#include "QuickSorter.h"
#include "PiramidSorter.h"
#include "ShellSorter.h"
//#include "InsertionSorter.h"
#include "MergeSorter.h"
#include "MyString.h"
#include "Sequence.h"
#include "ArraySequence.h"
#include "realtimeplot.h"
#include "BitonicSorter.h"
#include "LoadTestInt.h"
#include "GenerateArraySequenceSortedInt.h"

#include <QLabel>
#include <QVBoxLayout>


void LoadTestsSorted()
{

    //BubbleSorter<int> bSorter(cmpInt);
    QuickSorter<int> qSorter(cmpInt);
    PiramidSorter<int> pSorter(cmpInt);
    ShellSorter<int> sSorter(cmpInt);
    //InsertionSorter<int> iSorter(cmpInt);
    MergeSorter<int> mSorter(cmpInt);
    BitonicSorter<int> biSorter(cmpInt);

    Sequence<int>* seq;

    QWidget* wg = new QWidget;
    QVBoxLayout* vLayout = new QVBoxLayout;
    QLabel* labelTitle = new QLabel("LoadTestsSortedInt. Bubble Sort: blue\t Merge Sort: magenta\t Quick Sort:red\t Piramid Sort:black\t\
    Insertion Sort:cyan(light blue)\t Shell Sort: green");

    

    RealTimePlot *rTimePlotSorted = new RealTimePlot;

    vLayout->addWidget(labelTitle);
    vLayout->addWidget(rTimePlotSorted);
    wg->setLayout(vLayout);
    wg->show();

    QPalette p = rTimePlotSorted->palette();
    p.setColor(QPalette::Window, Qt::darkGray);
    rTimePlotSorted->setPalette(p);
    rTimePlotSorted->show();

    for(int i = 0; i <= 1000000; i+=50000) 
                                            
                                            
    {
        
        double timeBubble = 0;
        double timeQuick = 0;
        double timePiramid = 0;
        double timeShell = 0;
        double timeInsertion = 0;
        double timeMerge = 0;
        double timeBitonic = 0;


        
        

            //timeInsert = LoadTestFromFileInt(fileName, seq, &iSorter);
            //timeBubble = LoadTestFromFileInt(fileName, seq, &bSorter); // запускаю только на быстрых
                                                                         // алгоритмах сортировки 
                                                                         //ибо пузырьковая и вставками работают слишком долго

            seq = GenerateArraySequenceSortedInt(i);                                       //сортировка уже отсортированного сиквенса не меняет элемент ыметсами
            timeQuick = LoadTestInt(seq, &qSorter);
            timeMerge = LoadTestInt(seq, &mSorter);
            timePiramid = LoadTestInt(seq, &pSorter);
            timeShell = LoadTestInt(seq, &sSorter);
            delete seq;

            rTimePlotSorted->setData( i, timeBubble, timeInsertion, timeMerge, timeQuick, timePiramid, timeShell, timeBitonic);
        /*std::cout << "Count Of Elements:\n" << i << "\n" 
        << "timeBubble:\n" << timeBubble << "\n"
        << "timeInsert:\n" << timeInsert << "\n"
        << "timeQuick:\n" << timeQuick << "\n"  
        << "timeMerge:\n" << timeMerge << "\n" 
        << "timePiramid:\n" << timePiramid << "\n" 
        << "timeShell\n" << timeShell << "\n" << std::endl;*/

    }

    for(int i = 1; i <= 1000000; i*=2)
    {

        double timeBubble = 0;
        double timeQuick = 0;
        double timePiramid = 0;
        double timeShell = 0;
        double timeInsertion = 0;
        double timeMerge = 0;
        double timeBitonic = 0;

        seq = GenerateArraySequenceSortedInt(i);
        timeBitonic = LoadTestInt(seq, &biSorter);
        delete seq;

        rTimePlotSorted->setData( i, timeBubble, timeInsertion, timeMerge, timeQuick, timePiramid, timeShell, timeBitonic);
    }
    
    
}