#ifndef MINHA_THREAD_H
#define MINHA_THREAD_H

#include <QThread>

class MinhaThread : public QThread
{
    Q_OBJECT
public:
    explicit MinhaThread(QString name, QObject *parent = 0);
    void run();

private:
    QString name;

signals:
    void sinalEmitido(QString s);

public slots:
    void tempoEsgotado();

};

#endif // MINHA_THREAD_H
