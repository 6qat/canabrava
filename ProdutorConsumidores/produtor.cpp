#include "produtor.h"

#include <QTimer>
#include <QDebug>

Produtor::Produtor(QObject *parent) :
    QThread(parent),cont(0)
{
    QTimer *timer = new QTimer;
    timer->setInterval(1000);
    connect(timer,SIGNAL(timeout()),this,SLOT(produzir()));
    timer->start();

}

void Produtor::produzir()
{
    //static int cont = 0;
    QString dado = QString("Produzindo dado %1").arg(cont);
    //qDebug() << dado;
    emit dadoProduzido(dado);
    cont++;
}
