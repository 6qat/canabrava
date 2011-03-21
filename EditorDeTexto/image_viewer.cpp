#include "image_viewer.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QFileDialog>
#include <QPixmap>
#include <QDebug>

ImageViewer::ImageViewer(QWidget *parent) :
    QWidget(parent),SIZE(400,200)
{
    resize(SIZE);
    //setMinimumSize(SIZE);
    //setMaximumSize(SIZE);

    img.setText("<< IMAGEM >>");

    QVBoxLayout *buttons = new QVBoxLayout();
    QSpinBox *sp1 = new QSpinBox(this);sp1->setRange(0,255);sp1->setPrefix("R ");
    QSpinBox *sp2 = new QSpinBox(this);sp2->setRange(0,255);sp2->setPrefix("G ");
    QSpinBox *sp3 = new QSpinBox(this);sp3->setRange(0,255);sp3->setPrefix("B ");

    connect(sp1,SIGNAL(valueChanged(int)),this,SLOT(colorChanged(int)));
    connect(sp2,SIGNAL(valueChanged(int)),this,SLOT(colorChanged(int)));
    connect(sp3,SIGNAL(valueChanged(int)),this,SLOT(colorChanged(int)));

    QPushButton *btnLoadImage = new QPushButton("Load Image");
    connect(btnLoadImage,SIGNAL(clicked()),SLOT(loadImage()));

    buttons->addWidget(sp1);
    buttons->addWidget(sp2);
    buttons->addWidget(sp3);
    buttons->addWidget(btnLoadImage);

    QHBoxLayout *line = new QHBoxLayout();

    line->addWidget(&this->img);
    line->addLayout(buttons);

    this->setLayout(line);
}

void ImageViewer::loadImage()
{
    QFileDialog dialog(this);
    dialog.setFileMode(QFileDialog::AnyFile);
    dialog.setViewMode(QFileDialog::Detail);
    QString imageName;
    QStringList images;
    if (dialog.exec())
    {
        images = dialog.selectedFiles();
        if (images.count())
            imageName = images[0];
    }
    if(imageName != "")
    {
        pix = QPixmap(imageName);
        this->img.setPixmap( pix );
    }

}

void ImageViewer::colorChanged(int color)
{
     //sender()
    QSpinBox * sb = qobject_cast<QSpinBox *>(sender());
    qDebug() << sb->prefix();
    qDebug() << color;
    QImage imagem = this->img.pixmap()->toImage();
    for(int i=0; i<imagem.width(); ++i)
    {
        for(int j=0; j<imagem.height(); ++j)
        {
            QColor c(imagem.pixel(i,j));
            if(sb->prefix()==QString("R ") )
                c.setRed(color);
            else if(sb->prefix()== QString("G ") )
                c.setGreen(color);
            else if(sb->prefix()==QString("B ") )
                c.setBlue(color);

            imagem.setPixel(i,j,c.rgb());
        }
    }
    this->img.setPixmap(QPixmap::fromImage(imagem));

}
