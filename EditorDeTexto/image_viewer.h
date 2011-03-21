#ifndef IMAGE_VIEWER_H
#define IMAGE_VIEWER_H

#include <QWidget>
#include <QLabel>
#include <QSpinBox>

class ImageViewer : public QWidget
{
    Q_OBJECT
public:
    explicit ImageViewer(QWidget *parent = 0);

private:
    QLabel img;
    QPixmap pix;
    const QSize SIZE;

signals:

public slots:
    void loadImage();
    void colorChanged(int color);
};

#endif // IMAGE_VIEWER_H
