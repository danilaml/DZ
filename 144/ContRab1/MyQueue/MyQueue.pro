QT += testlib
TEMPLATE = app
CONFIG += console
CONFIG += c++11
CONFIG -= app_bundle

SOURCES += main.cpp \
    myemptyexception.cpp \
    myqueuetest.cpp

HEADERS += \
    myqueue.h \
    myemptyexception.h \
    myqueuetest.h

