QT += testlib
TEMPLATE = app
CONFIG += console
CONFIG += c++11
CONFIG -= app_bundle

SOURCES += main.cpp \
    bubblesort.cpp \
    quicksort.cpp \
    sortertest.cpp

HEADERS += \
    sorter.h \
    bubblesort.h \
    quicksort.h \
    sortertest.h

