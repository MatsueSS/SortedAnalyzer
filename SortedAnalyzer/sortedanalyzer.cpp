#include "sortedanalyzer.h"

SortedAnalyzer::SortedAnalyzer(){
    srand(time(nullptr));
}

void SortedAnalyzer::generateValues(int n){
    for(int i = 0; i < n; i++) values.push_back(rand()%n);
}

QVector<int>& SortedAnalyzer::getValues(){
    return values;
}

FileManager::FileManager(SortedAnalyzer* obj) : p_nlz(obj) {}

void FileManager::write(const QString& filename){
    QFile file(filename);
    if(file.open(QIODevice::WriteOnly)){
        QVector<int> v = p_nlz->getValues();
        QTextStream out(&file);
        for(int value : v) out << QString::number(value) << " ";
        out << "\n";
        file.close();
    }
}

void FileManager::read(const QString& filename){
    QFile file(filename);
    if(file.open(QIODevice::ReadOnly | QIODevice::Text)){
        QVector<int> v;
        QTextStream in(&file);
        QStringList lst = in.readLine().split(" ");
        for(QString value : lst) v.push_back(value.toInt());
        p_nlz->getValues() = v;
        file.close();
    }
}

void SortedAnalyzer::readFile(const QString& filename){
    FileManager manager(this);
    manager.read(filename);
}

void SortedAnalyzer::writeFile(const QString &filename){
    FileManager manager(this);
    manager.write(filename);

}

bool increase(int a, int b){
    return a > b;
}

void swap(int& a, int& b){
    int temp = a;
    a = b;
    b = temp;
}

void quick_sort(SortedAnalyzer* obj, int low, int high, bool(*func)(int a, int b)){
    if(low > high) return;
    int p = obj->values[(low+high)/2];
    int i = low, j = high;
    while(i <= j){
        while(func(p, obj->values[i])) i++;
        while(func(obj->values[j], p)) j--;
        if(i <= j){
            swap(obj->values[i++], obj->values[j--]);
        }
    }
    quick_sort(obj, low, j, func);
    quick_sort(obj, i, high, func);
}

void choice_sort(SortedAnalyzer* obj, int n, bool(*func)(int a, int b)){
    for(int i = 0; i < n-1; i++){
        int temp = obj->values[i];
        int ctrl_j;
        for(int j = i + 1; j < n; j++){
            if(func(temp, obj->values[j])) { temp = obj->values[j]; ctrl_j = j; }
        }
        if(temp != obj->values[i]){
            swap(obj->values[i], obj->values[ctrl_j]);
        }
    }
}

void SortedAnalyzer::make_sort(type_sort type){
    double start_time, end_time;
    switch(type){
    case _quick_sort:
        for(int i = 0; i < lengths.size(); i++) {
            start_time = clock();
            quick_sort(this, 0, lengths[i]-1, increase);
            end_time = clock();
            timeWorkQSort.push_back((end_time - start_time)/(double)CLOCKS_PER_SEC);
        }
        break;
    case _choice_sort:
        for(int i = 0; i < lengths.size(); i++) {
            start_time = clock();
            choice_sort(this, lengths[i], increase);
            end_time = clock();
            timeWorkCSort.push_back((end_time - start_time)/(double)CLOCKS_PER_SEC);
        }
        break;
    }
}

QVector<double>& SortedAnalyzer::getTime(type_sort type){
    switch(type){
    case _quick_sort:
        return timeWorkQSort;
    case _choice_sort:
        return timeWorkCSort;
    }
}

SortedWidget::SortedWidget(SortedAnalyzer* p_nlz, QWidget* pwgt /*=0*/) : p_nlz(p_nlz), QWidget(pwgt){
    setWindowTitle("Программа сортировки набора чисел");

    pcmdGnrtVls = new QPushButton("&Сгенерировать 10000 чисел");
    connect(pcmdGnrtVls, SIGNAL(clicked()), SLOT(slotGenerateValues()));

    pcmdQSort = new QPushButton("&Быстрая сортировка");
    connect(pcmdQSort, SIGNAL(clicked()), SLOT(slotQuickSort()));
    pcmdQSort->setEnabled(false);

    pcmdCSort = new QPushButton("&Сортировка выбором");
    connect(pcmdCSort, SIGNAL(clicked()), SLOT(slotChoiceSort()));
    pcmdCSort->setEnabled(false);

    pcmdTbl = new QPushButton("&Показать таблицу времени");
    connect(pcmdTbl, SIGNAL(clicked()), SLOT(slotShowTable()));
    pcmdTbl->setEnabled(false);

    pcmdGraphic = new QPushButton("&Отобразить графики времени");
    connect(pcmdGraphic, SIGNAL(clicked()), SLOT(slotShowGraphic()));
    pcmdGraphic->setEnabled(false);

    QPushButton* pcmdExit = new QPushButton("&Выход");
    connect(pcmdExit, SIGNAL(clicked()), qApp, SLOT(quit()));

    QMenuBar* pmnBar = new QMenuBar(this);
    QMenu* pmn = pmnBar->addMenu("&Файл");
    QMenu* pmnHelp = pmnBar->addMenu("&Помощь");

    QAction* pActWrt = new QAction("&Записать", this);
    pActWrt->setShortcut(QKeySequence("CTRL+S"));
    connect(pActWrt, SIGNAL(triggered()), SLOT(slotWriteFile()));

    QAction* pActRd = new QAction("&Прочитать", this);
    pActRd->setShortcut(QKeySequence("CTRL+D"));
    connect(pActRd, SIGNAL(triggered()), SLOT(slotReadFile()));

    QAction* pActHelpSteps = new QAction("&Поддержка");
    pActHelpSteps->setShortcut(QKeySequence("SHIFT+S"));
    connect(pActHelpSteps, SIGNAL(triggered()), SLOT(slotHelp()));

    pmnHelp->addAction(pActHelpSteps);

    pmn->addAction(pActWrt);
    pmn->addAction(pActRd);

    QVBoxLayout* pvbxLayout = new QVBoxLayout;
    pvbxLayout->addWidget(pcmdGnrtVls);
    pvbxLayout->addWidget(pcmdQSort);
    pvbxLayout->addWidget(pcmdCSort);
    pvbxLayout->addWidget(pcmdTbl);
    pvbxLayout->setMenuBar(pmnBar);
    pvbxLayout->addWidget(pcmdGraphic);
    pvbxLayout->addWidget(pcmdExit);

    setLayout(pvbxLayout);
}

void SortedWidget::slotQuickSort(){
    p_nlz->make_sort(SortedAnalyzer::type_sort::_quick_sort);
    QMessageBox::information(this, "Information", "Быстрая сортировка произведена");
}

void SortedWidget::slotChoiceSort(){
    p_nlz->make_sort(SortedAnalyzer::type_sort::_choice_sort);
    QMessageBox::information(this, "Information", "Сортировка выбором произведена");
}

void SortedWidget::slotShowTable(){
    QVector<double> t1 = p_nlz->getTime(SortedAnalyzer::type_sort::_quick_sort), t2 = p_nlz->getTime(SortedAnalyzer::type_sort::_choice_sort);
    QWidget* wgt = new QWidget;
    wgt->resize(350, 400);
    QTableWidget* ptblWgt = new QTableWidget(wgt);
    ptblWgt->setColumnCount(2);
    ptblWgt->setRowCount(10);
    ptblWgt->setVerticalHeaderLabels(QStringList() << "100" << "200" << "300" << "400" << "500" << "750" << "1000" << "2500" << "5000" << "10000");
    ptblWgt->setHorizontalHeaderLabels(QStringList() << "Время быстрой сортировка" << "Время сортировки выбором");
    for(int i = 0; i < 10; i++){
        QTableWidgetItem* ptblWgtItem1 = new QTableWidgetItem;
        ptblWgtItem1->setText(QString::number(t1[i]));
        QTableWidgetItem* ptblWgtItem2 = new QTableWidgetItem;
        ptblWgtItem2->setText(QString::number(t2[i]));

        ptblWgt->setItem(i, 0, ptblWgtItem1);
        ptblWgt->setItem(i, 1, ptblWgtItem2);
    }
    QVBoxLayout* pvbx = new QVBoxLayout;
    pvbx->addWidget(ptblWgt);
    wgt->setLayout(pvbx);
    wgt->show();
}

void SortedWidget::slotShowGraphic(){
    if(p_gr == nullptr) p_gr = new Graphic;
    QVector<double> bot = {100, 200, 300, 400, 500, 750, 1000, 2500, 5000, 10000};
    p_gr->draw(p_nlz->getTime(SortedAnalyzer::type_sort::_quick_sort), bot, Qt::blue);
    p_gr->showPlot();
    p_gr->draw(p_nlz->getTime(SortedAnalyzer::type_sort::_choice_sort), bot, Qt::red);
    p_gr->show();
}

void SortedWidget::slotGenerateValues(){
    p_nlz->generateValues();
    QMessageBox::information(this, "Information", "Числа были сгенерированы");
    activated();
}

void SortedWidget::slotReadFile(){
    QString filename = QFileDialog::getOpenFileName(this, "Выберите файл");
    if(!filename.isEmpty()){
        FileManager manager(p_nlz);
        manager.read(filename);
        QMessageBox::information(this, "Information", "Файл был прочитан");
    } else QMessageBox::warning(this, "Warning", "Файл не был прочитан");
    activated();
}

void SortedWidget::slotWriteFile(){
    QString filename = QFileDialog::getOpenFileName(this, "Выберите файл");
    if(!filename.isEmpty()){
        FileManager manager(p_nlz);
        manager.write(filename);
        QMessageBox::information(this, "Information", "Данные записаны в файл");
    } else QMessageBox::warning(this, "Warning", "Данные в файл не были записаны");
}

Graphic::Graphic(QWidget* pwgt /*=0*/) : QMainWindow(pwgt){
    plot = new QwtPlot;
    setCentralWidget(plot);
    resize(500,500);
}

void Graphic::draw(QVector<double> left, QVector<double> bottom, QColor col){
    QwtPlotCurve* curve = new QwtPlotCurve;
    curve->setPen(QPen(col, 2));
    curve->setSamples(bottom, left);
    curve->attach(plot);
}

void Graphic::showPlot(){ plot->replot(); }

void SortedWidget::slotHelp(){
    QTextEdit* ptxt = new QTextEdit;
    ptxt->setText("1. Сгенерируйте числа\n2. Сохраните их в файл\n3. Используйте сортировки\n4. Можете использовать иные функции");

    ptxt->show();
}

void SortedWidget::slotMakeEnabled(QWidget* pwgt){
    pwgt->setEnabled(true);
}

void SortedWidget::activated(){
    slotMakeEnabled(pcmdGnrtVls);
    slotMakeEnabled(pcmdQSort);
    slotMakeEnabled(pcmdCSort);
    slotMakeEnabled(pcmdTbl);
    slotMakeEnabled(pcmdGraphic);
}
