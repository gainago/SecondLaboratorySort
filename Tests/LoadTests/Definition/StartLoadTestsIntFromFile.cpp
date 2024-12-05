
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
#include "LoadTestFromFileInt.h"
#include "realtimeplot.h"
#include "fstream"
#include "BitonicSorter.h"
#include "realtimeplot.h"
#include <QLabel>
#include <QVBoxLayout>



void StartLoadTestsIntFromFile()
{

    BubbleSorter<int> bSorter(cmpInt);
    QuickSorter<int> qSorter(cmpInt);
    PiramidSorter<int> pSorter(cmpInt);
    ShellSorter<int> sSorter(cmpInt);
    InsertionSorter<int> iSorter(cmpInt);
    MergeSorter<int> mSorter(cmpInt);
    BitonicSorter<int> biSorter(cmpInt);

    Sequence<int> *seq = new MutableArraySequence<int>;
    //std::ofstream ofs("Time Functions2"); //uncomment if you want to get data to file
    QWidget* wg = new QWidget;
    QVBoxLayout* vLayout = new QVBoxLayout;
    QLabel* labelTitle = new QLabel("LoadTestsInt. Bubble Sort: blue\t Merge Sort: magenta\t Quick Sort:red\t Piramid Sort:black\t\
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
        MyString fileName("GeneratedInt");
        fileName = fileName + MyString::IntToMyString(i);
        double timeBubble = 0;
        double timeQuick = 0;
        double timePiramid = 0;
        double timeShell = 0;
        double timeInsertion = 0;
        double timeMerge = 0;
        double timeBitonic = 0;

            //timeInsertion = LoadTestFromFileInt(fileName, seq, &iSorter); //если раскомментируете то будет долго
                                                                            // а на меньших объемах данных не видно зависимости
            //timeBubble = LoadTestFromFileInt(fileName, seq, &bSorter);
            
            timeQuick = LoadTestFromFileInt(fileName, seq, &qSorter);
            timeMerge = LoadTestFromFileInt(fileName, seq, &mSorter);
            timePiramid = LoadTestFromFileInt(fileName, seq, &pSorter);
            timeShell = LoadTestFromFileInt(fileName, seq, &sSorter);
            
        
        /*ofs << "Count Of Elements:\n" << i << "\n"   //оставил на случай если вы захотите получить новые данные для всех функция в файл
        << "timeBubble:\n" << timeBubble << "\n"
        << "timeInsert:\n" << timeInsert << "\n"
        << "timeQuick:\n" << timeQuick << "\n"
        << "timeMerge:\n" << timeMerge << "\n"   
        << "timePiramid:\n" << timePiramid << "\n" 
        << "timeShell\n" << timeShell << "\n" << std::endl;  */
        //if(timeQuick > 1e-8 || timeBitonic > 1e-8 )
                                    //нулевое время на график не добавится
            rTimePlot->setData( i, timeBubble, timeInsertion, timeMerge, timeQuick, timePiramid, timeShell, timeBitonic); 
        // std::cout << "Count Of Elements:\n" << i << "\n" 
        // << "timeBubble:\n" << timeBubble << "\n"
        // << "timeInsert:\n" << timeInsert << "\n"
        // << "timeQuick:\n" << timeQuick << "\n"  
        // << "timeMerge:\n" << timeMerge << "\n" 
        // << "timePiramid:\n" << timePiramid << "\n" 
        // << "timeShell\n" << timeShell << "\n" << std::endl;

    }

    for(int i = 1; i <= 10000; i*=2)
    {
        std::cout << i << std::endl;
        MyString fileName("GeneratedInt");
        fileName = fileName + MyString::IntToMyString(i);
        double timeBubble = 0;
        double timeQuick = 0;
        double timePiramid = 0;
        double timeShell = 0;
        double timeInsertion = 0;
        double timeMerge = 0;
        double timeBitonic = 0;

                timeBitonic = LoadTestFromFileInt(fileName, seq, &biSorter);
        
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