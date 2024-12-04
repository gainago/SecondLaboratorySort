#ifndef UICLASSPRINTGRAPHICS_H
#define UICLASSPRINTGRAPHICS_H

#include <QObject>
#include "sortertablemodel.h"

class UIClassPrintGraphics : public QObject
{
public:
    UIClassPrintGraphics();
    void PrintGraphics(SorterTableModel const * model);
};

#endif // UICLASSPRINTGRAPHICS_H
