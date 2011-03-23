
#include <QCoreApplication>

#include "list.h"

int main(int argc, char *argv[])
{
        QCoreApplication a(argc, argv);

        //List *lista = new List();
        //(*lista)[0];

        List lista;
        lista +=1;
        lista +=7;
        lista << 12 << 13;

        lista.print();

        return a.exec();
}
