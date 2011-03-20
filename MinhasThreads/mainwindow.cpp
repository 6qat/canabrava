#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "minha_thread.h"

#include <QTextEdit>
#include <QDebug>
#include <QScrollBar>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    log = new QTextEdit;
    list = new QListWidget;
    setCentralWidget(list);

    MinhaThread *t1 = new MinhaThread("1");
    MinhaThread *t2 = new MinhaThread("2");
    MinhaThread *t3 = new MinhaThread("3");

    connect(t1,SIGNAL(sinalEmitido(QString)), this, SLOT(sinalRecebido(QString)), Qt::QueuedConnection);
    connect(t2,SIGNAL(sinalEmitido(QString)), this, SLOT(sinalRecebido(QString)), Qt::QueuedConnection);
    connect(t3,SIGNAL(sinalEmitido(QString)), this, SLOT(sinalRecebido(QString)), Qt::QueuedConnection);

    t1->start();
    t2->start();
    t3->start();

    connect(list->verticalScrollBar(),SIGNAL(rangeChanged(int,int)), this, SLOT(moveToBottom(int,int)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::sinalRecebido(QString s)
{
    //qobject_cast<QTextEdit *> (this->centralWidget());
    //qDebug() << s;
    list->addItem(s);
    //list->itemAt(list->count()-1)->;
    //list->move();
    //list->verticalScrollBar()->setSliderPosition(list->verticalScrollBar()->maximumHeight());

}

void MainWindow::moveToBottom(int min, int max)
{
    list->verticalScrollBar()->setValue(max);
}
