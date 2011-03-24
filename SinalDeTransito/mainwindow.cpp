#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "semaforo.h"

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

    Bolinha *verde = new Bolinha(semaforo);
    verde->setBrush(QBrush(Qt::green));
    verde->setRect(10,15,60,60);

    Bolinha *amarela = new Bolinha(semaforo);
    amarela->setRect(10,90,60,60);
    amarela->setBrush(QBrush(Qt::yellow));

    Bolinha *vermelha = new Bolinha(semaforo);
    vermelha->setBrush(QBrush(Qt::red));
    vermelha->setRect(10,165,60,60);



    cena->addItem(semaforo);


}

MainWindow::~MainWindow()
{
    delete ui;
}
