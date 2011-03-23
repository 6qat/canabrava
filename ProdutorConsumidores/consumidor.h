#ifndef CONSUMIDOR_H
#define CONSUMIDOR_H

#include <QThread>
#include <QListWidget>
#include <QString>
#include <QMutex>

class Consumidor : public QThread
{
    Q_OBJECT
public:
    explicit Consumidor(QListWidget *listProdutor, QObject *parent = 0);

private:
    QListWidget *listProdutor;
    static QMutex mtx;

protected:
    void run();

signals:
    void dadoConsumido(QString dado);

public slots:


};

#endif // CONSUMIDOR_H
