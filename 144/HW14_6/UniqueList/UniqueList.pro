QT += testlib
TEMPLATE = app
CONFIG += console
CONFIG += c++11
CONFIG -= app_bundle

SOURCES += main.cpp \
    myuniquelist.cpp \
    myexception.cpp \
    uniquelisttest.cpp \
    myoutofrangeexception.cpp \
    mylinkedlist.cpp \
    myemptylistexception.cpp \
    myduplicateexception.cpp

HEADERS += \
    myuniquelist.h \
    myexception.h \
    uniquelisttest.h \
    myoutofrangeexception.h \
    mylinkedlist.h \
    mylist.h \
    myemptylistexception.h \
    myduplicateexception.h

