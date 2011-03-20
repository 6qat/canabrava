#ifndef CONSUMIDOR_H
#define CONSUMIDOR_H

#include <QThread>

class Consumidor : public QThread
{
    Q_OBJECT
public:
    explicit Consumidor(QObject *parent = 0);

signals:

public slots:

};

#endif // CONSUMIDOR_H
