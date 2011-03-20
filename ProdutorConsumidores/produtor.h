#ifndef PRODUTOR_H
#define PRODUTOR_H

#include <QThread>

class Produtor : public QThread
{
    Q_OBJECT
public:
    explicit Produtor(QObject *parent = 0);

private:
    int cont;

signals:
    void dadoProduzido(QString s);

public slots:
    void produzir();

};

#endif // PRODUTOR_H
