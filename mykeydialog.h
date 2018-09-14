#ifndef MYKEYDIALOG_H
#define MYKEYDIALOG_H

#include <QDialog>
#include "ui_mykeydialog.h"
#include <QKeyEvent>

class MyKeyDialog : public QDialog,public Ui::MyKeyDialog
{
    Q_OBJECT
public:
     MyKeyDialog();
    ~MyKeyDialog();
     void affirmString();
     void deleteString();
     void changeNumLowerUpper();
     void initGb();
public slots:
    void buttonClickResponse(int gemfield);
signals:
    void sendMessage(QString gemfield);
private:
    Ui::MyKeyDialog *ui;
    QKeyEvent *event;
    QButtonGroup *button_group;
    QVector<QPushButton*> button_vector;

    int num_lower_upper;
};

#endif // MYKEYDIALOG_H
