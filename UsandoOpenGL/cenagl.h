#ifndef CENAGL_H
#define CENAGL_H

#include <QGLWidget>

class CenaGL : public QGLWidget
{
    Q_OBJECT
public:
    explicit CenaGL(QGLWidget *parent = 0);

protected:
    void initializeGL();
    void resizeGL(int w, int h);
    void paintGL();

signals:

public slots:

};

#endif // CENAGL_H
