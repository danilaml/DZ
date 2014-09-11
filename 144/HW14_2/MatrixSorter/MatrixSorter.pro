QT += testlib
TEMPLATE = app
CONFIG += console
CONFIG += c++11
CONFIG -= app_bundle

SOURCES += main.cpp \
    matrixquicksort.cpp \
    matrixsorttest.cpp

HEADERS += \
    matrixquicksort.h \
    matrixsorttest.h

