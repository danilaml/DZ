#ifndef COUNTZEROESTEST_H
#define COUNTZEROESTEST_H

#include <QObject>
#include <QtTest/QTest>
#include "countzeroes.h"

class CountZeroesTest : public QObject
{
	Q_OBJECT
public:
	explicit CountZeroesTest(QObject *parent = 0);

private slots:
	void intVecTest()
	{
		QVector<int> vec = {1, 2, 0, 3, 5, 0, -1, 0};
		QVERIFY(CountZeroes::count<int>(vec) == 3);
	}

	void doubleVecTest()
	{
		QVector<double> vec = {1.4, 2.1, 0.1, 0.0, 5.5, 0};
		QVERIFY(CountZeroes::count<double>(vec) == 2);
	}
};

#endif // COUNTZEROESTEST_H
