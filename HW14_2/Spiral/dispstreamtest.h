#ifndef DISPSTREAMTEST_H
#define DISPSTREAMTEST_H

#include <QObject>
#include <QtTest/QtTest>
#include <sstream>
#include "dispstream.h"

class DispStreamTest : public QObject
{
    Q_OBJECT
public:
    explicit DispStreamTest(QObject *parent = 0);

private slots:
    void initTestCase()
    {
        dsp = new DispStream();
    }

    void testOutput()
    {
        int** ar = new int*[3];
        ar[0] = new int[3] {1, 2, 3};
        ar[1] = new int[3] {4, 5, 6};
        ar[2] = new int[3] {7, 8, 9};
        std::stringstream ss;
        dsp->displayStream(ar, 3, ss);
        std::string result = ss.str();
        QCOMPARE(result, std::string("5 : 8 : 9 : 6 : 3 : 2 : 1 : 4 : 7"));

        for (int i = 0; i < 3; i++)
            delete[] ar[i];
        delete[] ar;
    }

    void cleanupTestCase()
    {
        delete dsp;
    }

private:
    DispStream *dsp;
};

#endif // DISPSTREAMTEST_H
