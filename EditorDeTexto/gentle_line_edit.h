#ifndef GENTLE_LINE_EDIT_H
#define GENTLE_LINE_EDIT_H

#include <QLineEdit>
#include <QPaintEvent>

class GentleLineEdit: public QLineEdit
{
public:
    GentleLineEdit(QWidget *p);

private:
    void paintEvent ( QPaintEvent * ); // virtual protected em QLineEdit
};

#endif // GENTLE_LINE_EDIT_H
