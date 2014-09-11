QT += testlib
TEMPLATE = app
CONFIG += console
CONFIG += c++11
CONFIG -= app_bundle

SOURCES += main.cpp \
    myarraystack.cpp \
    mylinkedstack.cpp \
    stacktest.cpp

HEADERS += \
    mystack.h \
    myarraystack.h \
    mylinkedstack.h \
    stacktest.h

