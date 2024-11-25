#include <qwt_plot.h>
#include <qwt_plot_curve.h>
#include <qwt_plot_directpainter.h>
#include <QPointF>
#include <QApplication>
#include "realtimeplot.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    RealTimePlot plot;
    plot.show();
    for(int i = 0; i < 100; i++)
    {
        plot.setData(i, i, i%300, i*5, i*12/5);
    }
    return a.exec();
}
