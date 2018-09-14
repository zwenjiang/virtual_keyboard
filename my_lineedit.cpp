#include "my_lineedit.h"

My_lineEdit::My_lineEdit(QWidget *parent) :
    QLineEdit(parent)
{
    this->setText("521");
}

void My_lineEdit::mousePressEvent(QMouseEvent *event)
{
    emit send_show(this->text());
    QLineEdit::mousePressEvent(event);
}
