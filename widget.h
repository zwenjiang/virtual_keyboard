#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <my_lineedit.h>
#include "mykeydialog.h"
#include <QKeyEvent>
namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

public slots:
    void show_numberkeyboard_ui(QString data);     //显示键盘
    void confirmString(QString gemfield);   //接收键盘发过来的数据
private:
    Ui::Widget *ui;
    QLineEdit *m_edit;
    MyKeyDialog *numberkeyboard;
    QKeyEvent *event;
    QString lineEdit_object;
};

#endif // WIDGET_H
