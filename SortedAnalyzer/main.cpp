#include "mainwindow.h"
#include "sortedanalyzer.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    SortedAnalyzer* nlz = new SortedAnalyzer;

    SortedWidget w(nlz);
    w.move((QApplication::desktop()->width()-w.width())/2, (QApplication::desktop()->height()-w.height())/2);
    w.show();

    return a.exec();
}
