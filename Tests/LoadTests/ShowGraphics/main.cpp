#include <QApplication>
#include <QPointF>
#include <qwt_series_data.h>
#include <QwtPlot>
#include <QwtPlotCurve>
#include <qwt_plot.h>
#include <qwt_plot_curve.h>
#include <QPen>
#include <QwtPainter>
#include <iostream>
#include <fstream>
#include "ScrollZoomer.h"
#include "ScrollBar.h"
#include "MyString.h"
#include <QPalette>
#include <string>


void setNull(double arr[102])
{
    for(int i = 0; i < 102; i++)
    {
        arr[i] = 0;
    }
}
int main( int argc, char* argv[] )
{
    QApplication app( argc, argv );

    QWidget *wg = new QWidget;
    QwtPlot *plot = new QwtPlot(wg);
    //plot->setBackgroundRole(QPalette::Background);
    plot->setAutoFillBackground(true);

    QPalette p = plot->palette();
    p.setColor(QPalette::Window, Qt::darkGray);
    plot->setPalette(p);

    plot->setAxisScale(QwtPlot::xBottom, -1, 102000);
    plot->setAxisScale(QwtPlot::yLeft, 0, 130);
    QwtPlotCurve *curve = new QwtPlotCurve("x(y)");
    curve->setStyle(QwtPlotCurve::Lines);
    curve->setPen(QPen(Qt::blue));
    double x[102];
    double bubbleTime[102];
    double insertTime[102];
    double mergeTime[102];
    double quickTime[102];
    double shellTime[102];
    double piramidTime[102];
    setNull(x);
    setNull(bubbleTime);
    setNull(insertTime);
    setNull(mergeTime);
    setNull(quickTime);
    setNull(shellTime);
    setNull(piramidTime);


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

    auto STD{ [](char inputStr[41] )->double // '0' = 48; '9' = 57
        {
            double d = 0;
            int coefficient;
            MyString MystrFirstPart;
            MyString MystrSecondPart;
            bool partNumber = 0;

            for(int i = 0; i <= 40; i++)
            {
                if(inputStr[i] == '\0')
                    break;
                if(inputStr[i] == '.'){
                
                    partNumber = 1;
                    continue;
                }
                if(partNumber == 0){
                
                    MystrFirstPart = MystrFirstPart + MyString(inputStr[i]);
                }
                else{
                    MystrSecondPart = MystrSecondPart + MyString(inputStr[i]);
                }

            }
            double firstPart = 0;
            for(int i = 0; i < MystrFirstPart.GetLength(); i++)
            {
                firstPart*=10;
                firstPart +=   ((int)(MystrFirstPart.operator[](i)) - 48);
            }

            double k = 1;
            double secondpart = 0;

            for(int i = 0; i < MystrSecondPart.GetLength(); i++)
            {
                k*=0.1;
                secondpart += ((int)(MystrSecondPart.operator[](i)) - 48) * k;
            }

            return firstPart + secondpart;

            

        }};

    std::ifstream ifs;
    ifs.open("../../../../DataToTests/Time Functions2");
    if(!ifs.is_open())
    {
        throw "can not open file\n";
    }

    char buffer[41];
    

    for(int i = 0; i < 102; i++)
    {
        ifs.getline(buffer, 41);
        std::cout << buffer << std::endl;

        ifs.getline(buffer, 41);
        std::cout << buffer << std::endl;
        std::cout << " number Elements is " << MyString(buffer).MyStringToDouble() << std::endl;
        x[i] = MyString(buffer).MyStringToDouble();
        //----------------
        ifs.getline(buffer, 41);
        std::cout << buffer << std::endl;

        ifs.getline(buffer, 41);
        std::cout << buffer << std::endl;
        std::cout << " number Bubble is " << MyString(buffer).MyStringToDouble() << std::endl;
        bubbleTime[i] = MyString(buffer).MyStringToDouble();
        //----------------
        ifs.getline(buffer, 41);
        std::cout << buffer << std::endl;

        ifs.getline(buffer, 41);
        std::cout << buffer << std::endl;
        std::cout << " number Insert is " << MyString(buffer).MyStringToDouble() << std::endl;
        insertTime[i] = MyString(buffer).MyStringToDouble();
        //----------------
        ifs.getline(buffer, 41);
        std::cout << buffer << std::endl;

        ifs.getline(buffer, 41);
        std::cout << buffer << std::endl;
        std::cout << " number Quick is " << MyString(buffer).MyStringToDouble() << std::endl;
        quickTime[i] = MyString(buffer).MyStringToDouble();
        //----------------
        ifs.getline(buffer, 41);
        std::cout << buffer << std::endl;

        ifs.getline(buffer, 41);
        std::cout << buffer << std::endl;
        std::cout << " number Merge is " << MyString(buffer).MyStringToDouble() << std::endl;
        mergeTime[i] = MyString(buffer).MyStringToDouble();
        //----------------
        ifs.getline(buffer, 41);
        std::cout << buffer << std::endl;

        ifs.getline(buffer, 41);
        std::cout << buffer << std::endl;
        std::cout << " numberPiramid is " << MyString(buffer).MyStringToDouble() << std::endl;
        piramidTime[i] = MyString(buffer).MyStringToDouble();
        //----------------
        ifs.getline(buffer, 41);
        std::cout << buffer << std::endl;

        ifs.getline(buffer, 41);
        std::cout << buffer << std::endl;
        std::cout << " numberShell is " << MyString(buffer).MyStringToDouble() << std::endl;
        shellTime[i] = MyString(buffer).MyStringToDouble();
        ifs.getline(buffer, 41);
        
    }
    for(int i = 0; i < 102; i++)
    {
        std::cout << "Shell time = " << shellTime[i] << std::endl;
    }
    curveBubble->setSamples(x, bubbleTime, 102);
    curveInsert->setSamples(x, insertTime, 102);
    curvePiramid->setSamples(x, piramidTime, 102);
    curveShell->setSamples(x, shellTime, 102);
    curveQuick->setSamples(x, quickTime, 102);
    curveMerge->setSamples(x, mergeTime, 102);

    curveBubble->attach(plot);
    curveInsert->attach(plot);
    curvePiramid->attach(plot);
    curveShell->attach(plot);
    curveQuick->attach(plot);
    curveMerge->attach(plot);

    plot->resize(2500, 1700);
    //plot->setAxisAutoScale()
    //plot->setAxisAutoScale(QwtPlot :: xBottom);

    ScrollZoomer *zoomer = new ScrollZoomer(plot->canvas());
    plot->replot();
    plot->show();
    wg->show();

    return app.exec();
}
