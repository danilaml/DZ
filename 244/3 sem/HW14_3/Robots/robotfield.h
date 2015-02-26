#ifndef ROBOTFIELD_H
#define ROBOTFIELD_H

#include <QVector>

/**
 * @brief The RobotField class by graph and robots list can say whether it's possible for all robots to self-destruct
 */
class RobotField
{
public:
	/**
	 * @brief RobotField main constructor for RobotField class
	 * @param f adjacency matrix for graph
	 * @param r list of robots or rather their places in graph vertices
	 */
	RobotField(QVector<QVector<bool> > &f, QVector<bool> &r);
	/**
	 * @brief isSelfDestructible calculates if it is possible for all robots to self-destruct
	 * @return true if it is, flase if it isn't
	 */
	bool isSelfDestructible() const;

private:
	void searchForGood(int start, QVector<bool> &good) const;

	QVector<QVector<bool> > field;
	QVector<bool> robots;

};

#endif // ROBOTFIELD_H
