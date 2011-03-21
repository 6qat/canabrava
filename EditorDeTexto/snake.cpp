#include "snake.h"
#include <QGraphicsScene>
#include <QTimer>
#include <QGraphicsRectItem>


Snake::Snake(QWidget *parent):QGraphicsView(parent),m_direcao(Up)
{
    setScene(new QGraphicsScene());
    scene()->setSceneRect(0,0,800,600);
    QTimer *t = new QTimer();
    t->start(250);
    connect(t,SIGNAL(timeout()),this,SLOT(andar()));

    for (int i=0; i< 3; ++i)
    {
         QGraphicsRectItem *item = new QGraphicsRectItem(0,0,20,20);
         scene()->addItem(item);
         m << item;
    }

    m[0]->setPos(400,300);
    m[1]->setPos(420,300);
    m[2]->setPos(440,300);

    QGraphicsRectItem *bordaCena = new QGraphicsRectItem(scene()->sceneRect());
    scene()->addItem(bordaCena);
}


void Snake::keyPressEvent(QKeyEvent *event)
{

    switch(event->key())
    {
    case Qt::Key_Down:
        m_direcao = Down;
        break;
    case Qt::Key_Up:
        m_direcao = Up;
        break;
    case Qt::Key_Left:
        m_direcao = Left;
        break;
    case Qt::Key_Right:
        m_direcao = Right;
        break;
    default:
        QWidget::keyPressEvent(event);

    }
}

void Snake::andar()
{
    QGraphicsItem * tail = m.takeLast();
    QGraphicsItem * head = m.at(0);

    int x = head->x();
    int y = head->y();

    switch(m_direcao)
    {
        case Up:
            y-=20;
            break;

        case Down:
            y+=20;
            break;

        case Left:
            x-=20;
            break;

        case Right:
            x+=20;
            break;
    }


    tail->setPos(x,y);
    m.prepend(tail);

}
