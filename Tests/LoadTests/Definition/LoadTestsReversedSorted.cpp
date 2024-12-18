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
#include "GenerateArraySequenceReversedSorted.h"
#include <QLabel>
#include <QVBoxLayout>


void LoadTestsReversedSorted()
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
    QLabel* labelTitle = new QLabel("LoadTestsReversedSortedInt. Bubble Sort: blue\t Merge Sort: magenta\t Quick Sort:red\t Piramid Sort:black\t\
    Insertion Sort:cyan(light blue)\t Shell Sort: green");

    vLayout->addWidget(labelTitle);
    RealTimePlot *rTimePlot = new RealTimePlot;
    vLayout->addWidget(rTimePlot);
    wg->setLayout(vLayout);
    wg->show();
    QPalette p = rTimePlot->palette();
    p.setColor(QPalette::Window, Qt::darkGray);
    /*QLabel* labelText = new QLabel("Merge Sort: blue\n\
    Quick Sort:red\n\
    Piramid Sort:black\n\
    Shell Sort:cyan(light blue)\n\
    Bitonic Sort:yellow");
    labelText->show();*/

    rTimePlot->setPalette(p);
    rTimePlot->show();

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

            seq = GenerateArraySequenceReversedSorted(i);               
            timeQuick = LoadTestInt(seq, &qSorter);
            delete seq;

            seq = GenerateArraySequenceReversedSorted(i);   
            timeMerge = LoadTestInt(seq, &mSorter);
            delete seq;

            seq = GenerateArraySequenceReversedSorted(i);  
            //PrintSeq(seq); 
            timePiramid = LoadTestInt(seq, &pSorter);
            delete seq;

            seq = GenerateArraySequenceReversedSorted(i);   
            timeShell = LoadTestInt(seq, &sSorter);
            delete seq;
            
            
            rTimePlot->setData( i, timeBubble, timeInsertion, timeMerge, timeQuick, timePiramid, timeShell, timeBitonic);

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

        seq = GenerateArraySequenceReversedSorted(i);   
        timeBitonic = LoadTestInt(seq, &biSorter);
        delete seq;

        rTimePlot->setData( i, timeBubble, timeInsertion, timeMerge, timeQuick, timePiramid, timeShell, timeBitonic);
    }
}