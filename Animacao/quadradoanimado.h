#ifndef QUADRADOANIMADO_H
#define QUADRADOANIMADO_H

#include <QGraphicsRectItem>

class QPropertyAnimation;
class QGraphicsSceneMouseEvent;
class QRectF;

class QuadradoAnimado :public QObject, public QGraphicsRectItem
{
    Q_OBJECT
private:
    Q_PROPERTY(int x READ x WRITE setX)
    Q_PROPERTY(QRectF rect READ rect WRITE setRect)
public:
    explicit QuadradoAnimado(QGraphicsItem *parent = 0);
    void setEasyingCurve(QEasingCurve ec);

signals:

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    QPropertyAnimation *animation;
    QPropertyAnimation *animationWidth, *animationHeight;

public slots:

};

#endif // QUADRADOANIMADO_H
