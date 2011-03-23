#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QPropertyAnimation>

#include "quadradoanimado.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QGraphicsScene *cena = new QGraphicsScene(this);
    cena->setSceneRect(0,0,800,600);
    ui->view->setScene(cena);
    ui->view->setAlignment(Qt::AlignLeft | Qt::AlignTop);
    //ui->view->set


    QuadradoAnimado *quad1 = new QuadradoAnimado;
    quad1->setRect(0,0,40,40);
    cena->addItem(quad1);
    quad1->setPos(0,0);
    quad1->setEasyingCurve(QEasingCurve::InBounce);


    QuadradoAnimado *quad2 = new QuadradoAnimado;
    quad2->setRect(0,0,40,40);
    cena->addItem(quad2);
    quad2->setPos(0,50);
    quad2->setEasyingCurve(QEasingCurve::InOutElastic);


    QuadradoAnimado *quad3 = new QuadradoAnimado;
    quad3->setRect(0,0,40,40);
    cena->addItem(quad3);
    quad3->setPos(0,100);


}

MainWindow::~MainWindow()
{
    delete ui;
}
