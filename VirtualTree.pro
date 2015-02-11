#-------------------------------------------------
#
# Project created by QtCreator 2015-02-10T14:15:22
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = VirtualTree
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    virtualtreemodel/virtualtreemodel.cpp \
    virtualtreemodel/virtualtreeadapter.cpp

HEADERS  += mainwindow.h \
    virtualtreemodel/virtualtreemodel.h \
    virtualtreemodel/virtualtreeadapter.h

FORMS    += mainwindow.ui
