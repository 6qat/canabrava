#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "semaforo.h"


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
    Bolinha *verde, *vermelha, *amarela;

public slots:
    void entrouNoAmarelo();
    void entrouNoVermelho();
    void entrouNoVerde();
};

#endif // MAINWINDOW_H
