#ifndef SEMAFORO_H
#define SEMAFORO_H

#include <QGraphicsRectItem>

class Semaforo : public QGraphicsRectItem
{

public:
    explicit Semaforo(QGraphicsItem *parent = 0);

protected:


signals:

public slots:

};


class Bolinha: public QGraphicsEllipseItem
{
public:
    explicit Bolinha(QGraphicsItem *parent = 0);

};

#endif // SEMAFORO_H
