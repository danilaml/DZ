#ifndef ROBOTFIELD_H
#define ROBOTFIELD_H

#include <QVector>

class RobotField
{
public:
	RobotField(QVector<QVector<bool> > &f, QVector<bool> &r);
	bool isSelfDestructible() const;

private:
	void searchForGood(int start, QVector<bool> &good) const;

	QVector<QVector<bool> > field;
	QVector<bool> robots;
	int robotNum;

};

#endif // ROBOTFIELD_H
