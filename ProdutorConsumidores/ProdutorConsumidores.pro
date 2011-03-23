#-------------------------------------------------
#
# Project created by QtCreator 2011-03-20T16:20:51
#
#-------------------------------------------------

QT       += core gui

TARGET = ProdutorConsumidores
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    produtor.cpp \
    consumidor.cpp \
    ../ListaEncadeada/node.cpp \
    ../ListaEncadeada/list.cpp

HEADERS  += mainwindow.h \
    produtor.h \
    consumidor.h \
    ../ListaEncadeada/node.h \
    ../ListaEncadeada/list.h

FORMS    += mainwindow.ui
