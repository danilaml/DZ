#ifndef LOCALNETTEST_H
#define LOCALNETTEST_H

#include <QObject>
#include <QtTest/QtTest>
#include <QtTest/QSignalSpy>
#include "genericpc.h"

class LocalNetTest : public QObject
{
	Q_OBJECT
public:
	explicit LocalNetTest(QObject *parent = 0);

public slots:

	void helper(int id)
	{
		if (!infected[id])
		{
			infected[id] = true;
		}
		for (uint i = 0; i < number; i++)
		{
			if (!pcs[i]->isInfected && netTop.at(id).at(i))
				connect(timer, SIGNAL(timeout()), pcs[i], SLOT(throwDice()));
		}
	}

private slots:

	void testNetFive()
	{
		number = 5;
		pcs = QVector<GenericPC*>(number);

		pcs[0] = new GenericPC(true, 0.75, 0, "Windows", 0);
		pcs[1] = new GenericPC(false, 0.25, 1, "Linux", 0);
		pcs[2] = new GenericPC(false, 0.75, 2, "Windows", 0);
		pcs[3] = new GenericPC(false, 0.25, 3, "Linux", 0);
		pcs[4] = new GenericPC(false, 0.35, 4, "OSX", 0);

		netTop = QVector< QVector<bool> >(number, QVector<bool>(number, false));
		firstInf = QVector<bool>(number, false);
		infected = QVector<bool>(number, false);

		netTop[0][1] = true;
		netTop[1][2] = true;
		netTop[2][3] = true;
		netTop[3][4] = true;
		netTop[1][4] = true;

		timer = new QTimer(this);
		timer->stop();

		 QSignalMapper *signalMapper = new QSignalMapper(this);

		for (GenericPC* p : pcs)
		{
			p->setTimer(timer);
			if (p->isInfected)
			{
				firstInf[p->id] = true;
				connect(timer, SIGNAL(timeout()), p, SLOT(infect()));
			}
			connect(p, SIGNAL(infected(uint)), signalMapper, SLOT(map()));
			signalMapper->setMapping(p, p->id);
		}

		connect(signalMapper, SIGNAL(mapped(int)), this, SLOT(helper(int)));
		QSignalSpy spy(signalMapper, SIGNAL(mapped(int)));

		timer->start(1);

		while ((uint)spy.length() < number)
		{
			QTest::qWait(1);
		}

		QVERIFY((uint)spy.length() == number);

		uint expected[] = {0, 1, 2, 4, 3};

		for (uint i = 0; i < number; i++)
		{
			QCOMPARE(spy.at(i).at(0).toUInt(), expected[i]);
		}

		timer->stop();
	}

private:

	QTimer *timer;
	QVector<GenericPC*> pcs;
	QVector< QVector<bool> > netTop;
	QVector<bool> firstInf;
	QVector<bool> infected;
	uint number;

};

#endif // LOCALNETTEST_H
