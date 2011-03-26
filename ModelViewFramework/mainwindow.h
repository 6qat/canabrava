#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "meu_modelo.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    MeuModelo *model;

public slots:
    void adicionarDados();
};

#endif // MAINWINDOW_H
