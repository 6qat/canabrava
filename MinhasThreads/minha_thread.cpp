#include "minha_thread.h"

#include <QDebug>
#include <QTimer>

MinhaThread::MinhaThread(QString name, QObject *parent) :
    QThread(parent),name(name)
{
    QTimer *timer = new QTimer;
    timer->setInterval(rand()%1000);

    connect(timer,SIGNAL(timeout()),this, SLOT(tempoEsgotado()));

    timer->start();
}


void MinhaThread::run()
{


    exec();
}

void MinhaThread::tempoEsgotado()
{
    QString s = QString("Minha thread %1, %2").arg(name).arg(rand()%1000);
    //s.append(name);
    //s.arg(name);
    emit sinalEmitido(s);
}

