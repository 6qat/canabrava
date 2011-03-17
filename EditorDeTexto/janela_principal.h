#ifndef JANELA_PRINCIPAL_H
#define JANELA_PRINCIPAL_H

#include <QMainWindow>
#include <QWidget>
#include <QLabel>
#include <QStringListModel>
#include <QHash>
#include <QString>

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

private slots:
    void createFile();
    void fileSelected();


};

#endif // JANELA_PRINCIPAL_H
