#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "meu_modelo.h"

#include <QStringList>
#include <QListView>
#include <QDebug>
#include <QLayout>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QStringList lista;
    lista << "adfaf" << "ddddd" << "ffff " << "ffff";

    MeuModelo *model = new MeuModelo(lista);

    //QListView * view = ui->listView;
    QListView *view = new QListView;
    setCentralWidget(view);

    view->setModel(model);

}

MainWindow::~MainWindow()
{
    delete ui;
}
