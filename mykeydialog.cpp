#include "mykeydialog.h"

QString number[30]={"0","1","2","3","4","5",
                    "6","7","8","9",".","!",
                    "@","#","$","%","[","]",
                    "*","(",")","-","+","/",
                    "?",",","~","abc","BackSpace"};
QString upperCase[30]={"A","B","C","D","E","F",
                       "G","H","I","J","K","L",
                       "M","N","O","P","Q","R",
                       "S","T","U","V","W","X",
                       "Y","Z","~","123","BackSpace"};
QString lowerCase[30]={"a","b","c","d","e","f",
                       "g","h","i","j","k","l",
                       "m","n","o","p","q","r",
                       "s","t","u","v","w","x",
                       "y","z","~","ABC","BackSpace"};

MyKeyDialog::MyKeyDialog() :
    QDialog(0,Qt::Tool | Qt::WindowStaysOnTopHint | Qt::FramelessWindowHint),button_group(new QButtonGroup(this))
{
    setupUi(this);
    initGb ();
}

MyKeyDialog::~MyKeyDialog()
{
    //delete ui;
}

void MyKeyDialog::initGb()
{
    num_lower_upper = 1; //1: num 2:小寫 3:大寫

    QPushButton *pushButton=new QPushButton(this);          //创建一个按钮对象
    pushButton->hide();                                     //按钮隐藏起来
    pushButton=pushButton_ok;
    for(int i=1;i<32;i++)
    {
        pushButton->setAutoFillBackground(true);
        pushButton->setFocusPolicy(Qt::NoFocus);
        button_vector.push_back(pushButton);      //按钮集合，push_back（）～～ It is equivalent to append(value)，往按钮集合中添加一个按钮
        button_group->addButton(pushButton,i);    //添加一个按钮到button_group中，并且给按钮编号
        pushButton=qobject_cast<QPushButton *>(pushButton->nextInFocusChain());     //焦点指向下一个button
    }
    connect(button_group,SIGNAL(buttonClicked(int)),SLOT(buttonClickResponse(int)));
}
void MyKeyDialog::buttonClickResponse(int gemfield)
{
    if(gemfield==1)
    {
        affirmString ();
        return;
    }
    else if(gemfield==30) //del
    {
        deleteString ();
        return;
    }
    else if(gemfield==29) //num Upper Lower
    {
        changeNumLowerUpper();
        return;
    }
    else
    {
        switch (num_lower_upper)
        {
            case 1:
                event=new QKeyEvent(QEvent::KeyPress, 0, Qt::NoModifier,number[gemfield-2]);
                break;
            case 2:
                event=new QKeyEvent(QEvent::KeyPress, 0, Qt::NoModifier,lowerCase[gemfield-2]);
                break;
            case 3:
                event=new QKeyEvent(QEvent::KeyPress, 0, Qt::NoModifier,upperCase[gemfield-2]);
                break;
            default:
                event=new QKeyEvent(QEvent::KeyPress, 0, Qt::NoModifier,number[gemfield-2]);
                break;
        }
    }

    lineEdit_window->setFocus();
    QApplication::sendEvent(focusWidget(),event);
}
void MyKeyDialog::affirmString()
{
    emit sendMessage(lineEdit_window->text());               //发送信号给界面
    this->hide();
}

void MyKeyDialog::changeNumLowerUpper()  //改变大小写和數字
{
    int i = 0;

    if(pushButton_28->text()=="123")       //如果按鈕是abc
    {
        num_lower_upper=2;
        pushButton_28->setText("abc");   //设置称小写

        while(i<30)
        {
            button_vector.at(i+1)->setText(lowerCase[i]);
            i++;
        }
    }
    else if(pushButton_28->text()=="abc")       //如果按鈕是ABC
    {
        num_lower_upper=3;
        pushButton_28->setText("ABC");   //设置称大写

        while(i<30)
        {
            button_vector.at(i+1)->setText(upperCase[i]);
            i++;
        }
    }
    else if(pushButton_28->text()=="ABC")       //如果按鈕是ABC
    {
        num_lower_upper=1;
        pushButton_28->setText("123");   //设置称大写

        while(i<30)
        {
            button_vector.at(i+1)->setText(number[i]);
            i++;
        }
    }
}
void MyKeyDialog::deleteString ()
{
    event=new QKeyEvent(QEvent::KeyPress, Qt::Key_Backspace, Qt::NoModifier);       //新建一个键盘事件
    lineEdit_window->setFocus();
    QApplication::sendEvent(focusWidget(),event);
}
