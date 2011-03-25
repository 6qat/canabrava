#ifndef SEMAFORO_H
#define SEMAFORO_H

#include <QGraphicsRectItem>
#include <QBrush>
#include <QObject>

class Semaforo : public QObject, public QGraphicsRectItem
{
    Q_OBJECT

public:
    explicit Semaforo(QGraphicsItem *parent = 0);

    Q_PROPERTY (QColor cor READ cor WRITE setCor)
    QColor cor()
    {
        return this->brush().color();
    }
    void setCor(QColor c)
    {
        this->setBrush(QBrush(c));
    }


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
