#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include "semaforo.h"

class QScriptEngine;

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
    QScriptEngine *engine;
    QLineEdit *line; // Texto com o codigo em Javascript


public slots:
    void entrouNoAmarelo();
    void entrouNoVermelho();
    void entrouNoVerde();
    void evaluateJavaScript();
};

#endif // MAINWINDOW_H
