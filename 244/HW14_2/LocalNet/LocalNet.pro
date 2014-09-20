#-------------------------------------------------
#
# Project created by QtCreator 2014-09-18T22:54:39
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = LocalNet
TEMPLATE = app

CONFIG += c++11

SOURCES += main.cpp\
        mainwindow.cpp \
    genericpc.cpp

HEADERS  += mainwindow.h \
    genericpc.h

FORMS    += mainwindow.ui
