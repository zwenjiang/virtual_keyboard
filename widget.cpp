#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    m_edit = new My_lineEdit(this);
    m_edit->setObjectName("lineEdit0");
    m_edit->setGeometry(10,10,200,20);

    numberkeyboard = new MyKeyDialog();
    connect(m_edit,SIGNAL(send_show(QString)),this,SLOT(show_numberkeyboard_ui(QString)));
    connect(ui->lineEdit1,SIGNAL(send_show(QString)),this,SLOT(show_numberkeyboard_ui(QString)));

    connect(numberkeyboard,SIGNAL(sendMessage(QString)),this,SLOT(confirmString(QString)));
}

Widget::~Widget()
{
    delete ui;
}
void Widget::show_numberkeyboard_ui(QString data){
    lineEdit_object = sender()->objectName();
    numberkeyboard->lineEdit_window->setText(data);
    numberkeyboard->show();
}
void Widget::confirmString(QString gemfield){
    if(lineEdit_object==ui->lineEdit1->objectName())
        ui->lineEdit1->setText(gemfield);
    else
        m_edit->setText(gemfield);
}
