#ifndef MEU_MODELO_H
#define MEU_MODELO_H

#include <QAbstractListModel>
#include <QStringList>

class MeuModelo : public QAbstractListModel
{
    Q_OBJECT
public:
    explicit MeuModelo(QStringList list, QObject *parent = 0);

    int rowCount(const QModelIndex &parent = QModelIndex()) const
    {
        return lista.count();
    }

    QVariant data(const QModelIndex &index, int role) const
    {
        if (!index.isValid() || index.row() > rowCount(index) )
            return QVariant();

        if (role == Qt::DisplayRole || role ==  Qt::EditRole)
            return lista.at(index.row());

        return QVariant();
    }

    QVariant headerData(int section, Qt::Orientation orientation, int role) const
    {
        return QVariant();
    }

    Qt::ItemFlags flags(const QModelIndex &index) const
    {
        if(!index.isValid())
            return Qt::ItemIsEnabled;
        else
            return QAbstractItemModel::flags(index) | Qt::ItemIsEditable;
    }

    bool setData(const QModelIndex &index, const QVariant &value, int role=Qt::EditRole)
    {
        //QVariant data = data(index, Qt::DisplayRole);
        if (! index.isValid() || role != Qt::EditRole)
            return false;

        lista.replace(index.row(), value.toString());
        emit dataChanged(index,index);
        return true;
    }

    bool insertRows(int row, int count, const QModelIndex &parent = QModelIndex())
    {
        beginInsertRows(parent,row,row+count-1);
        for(int i=0;i<count; ++i)
            this->lista << QString("Elemento %1").arg(i);
        endInsertRows();
        return true;
    }

    bool removeRows(int row, int count, const QModelIndex &parent)
    {

    }



private:
    QStringList lista;

signals:

public slots:

};

#endif // MEU_MODELO_H
