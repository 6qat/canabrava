#ifndef MEU_MODELO_H
#define MEU_MODELO_H

#include <QAbstractListModel>
#include <QStringList>

class MeuModelo : public QAbstractListModel
{
    Q_OBJECT
public:
    explicit MeuModelo(QStringList list, QObject *parent = 0);

    int rowCount(const QModelIndex &parent) const
    {
        return lista.count();
    }

    QVariant data(const QModelIndex &index, int role) const
    {
        if (!index.isValid() || index.row() > rowCount(index) )
            return QVariant();

        if (role == Qt::DisplayRole)
            return lista.at(index.row());
    }

    QVariant headerData(int section, Qt::Orientation orientation, int role) const
    {
        return QVariant();
    }

private:
    QStringList lista;

signals:

public slots:

};

#endif // MEU_MODELO_H
