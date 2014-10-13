#include "robotfield.h"
#include <QDebug>

RobotField::RobotField(QVector<QVector<bool> > &f, QVector<bool> &r) : field(f), robots(r), robotNum(r.count(true))
{
	robotNum = 0;
	for (auto const &el : f)
	{
		robotNum += el.count(true);
	}
}

bool RobotField::isSelfDestructible() const
{
	if (robots.size() < 2)
		return false;
	QVector<bool> good(robots.size(), false);
	searchForGood(robots.indexOf(true), good);
	int g = 0;
	int b = 0;
	for (int i = 0; i < robots.size(); i++)
	{
		if (robots[i])
		{
			good[i] ? g++ : b++;
		}
	}
	return (g != 1 && b != 1);
}

void RobotField::searchForGood(int start, QVector<bool> &good) const
{
	good[start] = true;
	for (int i = 0; i < field[start].size(); i++)
	{
		if (field[start][i] && !good[i])
		{
			for (int k = 0; k < field[i].size(); k++)
			{
				if (field[i][k] && !good[k])
				{
					searchForGood(k, good);
				}
			}
		}
	}
}
