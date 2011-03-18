#include <QApplication>
#include <QLabel>
#include "janela_principal.h"
#include "relogio.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //QLabel *lbl = new QLabel("teste");
    //lbl->show();

    //JanelaPrincipal janela;
    //janela.show();

    Relogio relogio;
    relogio.show();

    return a.exec();
}
