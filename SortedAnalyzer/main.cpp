#include "mainwindow.h"
#include "sortedanalyzer.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    SortedAnalyzer* nlz = new SortedAnalyzer;

    SortedWidget w(nlz);
    w.show();

    return a.exec();
}
