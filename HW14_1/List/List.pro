QT += testlib
TEMPLATE = app
CONFIG += console
CONFIG += c++11
CONFIG -= app_bundle

SOURCES += main.cpp \
    mylinkedlist.cpp \
    mydoublelinkedlist.cpp \
    listtest.cpp

HEADERS += \
    mylinkedlist.h \
    mylist.h \
    mydoublelinkedlist.h \
    listtest.h

