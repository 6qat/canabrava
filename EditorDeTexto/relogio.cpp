#include "relogio.h"

Relogio::Relogio(QWidget *parent) :
    QWidget(parent)
{
    timer = new QTimer(this);
    timer->setInterval(1000);
    timer->start();

    connect(timer,SIGNAL(timeout()),this,SLOT(timerAcionado()));
}


void Relogio::paintEvent(QPaintEvent *)
{

}

void Relogio::timerAcionado()
{
    qDebug() << "###########   Timer acionado #################";
}
