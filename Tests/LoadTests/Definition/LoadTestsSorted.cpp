
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
#include "realtimeplot.h"
#include "BitonicSorter.h"
#include "LoadTestInt.h"
#include "GenerateArraySequenceSortedInt.h"


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

    RealTimePlot *rTimePlot = new RealTimePlot;
    QPalette p = rTimePlot->palette();
    p.setColor(QPalette::Window, Qt::darkGray);
    rTimePlot->setPalette(p);
    rTimePlot->show();

    for(int i = 1000; i <= 1000000; i+=50000) //слишком часто замеряю
                                            //не анализирует поведение случайной и отсортированной и обратно отсортированной
                                            
    {
        std::cout << i << std::endl;
        double timeBubble = 0;
        double timeQuick = 0;
        double timePiramid = 0;
        double timeShell = 0;
        double timeInsert = 0;
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

            rTimePlot->setData( i,  timeMerge, timeQuick, timePiramid, timeShell, timeBitonic);
        std::cout << "Count Of Elements:\n" << i << "\n" 
        << "timeBubble:\n" << timeBubble << "\n"
        << "timeInsert:\n" << timeInsert << "\n"
        << "timeQuick:\n" << timeQuick << "\n"  
        << "timeMerge:\n" << timeMerge << "\n" 
        << "timePiramid:\n" << timePiramid << "\n" 
        << "timeShell\n" << timeShell << "\n" << std::endl;

    }

    for(int i = 32; i <= 2000000; i*=2)
    {
        std::cout << i << std::endl;

        double timeBubble = 0;
        double timeQuick = 0;
        double timePiramid = 0;
        double timeShell = 0;
        double timeInsert = 0;
        double timeMerge = 0;
        double timeBitonic = 0;

        seq = GenerateArraySequenceSortedInt(i);
        timeBitonic = LoadTestInt(seq, &biSorter);
        delete seq;

        rTimePlot->setData( i,  timeMerge, timeQuick, timePiramid, timeShell, timeBitonic);
    }
    
    
}