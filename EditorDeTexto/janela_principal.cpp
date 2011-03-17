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

#include <QFileDialog>
#include <QFile>

#include <QMessageBox>

#include "relogio.h"

JanelaPrincipal::JanelaPrincipal(QWidget *pai):QMainWindow(pai)
{
    this->setCentralWidget(new QLabel("Teste"));

    QAction *openFile = new QAction("Open file", this);
    QAction *saveFile = new QAction("Save file",this);
    QAction *newFile = new QAction("New file", this);
    QAction *exitProgram = new QAction("Exit", this);

    connect(exitProgram, SIGNAL(triggered()), this, SLOT(close()));
    connect(newFile, SIGNAL(triggered()),this,SLOT(createFile() ));
    connect(openFile, SIGNAL(triggered()),this,SLOT(openFile() ));


    QMenu *menu = new QMenu("Arquivo");
    menu->addAction(newFile);
    menu->addAction(openFile);
    menu->addAction(saveFile);
    menu->addAction(exitProgram);
    menuBar()->addMenu(menu);

    //Qlistview

    QDockWidget *dock = new QDockWidget("Ferramentas");
    QDockWidget *dock2 = new QDockWidget("Ferramentas2");

    this->listView = new QListView(dock);



    this->model = new QStringListModel(this);
    //this->fileList << "lkajdfladkfj";
    this->model->setStringList(this->fileList);

    this->listView->setModel(model);
    dock->setWidget(this->listView);

    addDockWidget(Qt::LeftDockWidgetArea, dock);
    addDockWidget(Qt::RightDockWidgetArea, dock2);


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

    relogio = new Relogio;
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


void JanelaPrincipal::openFile()
{
    QFileDialog dialog(this);
    dialog.setFileMode(QFileDialog::AnyFile);
    dialog.setViewMode(QFileDialog::Detail);
    QStringList fileNames;
    if (dialog.exec())
        fileNames = dialog.selectedFiles();

    if (!fileNames.count())
        return;

    qDebug() << fileNames;
    QString fileName = fileNames[0];

    QFile arq(fileName);
    QString texto;

    if (arq.open(QFile::ReadOnly))
    {
        QTextStream data(&arq);

        texto = data.readAll();

        qDebug() << texto;
    }
    else
    {
        QMessageBox::warning(this,"Erro",QString("Impossivel abrir o arquivo %1").arg(fileName));
        return;
    }

    this->fileList << fileName;
    this->fileHash[fileName]=texto;
    this->model->setStringList(this->fileList);
    QTextEdit *textEdit = qobject_cast<QTextEdit*>( this->centralWidget() );
    textEdit->setPlainText(texto);

    //this->currentFileIndex

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
    //QString fileName =  this->model->data(idx, Qt::DisplayRole ).toString() ;
    QString fileName = this->fileList[idx.row()];
    textEdit->setPlainText(this->fileHash[fileName]);


    qDebug() << "Arquivo selecionado: " << fileName;
    qDebug() << "Conteudo do arquivo: " << this->fileHash[fileName];


}
