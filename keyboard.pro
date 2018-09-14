#-------------------------------------------------
#
# Project created by QtCreator 2018-09-01T22:08:16
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = keyboard
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp\
my_lineedit.cpp \
    mykeydialog.cpp

HEADERS  += widget.h\
my_lineedit.h \
    mykeydialog.h


FORMS    += widget.ui \
    mykeydialog.ui
