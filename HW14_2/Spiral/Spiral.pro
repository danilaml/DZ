QT += testlib
TEMPLATE = app
CONFIG += console
CONFIG += c++11
CONFIG -= app_bundle

SOURCES += main.cpp \
    dispconsole.cpp \
    dispfile.cpp \
    dispstream.cpp \
    dispstreamtest.cpp

HEADERS += \
    displayer.h \
    dispconsole.h \
    dispfile.h \
    dispstream.h \
    dispstreamtest.h

