QT += testlib
TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle

SOURCES += main.cpp \
    comparatortest.cpp

HEADERS += \
    abstractcomparator.h \
    bubblesort.h \
    standardcomparator.h \
    comparatortest.h \
    reversecomparator.h

