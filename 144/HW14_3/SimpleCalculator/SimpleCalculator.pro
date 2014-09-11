#-------------------------------------------------
#
# Project created by QtCreator 2014-03-06T12:12:27
#
#-------------------------------------------------

QT       += core gui
QT       += testlib

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SimpleCalculator
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    result.cpp \
    resulttest.cpp

HEADERS  += mainwindow.h \
    result.h \
    resulttest.h

FORMS    += mainwindow.ui
