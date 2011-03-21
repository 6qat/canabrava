#ifndef SNAKE_H
#define SNAKE_H

#include <QGraphicsView>
#include <QKeyEvent>

class Snake : public QGraphicsView
{
    Q_OBJECT
public:
    explicit Snake(QWidget *parent = 0);
    enum m_direcao_type {Up, Down,Left,Right} ;

protected:
    void keyPressEvent(QKeyEvent *event);


signals:

public slots:
    void andar();

private:
    QList<QGraphicsItem*> m;
    m_direcao_type m_direcao;


};

#endif // SNAKE_H
