#include <QApplication>
#include <QLabel>
#include "janela_principal.h"
#include "relogio.h"
#include "switch_button.h"
#include "image_viewer.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //QLabel *lbl = new QLabel("teste");
    //lbl->show();

    //JanelaPrincipal janela;
    //janela.show();

    //Relogio relogio;
    //relogio.show();

    //SwitchButton *btn = new SwitchButton();
    //QObject::connect(btn,SIGNAL(stateChanged(stateType)),btn, SLOT(teste(stateType)));
    //btn->show();

    ImageViewer *iv = new ImageViewer();
    iv->show();

    return a.exec();
}
