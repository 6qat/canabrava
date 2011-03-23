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

    animationWidth = new QPropertyAnimation(this,"rect");
    animationWidth->setDuration(5000);
    animationWidth->setStartValue(QRectF(0,0,10,10));
    animationWidth->setEndValue(QRectF(0,0,50,50));


}

void QuadradoAnimado::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    qDebug() << "Clicado";
    animation->start();
    animationWidth->start();
}

void QuadradoAnimado::setEasyingCurve(QEasingCurve ec)
{
    animation->setEasingCurve(ec);
}
