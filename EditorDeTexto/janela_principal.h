#ifndef JANELA_PRINCIPAL_H
#define JANELA_PRINCIPAL_H

#include <QMainWindow>
#include <QWidget>
#include <QLabel>
#include <QStringListModel>
#include <QHash>
#include <QString>
#include <QListView>
#include <QModelIndex>
#include "relogio.h"

class JanelaPrincipal: public QMainWindow
{
    Q_OBJECT
public:
    JanelaPrincipal(QWidget *parent = 0);
    ~JanelaPrincipal();

private:
    QStringList fileList;
    QStringListModel *model;
    QHash<QString,QString> fileHash;
    QListView *listView;
    QModelIndex currentFileIndex; // Arquivo atual selecionado
    Relogio *relogio;

private slots:
    void createFile();
    void fileSelected(QModelIndex idx);
    void openFile();


};

#endif // JANELA_PRINCIPAL_H
