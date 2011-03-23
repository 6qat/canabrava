#ifndef QUADRADOANIMADO_H
#define QUADRADOANIMADO_H

#include <QGraphicsRectItem>

class QPropertyAnimation;
class QGraphicsSceneMouseEvent;

class QuadradoAnimado :public QObject, public QGraphicsRectItem
{
    Q_OBJECT
private:
    Q_PROPERTY(int x READ x WRITE setX)
public:
    explicit QuadradoAnimado(QGraphicsItem *parent = 0);

signals:

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    QPropertyAnimation *animation;

public slots:

};

#endif // QUADRADOANIMADO_H
