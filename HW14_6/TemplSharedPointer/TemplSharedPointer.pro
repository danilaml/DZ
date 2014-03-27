QT += testlib
TEMPLATE = app
CONFIG += console
CONFIG += c++11
CONFIG -= app_bundle

SOURCES += main.cpp \
    myshareptrtest.cpp

HEADERS += \
    mysharedpointer.h \
    myshareptrtest.h

