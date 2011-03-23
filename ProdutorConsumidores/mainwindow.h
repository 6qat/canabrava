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

signals:
    void dadoAdicionado();

private slots:
    void adicionaDadoProduzido(QString s);
    void atualizaScrollProdutor(int, int);

    void adicionaDadoConsumido1(QString s);
    void adicionaDadoConsumido2(QString s);
    void adicionaDadoConsumido3(QString s);

};

#endif // MAINWINDOW_H
