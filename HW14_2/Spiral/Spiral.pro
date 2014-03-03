TEMPLATE = app
CONFIG += console
CONFIG += c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    dispconsole.cpp \
    dispfile.cpp \
    dispstream.cpp

HEADERS += \
    displayer.h \
    dispconsole.h \
    dispfile.h \
    dispstream.h

