#ifndef PYTHONINTERFACE_H
#define PYTHONINTERFACE_H
#include <QObject>
#include <QHash>
#include "grid.h"
#include "layeredgrid.h"

class PythonInterface : public QObject
{
    Q_OBJECT
public:
    PythonInterface();
public slots:
    void run(int years); // execute the iLand model
};
#endif // PYTHONINTERFACE_H
