#include "switch_button.h"
#include <QPainter>
#include <QKeyEvent>

SwitchButton::SwitchButton(QWidget *parent) :
    QWidget(parent),SIZE(60,30),state(ON)
{
    resize(SIZE);
    setMinimumSize(SIZE);
    setMaximumSize(SIZE);

    //state = 1;

}

void SwitchButton::mousePressEvent(QMouseEvent *event)
{
    if(state == ON)
        state = OFF;
    else
        state = ON;

    emit this->stateChanged(state);

    update();
}

//TODO: implementar
void SwitchButton::keyPressEvent(QKeyEvent *event)
{
    switch(event->key())
    {
    case Qt::Key_Down:
        if(state == ON)
        {
            state = OFF;
            update();
            emit this->stateChanged(state);
        }
        break;
    case Qt::Key_Up:
        if(state == OFF)
        {
            state = ON;
            update();
            emit this->stateChanged(state);
        }
        break;
    case Qt::Key_Space:
        if(state == ON)state = OFF;
        else state = ON;
        update();
        emit this->stateChanged(state);
        break;
    default:
        QWidget::keyPressEvent(event);

    }
}

void SwitchButton::wheelEvent(QWheelEvent *event)
{
    int delta = event->delta();
    if(delta < 0)
    {
        if (state == ON)
        {
            state = OFF;
            emit this->stateChanged(state);
        }

    }
    else if (delta > 0)
    {
        if (state == OFF)
        {
            state = ON;
            emit this->stateChanged(state);
        }
    }
    update();
}

void SwitchButton::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setRenderHints(QPainter::Antialiasing);

    painter.drawRect(QRect(QPoint(0,0),SIZE));

    if(state == ON)
    {
      painter.setBrush(QBrush(Qt::black));
      painter.drawRect(QRect(QPoint(0,0), QSize(SIZE.width()/2, SIZE.height()) ) );

      painter.setBrush(QBrush(Qt::blue));
      painter.translate(SIZE.width()/2,0);
      painter.drawRect(QRect(QPoint(0,0), QSize(SIZE.width()/2, SIZE.height()) ) );
    }
    else // state == OFF
    {
        painter.setBrush(QBrush(Qt::red));
        painter.drawRect(QRect(QPoint(0,0), QSize(SIZE.width()/2, SIZE.height()) ) );

        painter.setBrush(QBrush(Qt::black));
        painter.translate(SIZE.width()/2,0);
        painter.drawRect(QRect(QPoint(0,0), QSize(SIZE.width()/2, SIZE.height()) ) );
    }


}



