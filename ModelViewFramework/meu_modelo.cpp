#include "meu_modelo.h"

MeuModelo::MeuModelo(QStringList list, QObject *parent) :
    QAbstractListModel(parent)
{
    this->lista = list;
}
