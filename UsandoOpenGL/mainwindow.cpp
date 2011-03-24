#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "cenagl.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    CenaGL *cena = new CenaGL;

    setCentralWidget(cena);
}

MainWindow::~MainWindow()
{
    delete ui;
}
