#ifndef ROBOTFIELDTEST_H
#define ROBOTFIELDTEST_H

#include <QObject>
#include <QtTest/QtTest>
#include "robotfield.h"

class RobotFieldTest : public QObject
{
	Q_OBJECT
public:
	explicit RobotFieldTest(QObject *parent = 0);

private slots:
	void simpleTestTrue()
	{
		QVector<QVector<bool> > field = {{false, true, false, false},
		                                {true, false, true, false},
		                                {false, true, false, true},
		                                {false, false, true, false}};
		QVector<bool> robots = {true, false, true, false};

		RobotField rf(field, robots);
		QVERIFY(rf.isSelfDestructible());
	}

	void simpleTestFalse()
	{
		QVector<QVector<bool> > field = {{false, true, false, false},
		                                {true, false, true, false},
		                                {false, true, false, true},
		                                {false, false, true, false}};
		QVector<bool> robots = {true, false, false, true};

		RobotField rf(field, robots);
		QVERIFY(!rf.isSelfDestructible());
	}

	void complexTestTrue()
	{
		QVector<QVector<bool> > field = {{false, true, false, false, false},
		                                {true, false, true, false, false},
		                                {false, true, false, true, true},
		                                {false, false, true, false, false},
		                                {false, false, true, false, false}};
		QVector<bool> robots = {false, true, false, true, true};

		RobotField rf(field, robots);
		QVERIFY(rf.isSelfDestructible());
	}

	void complexTestFalse()
	{
		QVector<QVector<bool> > field = {{false, true, false, false, false},
		                                {true, false, true, false, false},
		                                {false, true, false, true, true},
		                                {false, false, true, false, false},
		                                {false, false, true, false, false}};
		QVector<bool> robots = {true, false, false, true, true};

		RobotField rf(field, robots);
		QVERIFY(!rf.isSelfDestructible());
	}

};

#endif // ROBOTFIELDTEST_H
