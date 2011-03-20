#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "produtor.h"
#include <QDebug>
#include <QScrollBar>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    Produtor *produtor = new Produtor;
    connect(produtor,SIGNAL(dadoProduzido(QString)),this,SLOT(adicionaDadoProduzido(QString)));

    connect(this->ui->listProdutor->verticalScrollBar(),SIGNAL(rangeChanged(int,int)), this,SLOT(atualizaScrollProdutor(int,int)));

    produtor->start();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::adicionaDadoProduzido(QString dado)
{
    //qDebug() << dado;
    this->ui->listProdutor->addItem(dado);
}

void MainWindow::atualizaScrollProdutor(int min, int max)
{
    this->ui->listProdutor->verticalScrollBar()->setValue(max);
}


