#ifndef SORTEDANALYZER_H
#define SORTEDANALYZER_H

#include <QVector>
#include <QtWidgets>
#include <qwt_plot.h>
#include <qwt_plot_curve.h>

class Graphic : public QMainWindow{
Q_OBJECT
private:
    QwtPlot* plot {0};

public:
    Graphic(QWidget* pwgt = 0);

    void draw(QVector<double> left, QVector<double> bottom, QColor col);

    void showPlot();
};

class SortedAnalyzer;

class FileManager{
private:
    SortedAnalyzer* p_nlz {nullptr};

public:
    FileManager(SortedAnalyzer* p_nlz);

    void write(const QString& filename);
    void read(const QString& filename);
};

class SortedAnalyzer{
private:
    QVector<int> values;
    QVector<double> timeWorkQSort;
    QVector<double> timeWorkCSort;
    QVector<int> lengths = {100, 200, 300, 400, 500, 750, 1000, 2500, 5000, 10000};

public:
    SortedAnalyzer();

    enum type_sort {_quick_sort = 0, _choice_sort = 1};

    void generateValues(int n = 10000);

    QVector<int>& getValues();
    QVector<double>& getTime(type_sort type);

    void make_sort(type_sort type);

    void writeFile(const QString& filename);
    void readFile(const QString& filename);

    friend void quick_sort(SortedAnalyzer* obj, int low, int high, bool(*func)(int a, int b));
    friend void choice_sort(SortedAnalyzer* obj, int n, bool(*func)(int a, int b));
};

class SortedWidget : public QWidget{
Q_OBJECT
private:
    SortedAnalyzer* p_nlz {nullptr};
    Graphic* p_gr {nullptr};

    QPushButton* pcmdGnrtVls {nullptr};
    QPushButton* pcmdQSort {nullptr};
    QPushButton* pcmdCSort {nullptr};
    QPushButton* pcmdTbl {nullptr};
    QPushButton* pcmdGraphic {nullptr};

public:
    SortedWidget(SortedAnalyzer* p_nlz, QWidget* pwgt = 0);

    void activated();

public slots:
    void slotGenerateValues();
    void slotWriteFile();
    void slotReadFile();
    void slotQuickSort();
    void slotChoiceSort();
    void slotShowTable();
    void slotShowGraphic();
    void slotHelp();
    void slotMakeEnabled(QWidget* pwgt);

};

#endif // SORTEDANALYZER_H
