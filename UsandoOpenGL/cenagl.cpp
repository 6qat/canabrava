#include "cenagl.h"
#include <QGLWidget>

CenaGL::CenaGL(QGLWidget *parent) :
    QGLWidget(parent)
{
}

void CenaGL::initializeGL()
{
    glClearColor(1,1,1,1);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0,600,0,600);
    glMatrixMode(GL_MODELVIEW);
}

void CenaGL::resizeGL(int w, int h)
{
}

void CenaGL::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1,0,0);
    glBegin(GL_QUADS);
    glVertex2f(200,200);
    glVertex2f(400,200);
    glVertex2f(400,400);
    glVertex2f(200,400);
    glEnd();
    glFlush();

}
