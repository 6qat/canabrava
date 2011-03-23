#include "consumidor.h"
#include <QMutex>

QMutex Consumidor::mtx ;

Consumidor::Consumidor(QListWidget *l, QObject *parent) :
    QThread(parent),listProdutor(l)
{
}

void Consumidor::run()
{
    for(;;)
    {
//        QMutex mtx;
//        mtx.lock();
        mtx.lock();
        QListWidgetItem *item = this->listProdutor->takeItem(0);

        if(item)
        {
            QString dado = item->data(Qt::DisplayRole).toString();
            emit dadoConsumido(dado);

        }
        mtx.unlock();
    }

    //exec();
}


