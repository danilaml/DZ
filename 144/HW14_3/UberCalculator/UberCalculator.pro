#-------------------------------------------------
#
# Project created by QtCreator 2014-03-06T17:40:34
#
#-------------------------------------------------

QT       += core gui
QT       += testlib

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = UberCalculator
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    exprcalculator.cpp \
    exprcalculatortest.cpp

HEADERS  += mainwindow.h \
    exprcalculator.h \
    exprcalculatortest.h

FORMS    += mainwindow.ui
