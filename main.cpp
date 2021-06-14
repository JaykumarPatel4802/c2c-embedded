#include "mainwindow.h"
#include <QApplication>
#include <QTimer>


int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    QTimer timer1;
    QObject::connect(&timer1, &QTimer::timeout, [&]()
    {
        if(digitalRead(21))
        {

        }
    });

    timer1.start(100);

    return a.exec();
}
