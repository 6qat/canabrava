#include "janela_principal.h"
#include <QAction>
#include <QMenuBar>
#include <QStatusBar>
#include <QMenu>
#include <QToolBar>

#include <QTextEdit>
#include <QListView>
#include <QStringListModel>

#include <QLineEdit>

#include <QDockWidget>
#include <QDebug>


JanelaPrincipal::JanelaPrincipal(QWidget *pai):QMainWindow(pai)
{
    this->setCentralWidget(new QLabel("Teste"));

    QAction *openFile = new QAction("Open file", this);
    QAction *saveFile = new QAction("Save file",this);
    QAction *newFile = new QAction("New file", this);
    QAction *exitProgram = new QAction("Exit", this);

    connect(exitProgram, SIGNAL(triggered()), this, SLOT(close()));
    connect(newFile, SIGNAL(triggered()),this,SLOT(createFile() ));

    QMenu *menu = new QMenu("Arquivo");
    menu->addAction(newFile);
    menu->addAction(openFile);
    menu->addAction(saveFile);
    menu->addAction(exitProgram);
    menuBar()->addMenu(menu);

    //Qlistview

    QDockWidget *dock = new QDockWidget("Ferramentas");
    this->listView = new QListView(dock);

    this->model = new QStringListModel(this);
    //this->fileList << "lkajdfladkfj";
    this->model->setStringList(this->fileList);

    this->listView->setModel(model);
    dock->setWidget(this->listView);
    addDockWidget(Qt::LeftDockWidgetArea, dock);

    QToolBar *tool = new QToolBar("Barra de ferramentas");
    tool->addAction(newFile);
    tool->addAction(openFile);
    tool->addAction(saveFile);
    tool->addAction(exitProgram);
    addToolBar(tool);

    this->statusBar()->showMessage("Editando o texto ...");

    QTextEdit *textEdit = new QTextEdit(this);
    textEdit->setAcceptRichText(true);
    this->setCentralWidget(textEdit);

    connect(this->listView,SIGNAL(clicked(QModelIndex)), this,SLOT(fileSelected(QModelIndex)));
}

JanelaPrincipal::~JanelaPrincipal()
{

}

void JanelaPrincipal::createFile()
{

    QString fileName = QString("Arquivo %1").arg( fileList.count());
    this->fileList << fileName;
    QString text("Novo arquivo");
    this->fileHash[fileName]=text;
    this->model->setStringList(this->fileList);
    QTextEdit *textEdit = qobject_cast<QTextEdit*>( this->centralWidget() );
    textEdit->setPlainText(text);

}

void JanelaPrincipal::fileSelected(QModelIndex idx)
{
    /*
     * Salva o texto atual no arquivo anterior
     * Pega o nome do novo arquivo selecionado em fileList
     * Apaga o texto atual
     * Pega o texto correspondente no hash
     * Mostra o texto
     */
    QTextEdit *textEdit = qobject_cast<QTextEdit*>( this->centralWidget() );
    QString oldFileName = this->model->data(this->currentFileIndex, Qt::DisplayRole).toString();
    this->fileHash[oldFileName] = textEdit->toPlainText();


    this->currentFileIndex = idx;
    QString fileName =  this->model->data(idx, Qt::DisplayRole ).toString() ;
    textEdit->setPlainText(this->fileHash[fileName]);

    qDebug() << "Arquivo selecionado: " << fileName;

}
