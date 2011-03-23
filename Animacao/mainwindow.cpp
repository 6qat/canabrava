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
    ui->view->setScene(cena);

    QuadradoAnimado *quad = new QuadradoAnimado;
    quad->setRect(0,0,40,40);
    cena->addItem(quad);



}

MainWindow::~MainWindow()
{
    delete ui;
}
