#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>
#include <QList>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),display("")
{
    ui->setupUi(this);

    QList<QPushButton*> lista;
    lista << ui->b1 << ui->b2 << ui->b3 << ui->b4 << ui->b5 << ui->b6 << ui->b7 << ui->b8 << ui->b9 << ui->b0;


    foreach(QPushButton *b, lista)
    {
        connect (b, SIGNAL(clicked()), this, SLOT(botaoAcionado()));
    }

    connect(ui->bMais, SIGNAL(clicked()), this,SLOT(operacao()));
    connect(ui->bMenos, SIGNAL(clicked()), this,SLOT(operacao()));
    connect(ui->bVezes, SIGNAL(clicked()), this,SLOT(operacao()));
    connect(ui->bDiv, SIGNAL(clicked()), this,SLOT(operacao()));

    connect(ui->bC, SIGNAL(clicked()), this, SLOT(clear()));

    connect(ui->bEnter, SIGNAL(clicked()), this, SLOT(calc()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::botaoAcionado()
{

    QPushButton *botao = qobject_cast<QPushButton*>( sender() );
    display = display + botao->text();

    ui->lcdNumber->setNumDigits(10);

    ui->lcdNumber->display(display);

    //qDebug() << botao->text();
}

void MainWindow::operacao()
{
    QPushButton *botao = qobject_cast<QPushButton*>( sender() );

    this->operando1 = this->ui->lcdNumber->value();

    qDebug() << "Operando 1: " << this->operando1;

    this->op = botao->text();

    this->clear();

}

void MainWindow::clear()
{
    this->display = QString("");
    this->ui->lcdNumber->display(0);
}

void MainWindow::calc()
{
    this->operando2 = this->ui->lcdNumber->value();
    if(this->op == "+")
        this->ui->lcdNumber->display(this->operando1 + this->operando2);

    if(this->op == "-")
        this->ui->lcdNumber->display(this->operando1 - this->operando2);

    if(this->op == "*")
        this->ui->lcdNumber->display(this->operando1 * this->operando2);

    if(this->op == "/")
        this->ui->lcdNumber->display(this->operando1 / this->operando2);
}
