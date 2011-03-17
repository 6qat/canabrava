#include <QApplication>
#include <QLabel>
#include "janela_principal.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //QLabel *lbl = new QLabel("teste");
    //lbl->show();

    JanelaPrincipal janela;
    janela.show();


    return a.exec();
}
