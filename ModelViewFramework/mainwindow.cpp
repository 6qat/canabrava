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

    model = new MeuModelo(lista);

    //QListView * view = ui->listView;
    QListView *view = new QListView;
    setCentralWidget(view);

    view->setModel(model);

    connect(ui->actionAdicionarDados, SIGNAL(triggered()), this,SLOT(adicionarDados()));


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::adicionarDados()
{
    qDebug() << " Adicionando dados ";
    model->insertRows(2,5);
}
