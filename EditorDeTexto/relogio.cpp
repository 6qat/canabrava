#include "relogio.h"

#include <QPainter>
#include <QTime>

Relogio::Relogio(QWidget *parent) :
    QWidget(parent),angleSecond(0),angleMinute(0),angleHour(0)
{
    timer = new QTimer(this);
    timer->setInterval(100);
    timer->start();

    connect(timer,SIGNAL(timeout()),this,SLOT(update()));

    resize(QSize(200,200));
}


void Relogio::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setRenderHints(QPainter::Antialiasing);

    QColor hora(Qt::blue);
    QColor minuto(Qt::green);
    QColor second(Qt::black);

    QTime time = QTime::currentTime();
    this->angleSecond = 180 + time.second()*6;
    this->angleMinute = 180 + time.minute()*6;
    this->angleHour = 180 + time.hour()*30;

    // Horas
    painter.setBrush(QBrush(hora));
    painter.setPen(QPen(hora,5));
    painter.translate(this->width()/2,this->height()/2);

    painter.save();

    for(int i=0; i<12;++i)
    {
        painter.drawLine(QPoint(0,80), QPoint(0,100));
        painter.rotate(30);

    }

    // Minutes
    painter.restore();
    painter.save();

    painter.setBrush(QBrush(minuto));
    painter.setPen(QPen(minuto,2));

    for(int i=0; i<12*60;++i)
    {
        painter.drawLine(QPoint(0,90), QPoint(0,100));
        painter.rotate(6);

    }
\
    // Desenha o ponteiro de Seconds
    painter.restore();
    painter.save();

    painter.setBrush(QBrush(second));
    painter.setPen(QPen(second,1));

    painter.rotate(this->angleSecond);
    painter.drawLine(QPoint(0,0), QPoint(0,100));

    // desenha o ponteiro de minutos
    painter.restore();
    painter.save();

    painter.setBrush(QBrush(minuto));
    painter.setPen(QPen(minuto,2));

    painter.rotate(this->angleMinute);
    painter.drawLine(QPoint(0,0), QPoint(0,90));



    // desenha o ponteiro de horas
    painter.restore();
    painter.save();

    painter.setBrush(QBrush(hora));
    painter.setPen(QPen(hora,5));

    painter.rotate(this->angleHour);
    painter.drawLine(QPoint(0,0), QPoint(0,50));

    painter.restore();



}

void Relogio::timerSecondAcionado()
{
    //qDebug() << "###########   Timer acionado #################";
    //angleSecond +=6;
    update();

}
