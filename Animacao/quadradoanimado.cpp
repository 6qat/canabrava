#include "quadradoanimado.h"
#include <QDebug>

#include <QGraphicsSceneMouseEvent>
#include <QPropertyAnimation>

QuadradoAnimado::QuadradoAnimado(QGraphicsItem *parent) :
    QGraphicsRectItem(parent)
{
    animation = new QPropertyAnimation(this,"x");
    animation->setDuration(5000);
    animation->setStartValue(0);
    animation->setEndValue(500);
}

void QuadradoAnimado::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    qDebug() << "Clicado";
    animation->start();
}
