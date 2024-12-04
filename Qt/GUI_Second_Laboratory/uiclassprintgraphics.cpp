#include <qwt_plot.h>
#include <qwt_plot_curve.h>
#include <QPen>
#include <QString>
#include <QApplication>
#include <QScreen>

#include "ScrollZoomer.h"
#include "uiclassprintgraphics.h"

UIClassPrintGraphics::UIClassPrintGraphics() {}

void UIClassPrintGraphics::PrintGraphics(SorterTableModel const * model)
{
    //int size = model->rowCount(QModelIndex());
    int countBubbleSorters = 0;
    int countInsertionSorters = 0;
    int countShellSorters = 0;
    int countMergeSorters = 0;
    int countPiramidSorters = 0;
    int countQuickSorters = 0;

    for(int i = 0; i < model->rowCount(QModelIndex()); ++i)
    {
        QString sorterName = model->data(model->index(i, 0)
                                         , Qt::DisplayRole).value<QString>();
        if(sorterName == "BubbleSorter"){
            countBubbleSorters++;
            continue;
        }
        if(sorterName == "InsertionSorter"){
            countInsertionSorters++;
            continue;
        }
        if(sorterName == "ShellSorter"){
            countShellSorters++;
            continue;
        }
        if(sorterName == "MergeSorter"){
            countMergeSorters++;
            continue;
        }
        if(sorterName == "PiramidSorter"){
            countPiramidSorters++;
            continue;
        }
        if(sorterName == "QuickSorter"){
            countQuickSorters++;
            continue;
        }
    }

    double timeBubbleSorter[countBubbleSorters];
    double sizeBubbleSorter[countBubbleSorters];

    double timeInsertionSorter[countInsertionSorters];
    double sizeInsertionSorter[countInsertionSorters];

    double timeShellSorter[countShellSorters];
    double sizeShellSorter[countShellSorters];

    double timeMergeSorter[countMergeSorters];
    double sizeMergeSorter[countMergeSorters];

    double timePiramidSorter[countPiramidSorters];
    double sizePiramidSorter[countPiramidSorters];

    double timeQuickSorter[countQuickSorters];
    double sizeQuickSorter[countQuickSorters];

    int currentBubbleSorterIndex = 0;
    int currentInsertionSorterIndex = 0;
    int currentShellSorterIndex = 0;
    int currentMergeSorterIndex = 0;
    int currentPiramidSorterIndex = 0;
    int currentQuickSorterIndex = 0;

    for(int i = 0; i < model->rowCount(QModelIndex()); ++i)
    {
        QString sorterName = model->data(model->index(i, 0)
                                         , Qt::DisplayRole).value<QString>();
        if(sorterName == "BubbleSorter"){
            timeBubbleSorter[currentBubbleSorterIndex]
                = model->data(model->index(i, 1)
                        , Qt::DisplayRole).value<double>();
            sizeBubbleSorter[currentBubbleSorterIndex]
                = model->data(model->index(i, 2)
                              , Qt::DisplayRole).value<double>();
            currentBubbleSorterIndex++;
            continue;
        }
        if(sorterName == "InsertionSorter"){
            timeInsertionSorter[currentInsertionSorterIndex]
                = model->data(model->index(i, 1)
                              , Qt::DisplayRole).value<double>();
            sizeInsertionSorter[currentInsertionSorterIndex]
                = model->data(model->index(i, 2)
                              , Qt::DisplayRole).value<double>();
            currentInsertionSorterIndex++;
            continue;
        }
        if(sorterName == "ShellSorter"){
            timeShellSorter[currentShellSorterIndex]
                = model->data(model->index(i, 1)
                              , Qt::DisplayRole).value<double>();
            sizeShellSorter[currentShellSorterIndex]
                = model->data(model->index(i, 2)
                              , Qt::DisplayRole).value<double>();
            currentShellSorterIndex++;
            continue;
        }
        if(sorterName == "MergeSorter"){
            timeMergeSorter[currentMergeSorterIndex]
                = model->data(model->index(i, 1)
                              , Qt::DisplayRole).value<double>();
            sizeMergeSorter[currentMergeSorterIndex]
                = model->data(model->index(i, 2)
                              , Qt::DisplayRole).value<double>();
            currentMergeSorterIndex++;
            continue;
        }
        if(sorterName == "PiramidSorter"){
            timePiramidSorter[currentPiramidSorterIndex]
                = model->data(model->index(i, 1)
                              , Qt::DisplayRole).value<double>();
            sizePiramidSorter[currentPiramidSorterIndex]
                = model->data(model->index(i, 2)
                              , Qt::DisplayRole).value<double>();
            currentPiramidSorterIndex++;
            continue;
        }
        if(sorterName == "QuickSorter"){
            timeQuickSorter[currentQuickSorterIndex]
                = model->data(model->index(i, 1)
                              , Qt::DisplayRole).value<double>();
            sizeQuickSorter[currentQuickSorterIndex]
                = model->data(model->index(i, 2)
                              , Qt::DisplayRole).value<double>();
            currentQuickSorterIndex++;
            continue;
        }
    }
    for(int i = 0; i < countBubbleSorters; i++){
        for(int j = 0; j < countBubbleSorters - 1; j++){
            if(sizeBubbleSorter[j] > sizeBubbleSorter[j + 1]){
                int tmpSize = sizeBubbleSorter[j];
                sizeBubbleSorter[j] = sizeBubbleSorter[j + 1];
                sizeBubbleSorter[j + 1] = tmpSize;

                double tmpTime = timeBubbleSorter[j];
                timeBubbleSorter[j] = timeBubbleSorter[j + 1];
                timeBubbleSorter[j + 1] = tmpTime;

            }
        }
    }
    for(int i = 0; i < countShellSorters; i++){
        for(int j = 0; j < countShellSorters - 1; j++){
            if(sizeShellSorter[j] > sizeShellSorter[j + 1]){
                int tmpSize = sizeShellSorter[j];
                sizeShellSorter[j] = sizeShellSorter[j + 1];
                sizeShellSorter[j + 1] = tmpSize;

                double tmpTime = timeShellSorter[j];
                timeShellSorter[j] = timeShellSorter[j + 1];
                timeShellSorter[j + 1] = tmpTime;

            }
        }
    }
    for(int i = 0; i < countInsertionSorters; i++){
        for(int j = 0; j < countInsertionSorters - 1; j++){
            if(sizeInsertionSorter[j] > sizeInsertionSorter[j + 1]){
                int tmpSize = sizeInsertionSorter[j];
                sizeInsertionSorter[j] = sizeInsertionSorter[j + 1];
                sizeInsertionSorter[j + 1] = tmpSize;

                double tmpTime = timeInsertionSorter[j];
                timeInsertionSorter[j] = timeInsertionSorter[j + 1];
                timeInsertionSorter[j + 1] = tmpTime;

            }
        }
    }
    for(int i = 0; i < countMergeSorters; i++){
        for(int j = 0; j < countMergeSorters - 1; j++){
            if(sizeMergeSorter[j] > sizeMergeSorter[j + 1]){
                int tmpSize = sizeMergeSorter[j];
                sizeMergeSorter[j] = sizeMergeSorter[j + 1];
                sizeMergeSorter[j + 1] = tmpSize;

                double tmpTime = timeMergeSorter[j];
                timeMergeSorter[j] = timeMergeSorter[j + 1];
                timeMergeSorter[j + 1] = tmpTime;

            }
        }
    }
    for(int i = 0; i < countPiramidSorters; i++){
        for(int j = 0; j < countPiramidSorters - 1; j++){
            if(sizePiramidSorter[j] > sizePiramidSorter[j + 1]){
                int tmpSize = sizePiramidSorter[j];
                sizePiramidSorter[j] = sizePiramidSorter[j + 1];
                sizePiramidSorter[j + 1] = tmpSize;

                double tmpTime = timePiramidSorter[j];
                timePiramidSorter[j] = timePiramidSorter[j + 1];
                timePiramidSorter[j + 1] = tmpTime;

            }
        }
    }
    for(int i = 0; i < countQuickSorters; i++){
        for(int j = 0; j < countQuickSorters - 1; j++){
            if(sizeQuickSorter[j] > sizeQuickSorter[j + 1]){
                int tmpSize = sizeQuickSorter[j];
                sizeQuickSorter[j] = sizeQuickSorter[j + 1];
                sizeQuickSorter[j + 1] = tmpSize;

                double tmpTime = timeQuickSorter[j];
                timeQuickSorter[j] = timeQuickSorter[j + 1];
                timeQuickSorter[j + 1] = tmpTime;

            }
        }
    }


    QwtPlotCurve *curveBubble = new QwtPlotCurve("y(x)");
    QwtPlotCurve *curveQuick = new QwtPlotCurve("y(x)");
    QwtPlotCurve *curvePiramid = new QwtPlotCurve("y(x)");
    QwtPlotCurve *curveInsert = new QwtPlotCurve("y(x)");
    QwtPlotCurve *curveShell = new QwtPlotCurve("y(x)");
    QwtPlotCurve *curveMerge = new QwtPlotCurve("y(x)");

    curveBubble->setStyle(QwtPlotCurve::Lines);
    curveBubble->setPen(QPen(Qt::blue));
    curveBubble->setCurveAttribute(QwtPlotCurve::Fitted);
    //curveBubble->setData(new CurveData());
    //curveBubble->setSymbol(new QwtSymbol(QwtSymbol::Ellipse, Qt::NoBrush, QPen(Qt::blue), QSize(1, 1)));


    curveQuick->setStyle(QwtPlotCurve::Lines);
    curveQuick->setPen(QPen(Qt::red));
    curveQuick->setCurveAttribute(QwtPlotCurve::Fitted);
    //curveQuick->setData(new CurveData());
    //curveQuick->setSymbol(new QwtSymbol(QwtSymbol::Ellipse, Qt::NoBrush, QPen(Qt::red), QSize(1, 1)));



    curvePiramid->setStyle(QwtPlotCurve::Lines);
    curvePiramid->setPen(QPen(Qt::black));
    curvePiramid->setCurveAttribute(QwtPlotCurve::Fitted);
    //curvePiramid->setData(new CurveData());
    //curvePiramid->setSymbol(new QwtSymbol(QwtSymbol::Ellipse, Qt::NoBrush, QPen(Qt::black), QSize(1, 1)));

    curveInsert->setStyle(QwtPlotCurve::Lines);
    curveInsert->setPen(QPen(Qt::cyan));
    //curveInsert->setCurveAttribute(QwtPlotCurve::Fitted);

    curveShell->setStyle(QwtPlotCurve::Lines);
    curveShell->setPen(QPen(Qt::green));
    curveShell->setCurveAttribute(QwtPlotCurve::Fitted);

    curveMerge->setStyle(QwtPlotCurve::Lines);
    curveMerge->setPen(QPen(Qt::magenta));
    curveMerge->setCurveAttribute(QwtPlotCurve::Fitted);

    curveBubble->setSamples(sizeBubbleSorter, timeBubbleSorter, countBubbleSorters);
    curveInsert->setSamples(sizeInsertionSorter, timeInsertionSorter, countInsertionSorters);
    curveShell->setSamples(sizeShellSorter, timeShellSorter, countShellSorters);
    curveMerge->setSamples(sizeMergeSorter, timeMergeSorter, countMergeSorters);
    curvePiramid->setSamples(sizePiramidSorter, timePiramidSorter, countPiramidSorters);
    curveQuick->setSamples(sizeQuickSorter, timeQuickSorter, countQuickSorters);

    QWidget* wgGraphics = new QWidget;
    QwtPlot *plot = new QwtPlot(wgGraphics);
    //plot->setBackgroundRole(QPalette::Background);
    plot->setAutoFillBackground(true);

    QPalette p = plot->palette();
    p.setColor(QPalette::Window, Qt::darkGray);
    plot->setPalette(p);

    curveBubble->attach(plot);
    curveInsert->attach(plot);
    curveShell->attach(plot);
    curveMerge->attach(plot);
    curvePiramid->attach(plot);
    curveQuick->attach(plot);

    plot->resize(QRect(QApplication::screens().at(0)->geometry()).width() / 2, QRect(QApplication::screens().at(0)->geometry()).height() / 2);
    //plot->setAxisAutoScale()
    //plot->setAxisAutoScale(QwtPlot :: xBottom);

    ScrollZoomer *zoomer = new ScrollZoomer(plot->canvas());
    plot->replot();
    plot->show();
    wgGraphics->show();



}
