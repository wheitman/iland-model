#include <iostream>
#include <QCoreApplication>


#include "python.hpp"

#include "global.h"
#include "model.h"
#include "modelcontroller.h"

PythonInterface::PythonInterface()
{
}

void PythonInterface::run(int years)
{

    // QString xml_name = QCoreApplication::arguments().at(1);
    // get the number of years to run...
    // bool ok;
    // int years = QCoreApplication::arguments().at(2).toInt(&ok);
    if (years < 0)
    {
        qDebug() << QCoreApplication::arguments().at(2) << "is an invalid number of years to run!";
        // QCoreApplication::quit();
        return;
    }

    // if (!QFile::exists(xml_name))
    // {
    //     qDebug() << "invalid XML project file: " << xml_name;
    //     QCoreApplication::quit();
    //     return;
    // }
    try
    {

        ModelController iland_model;
        GlobalSettings::instance()->setModelController(&iland_model);
        // QObject::connect(&iland_model, SIGNAL(year(int)), SLOT(runYear(int)));
        iland_model.setFileName("/home/main/iland-model/data/project.xml");
        if (iland_model.hasError())
        {
            qWarning() << "!!!! ERROR !!!!";
            qWarning() << iland_model.lastError();
            qWarning() << "!!!! ERROR !!!!";
            // QCoreApplication::quit();
            return;
        }

        // if (QCoreApplication::arguments().count() > 3)
        // {
        //     qWarning() << "set command line values:";
        //     for (int i = 3; i < QCoreApplication::arguments().count(); ++i)
        //     {
        //         QString line = QCoreApplication::arguments().at(i);
        //         line = line.remove(QChar('"')); // drop quotes
        //         mParams.append(line);
        //         // qDebug() << qPrintable(line);
        //         QString key = line.left(line.indexOf('='));
        //         QString value = line.mid(line.indexOf('=') + 1);
        //         const_cast<XmlHelper &>(GlobalSettings::instance()->settings()).setNodeValue(key, value);
        //         qWarning() << QString("set '%1' to value '%2'. result: '%3'").arg(key).arg(value).arg(GlobalSettings::instance()->settings().value(key));
        //     }
        // }
        // if (!setupLogging())
        // {
        //     qWarning() << "**************************************************";
        //     qWarning() << "********* Error in setup of logging **************";
        //     qWarning() << "**************************************************";
        //     QCoreApplication::quit();
        //     return;
        // }

        qWarning() << "*** creating model...";

        iland_model.create();
        if (iland_model.hasError())
        {
            qWarning() << "!!!! ERROR !!!!";
            qWarning() << iland_model.lastError();
            qWarning() << "!!!! ERROR !!!!";
            // QCoreApplication::quit();
            return;
        }
        // runJavascript("onCreate");
        qWarning() << "**************************************************";
        qWarning() << "*** running model for" << years << "years";
        qWarning() << "**************************************************";

        iland_model.run(years + 1);
        if (iland_model.hasError())
        {
            qWarning() << "!!!! ERROR !!!!";
            qWarning() << iland_model.lastError();
            qWarning() << "!!!! ERROR !!!!";
            // QCoreApplication::quit();
            return;
        }
        // runJavascript("onFinish");

        qWarning() << "**************************************************";
        qWarning() << "*** model run finished.";
        qWarning() << "**************************************************";
    }
    catch (const IException &e)
    {
        qWarning() << "*** An exception occured ***";
        qWarning() << e.message();
    }
    catch (const std::exception &e)
    {
        qWarning() << "*** An (std)exception occured ***";
        qWarning() << e.what();
    }
    // QCoreApplication::quit();
}

int main(int argc, char *argv[])
{

    QCoreApplication app(argc, argv);
    PythonInterface py;

    std::cout << "Python interface initialized." << std::endl;

    py.run(10); // Run the model for 10 years

    return 0;
}
