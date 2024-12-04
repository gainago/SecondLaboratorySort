#ifndef REALTIMEPLOT_H
#define REALTIMEPLOT_H

#include <qwt_plot.h>
#include <qwt_plot_curve.h>
#include <qwt_plot_directpainter.h>
#include <QPointF>
//#include "QScrollBar"
//#include "ScrollZoomer.h"

class RealTimePlot : public QwtPlot
{
    Q_OBJECT
public:
    RealTimePlot();
    ~RealTimePlot();

public slots:
    void timeHandle();
    void setData(double testSize, double timeBubble, double timeQuick, double timePiramid, double timeShell, double timeBitonic);

private:
    QwtPlotCurve *curveMerge;
    QwtPlotCurve *curveBitonic;
    QwtPlotCurve *curveQuick;
    QwtPlotCurve *curvePiramid;
    QwtPlotCurve *curveShell;
    QwtPlotDirectPainter *painter;
    //QwtPlot* plot;

    void appendGraphPoint(QPointF newPointMerge, QPointF newPointQuick, QPointF newPointPiramid, QPointF newPointBitonic, QPointF newPointShell);
    int counter{0};
    int lastAppend{0};
    //ScrollZoomer *zoomer;
    QTimer *timer;
    double x[1000000];
    double Merge[1000000];
    double Quick[1000000];
    double Piramid[1000000];
    double Bitonic[1000000];
    double Shell[1000000];
};

#endif // REALTIMEPLOT_H
