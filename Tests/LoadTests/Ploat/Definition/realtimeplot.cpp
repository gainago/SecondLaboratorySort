#include "realtimeplot.h"
#include <qwt_arrow_button.h>
#include <qwt_plot.h>
#include <qwt_plot_curve.h>
#include <qwt_plot_directpainter.h>
#include <QPointF>
#include <qwt_series_data.h>
#include <QwtPlot>
#include <QwtPlotCurve>
#include <QwtSymbol>
#include <QwtScaleMap>
#include <QwtPlotDirectPainter>
#include <QPen>
#include <QwtPainter>
#include <QTimer>
#include <iostream>

class CurveData : public QwtArraySeriesData< QPointF >
{
public:
    virtual QRectF boundingRect() const QWT_OVERRIDE
    {
        if ( cachedBoundingRect.width() < 0.0 )
            cachedBoundingRect = qwtBoundingRect( *this );

        return cachedBoundingRect;
    }

    inline void append( const QPointF& point )
    {
        m_samples += point;
    }

    void clear()
    {
        m_samples.clear();
        m_samples.squeeze();
        cachedBoundingRect = QRectF( 0.0, 0.0, -1.0, -1.0 );
    }
};

RealTimePlot::RealTimePlot()
{
    counter = 0;
    lastAppend = 0;
    timer = new QTimer(this);
    QObject::connect(timer, SIGNAL(timeout()), this, SLOT(timeHandle()));
    timer->start(100);
    painter = new QwtPlotDirectPainter(this);
    //this->setAxisScale(QwtPlot::xBottom, -1, 1000000);
    //this->setAxisScale(QwtPlot::yLeft, 0, 1);

    curveMerge = new QwtPlotCurve("y(x)");
    curveQuick = new QwtPlotCurve("y(x)");
    curvePiramid = new QwtPlotCurve("y(x)");
    curveBitonic = new QwtPlotCurve("y(x)");
    curveShell = new QwtPlotCurve("y(x)");

    curveMerge->setStyle(QwtPlotCurve::Lines);
    curveMerge->setPen(QPen(Qt::blue));
    curveMerge->setCurveAttribute(QwtPlotCurve::Fitted);
    curveMerge->setData(new CurveData());
    curveMerge->setSymbol(new QwtSymbol(QwtSymbol::Ellipse, Qt::NoBrush, QPen(Qt::blue), QSize(1, 1)));
    curveMerge->attach(this);

    curveQuick->setStyle(QwtPlotCurve::Lines);
    curveQuick->setPen(QPen(Qt::red));
    curveQuick->setCurveAttribute(QwtPlotCurve::Fitted);
    curveQuick->setData(new CurveData());
    curveQuick->setSymbol(new QwtSymbol(QwtSymbol::Ellipse, Qt::NoBrush, QPen(Qt::red), QSize(1, 1)));
    curveQuick->attach(this);


    curvePiramid->setStyle(QwtPlotCurve::Lines);
    curvePiramid->setPen(QPen(Qt::black));
    curvePiramid->setCurveAttribute(QwtPlotCurve::Fitted);
    curvePiramid->setData(new CurveData());
    curvePiramid->setSymbol(new QwtSymbol(QwtSymbol::Ellipse, Qt::NoBrush, QPen(Qt::black), QSize(1, 1)));
    curvePiramid->attach(this);

    curveShell->setStyle(QwtPlotCurve::Lines);
    curveShell->setPen(QPen(Qt::cyan));
    curveShell->setCurveAttribute(QwtPlotCurve::Fitted);
    curveShell->setData(new CurveData());
    curveShell->setSymbol(new QwtSymbol(QwtSymbol::Ellipse, Qt::NoBrush, QPen(Qt::cyan), QSize(1, 1)));
    curveShell->attach(this);

    curveBitonic->setStyle(QwtPlotCurve::Lines);
    curveBitonic->setPen(QPen(Qt::yellow));
    curveBitonic->setCurveAttribute(QwtPlotCurve::Fitted);
    curveBitonic->setData(new CurveData());
    curveBitonic->setSymbol(new QwtSymbol(QwtSymbol::Ellipse, Qt::NoBrush, QPen(Qt::yellow), QSize(1, 1)));
    curveBitonic->attach(this);


    setAutoReplot(false);

}

void RealTimePlot::setData(double testSize, double timeMerge, double timeQuick, double timePiramid, double timeShell, double timeBitonic)
{
    
    x[counter] = testSize;
    Merge[counter] = timeMerge;
    Quick[counter] = timeQuick;
    Piramid[counter] = timePiramid;
    Bitonic[counter] = timeBitonic;
    Shell[counter] = timeShell;

    counter ++;

    //std::cout << "counter = " << counter << "\tsize = " << testSize <<  "\ntimeBitonic = " << timeBitonic << std::endl;

    
}

RealTimePlot::~RealTimePlot()
{
    //delete zoomer;
    delete painter;
    delete curveMerge;
    delete curveQuick;
    delete curvePiramid;
    delete curveBitonic;
    delete curveShell;
}

void RealTimePlot::timeHandle()
{
    if(lastAppend < counter){
    QPointF newPointMerge = QPointF(this->x[this->lastAppend], this->Merge[this->lastAppend]);
    QPointF newPointQuick = QPointF(this->x[this->lastAppend], this->Quick[this->lastAppend]);
    QPointF newPointPiramid = QPointF(this->x[this->lastAppend], this->Piramid[this->lastAppend]);
    QPointF newPointShell = QPointF(this->x[this->lastAppend], this->Shell[this->lastAppend]);
    QPointF newPointBitonic = QPointF(this->x[this->lastAppend], this->Bitonic[this->lastAppend]);
    

    RealTimePlot::appendGraphPoint(newPointMerge, newPointQuick, newPointPiramid, newPointShell, newPointBitonic);
    ++lastAppend;

    }
}

void RealTimePlot::appendGraphPoint(QPointF newPointMerge, QPointF newPointQuick, QPointF newPointPiramid, QPointF newPointShell, QPointF newPointBitonic)
{
    if(newPointQuick.ry() > 1e-8){
    CurveData *dataMerge = static_cast<CurveData *>(curveMerge->data());
    dataMerge->append(newPointMerge);
    painter->drawSeries(curveMerge, 0, dataMerge->size() - 1);

    CurveData *dataQuick = static_cast<CurveData *>(curveQuick->data());
    dataQuick->append(newPointQuick);
    painter->drawSeries(curveQuick, 0, dataQuick->size() - 1);

    CurveData *dataPiramid = static_cast<CurveData *>(curvePiramid->data());
    dataPiramid->append(newPointPiramid);
    painter->drawSeries(curvePiramid, 0, dataPiramid->size() - 1);

    CurveData *dataShell = static_cast<CurveData *>(curveShell->data());
    dataShell->append(newPointShell);
    painter->drawSeries(curveShell, 0, dataShell->size() - 1);
    }

    //std::cout << "newPointBitonuc.ry() = " << newPointBitonic.ry() << std::endl;
    if(newPointBitonic.ry() > 1e-8){
        CurveData *dataBitonic = static_cast<CurveData *>(curveBitonic->data());
        dataBitonic->append(newPointBitonic);
        painter->drawSeries(curveBitonic, 0, dataBitonic->size() - 1);
    }

}
