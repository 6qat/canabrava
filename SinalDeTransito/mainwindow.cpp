#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QStateMachine>
#include <QTimer>
#include <QColor>

#include <QGraphicsTextItem>
#include <QGraphicsProxyWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QtScript/QScriptEngine> //.evaluate("")
#include <QtScript/QScriptValue> //toInt(), toString(), etc

#include <QDebug>
#include <QString>

/*
  graphicstext->setText(QString::number(retorno) );
  */

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    engine = new QScriptEngine;

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

    //QGraphicsTextItem *texto = new QGraphicsTextItem("texto");
//    texto->text
    //cena->addItem(texto);
    //texto->setPos(0,250);

    QGraphicsProxyWidget *texto = new QGraphicsProxyWidget;
    line = new QLineEdit("Meu javascript");
    texto->setWidget(line);
    texto->setPos(0,250);
    cena->addItem(texto);

    QGraphicsProxyWidget *proxyButton = new QGraphicsProxyWidget;
    QPushButton *btnEvaluate = new QPushButton("Evaluate");
    proxyButton->setWidget(btnEvaluate);
    proxyButton->setPos(0,280);
    cena->addItem(proxyButton);

    connect(btnEvaluate,SIGNAL(clicked()),this,SLOT(evaluateJavaScript()));

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
    QColor am(Qt::yellow);
    am.setAlpha(100);

    QColor ve(Qt::green);
    ve.setAlpha(100);

    QColor vm(Qt::red);
    vm.setAlpha(100);

    amarela->setBrush(QBrush(Qt::yellow));
    vermelha->setBrush(QBrush(vm));
    verde->setBrush(QBrush(ve));
}

void MainWindow::entrouNoVermelho()
{
    QColor am(Qt::yellow);
    am.setAlpha(100);

    QColor ve(Qt::green);
    ve.setAlpha(100);

    QColor vm(Qt::red);
    vm.setAlpha(100);

    vermelha->setBrush(QBrush(Qt::red));
    amarela->setBrush(QBrush(am));
    verde->setBrush(QBrush(ve));
}

void MainWindow::entrouNoVerde()
{
    QColor am(Qt::yellow);
    am.setAlpha(100);

    QColor ve(Qt::green);
    ve.setAlpha(100);

    QColor vm(Qt::red);
    vm.setAlpha(100);

    verde->setBrush(QBrush(Qt::green));
    amarela->setBrush(QBrush(am));
    vermelha->setBrush(QBrush(vm));
}

void MainWindow::evaluateJavaScript()
{
    qDebug() << "Evaluating JAVA SCRIPT";
    QScriptValue valor = engine->evaluate(this->line->text());
    qDebug() << valor.toString();
    // qDebug() << QString::number(valor.toInt32());
}
