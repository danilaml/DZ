QT += testlib
TEMPLATE = app
CONFIG += console
CONFIG += c++11
CONFIG -= app_bundle

SOURCES += main.cpp \
    myuniquelist.cpp \
    myexception.cpp \
    uniquelisttest.cpp

HEADERS += \
    myuniquelist.h \
    myexception.h \
    uniquelisttest.h

