#-------------------------------------------------
#
# Project created by QtCreator 2014-04-16T23:52:04
#
#-------------------------------------------------

QT       += core gui
CONFIG += c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TicTacToe
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    tictactoe.cpp \
    sizedialog.cpp

HEADERS  += mainwindow.h \
    tictactoe.h \
    sizedialog.h

FORMS    += mainwindow.ui \
    tictactoe.ui \
    sizedialog.ui
