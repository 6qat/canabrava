#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "produtor.h"
#include "consumidor.h"

#include <QDebug>
#include <QScrollBar>
#include <QMutex>
#include <QListWidget>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    Produtor *produtor = new Produtor;
    connect(produtor,SIGNAL(dadoProduzido(QString)),this,SLOT(adicionaDadoProduzido(QString)),Qt::QueuedConnection);
    connect(this->ui->listProdutor->verticalScrollBar(),SIGNAL(rangeChanged(int,int)), this,SLOT(atualizaScrollProdutor(int,int)));
    produtor->start();

    Consumidor *consumidor1 = new Consumidor(this->ui->listProdutor);
    connect(consumidor1,SIGNAL(dadoConsumido(QString)),this,SLOT(adicionaDadoConsumido1(QString)));

    Consumidor *consumidor2 = new Consumidor(this->ui->listProdutor);
    connect(consumidor2,SIGNAL(dadoConsumido(QString)),this,SLOT(adicionaDadoConsumido2(QString)));

    Consumidor *consumidor3 = new Consumidor(this->ui->listProdutor);
    connect(consumidor3,SIGNAL(dadoConsumido(QString)),this,SLOT(adicionaDadoConsumido3(QString)));

    consumidor1->start();
    consumidor2->start();
    consumidor3->start();


}

MainWindow::~MainWindow()
{
    delete ui;
}

//slot
void MainWindow::adicionaDadoProduzido(QString dado)
{
    //qDebug() << dado;
    //QMutex m;
    //m.lock();
    this->ui->listProdutor->addItem(dado);
    //m.unlock();
}

//slot
void MainWindow::atualizaScrollProdutor(int min, int max)
{
    //qDebug() << max;
    this->ui->listProdutor->verticalScrollBar()->setValue(max);
}

void MainWindow::adicionaDadoConsumido1(QString dado)
{
    qDebug() << dado;
}

void MainWindow::adicionaDadoConsumido2(QString dado)
{
    qDebug() << dado;
}

void MainWindow::adicionaDadoConsumido3(QString dado)
{
    qDebug() << dado;
}



