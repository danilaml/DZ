TEMPLATE = app
CONFIG += console
CONFIG += c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    num.cpp \
    mult.cpp \
    div.cpp \
    sum.cpp \
    sub.cpp \
    parser.cpp

HEADERS += \
    node.h \
    num.h \
    mult.h \
    div.h \
    sum.h \
    sub.h \
    parser.h

