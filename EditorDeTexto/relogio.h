#ifndef RELOGIO_H
#define RELOGIO_H

#include <QWidget>
#include <QTimer>
#include <QDebug>

class Relogio : public QWidget
{
    Q_OBJECT
public:
    explicit Relogio(QWidget *parent = 0);

protected:
    void paintEvent(QPaintEvent *);


signals:

public slots:
    void timerSecondAcionado();

private:
    QTimer * timer;
    int angleSecond;
    int angleMinute;
    int angleHour;

};

#endif // RELOGIO_H
