#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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
    QString display;

    double operando1, operando2;

    QString op;

public slots:
    void botaoAcionado();
    void operacao();
    void clear();
    void calc();

};

#endif // MAINWINDOW_H
