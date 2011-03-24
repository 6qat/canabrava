#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QStateMachine>
#include <QTimer>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QGraphicsScene *cena = new QGraphicsScene(this);
    cena->setSceneRect(0,0,80,160);
    ui->graphicsView->setScene(cena);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);

    ui->graphicsView->setAlignment(Qt::AlignLeft | Qt::AlignTop);

    Semaforo *semaforo = new Semaforo;
    semaforo->setBrush(QBrush(Qt::black));
    semaforo->setRect(0,0,80,240);

    verde = new Bolinha(semaforo);
    verde->setBrush(QBrush(Qt::white));
    verde->setRect(10,15,60,60);

    amarela = new Bolinha(semaforo);
    amarela->setRect(10,90,60,60);
    amarela->setBrush(QBrush(Qt::white));

    vermelha = new Bolinha(semaforo);
    vermelha->setBrush(QBrush(Qt::white));
    vermelha->setRect(10,165,60,60);

    cena->addItem(semaforo);

    QTimer *timer = new QTimer;
    timer->setInterval(1000);
    timer->start();

    QStateMachine *sm = new QStateMachine;
    QState *estadoVerde = new QState(sm);
    QState *estadoVermelho = new QState(sm);
    QState *estadoAmarelo = new QState(sm);

    estadoVerde->addTransition(timer,SIGNAL(timeout()),estadoAmarelo);
    estadoAmarelo->addTransition(timer,SIGNAL(timeout()),estadoVermelho);
    estadoVermelho->addTransition(timer,SIGNAL(timeout()),estadoVerde);

    connect(estadoVerde,SIGNAL(entered()), this, SLOT(entrouNoVerde()));
    connect(estadoVermelho,SIGNAL(entered()), this, SLOT(entrouNoVermelho()));
    connect(estadoAmarelo,SIGNAL(entered()), this, SLOT(entrouNoAmarelo()));

    sm->setInitialState(estadoVerde);
    sm->start();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::entrouNoAmarelo()
{
    amarela->setBrush(QBrush(Qt::yellow));
    vermelha->setBrush(QBrush(Qt::white));
    verde->setBrush(QBrush(Qt::white));
}

void MainWindow::entrouNoVermelho()
{
    vermelha->setBrush(QBrush(Qt::red));
    amarela->setBrush(QBrush(Qt::white));
    verde->setBrush(QBrush(Qt::white));
}

void MainWindow::entrouNoVerde()
{
    verde->setBrush(QBrush(Qt::green));
    amarela->setBrush(QBrush(Qt::white));
    vermelha->setBrush(QBrush(Qt::white));
}
