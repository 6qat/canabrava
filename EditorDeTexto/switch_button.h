#ifndef SWITCH_BUTTON_H
#define SWITCH_BUTTON_H

#include <QWidget>
#include <QSize>
#include <QDebug>

class SwitchButton : public QWidget
{
    Q_OBJECT
    Q_ENUMS(stateType)

public:
    explicit SwitchButton(QWidget *parent = 0);
    enum stateType {ON, OFF};

protected:
    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent *);
    void keyPressEvent(QKeyEvent *);
    void wheelEvent(QWheelEvent *);

private:
    const QSize SIZE;
    stateType state;


signals:
    void stateChanged(stateType state);

public slots:
    void teste(stateType state)
    {
        if(state == ON)
            qDebug() << "Estado trocado para ON";
        else
            qDebug() << "Estado trocado para OFF";
    }


};

#endif // SWITCH_BUTTON_H
