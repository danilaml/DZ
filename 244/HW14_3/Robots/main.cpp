#include "robotfield.h"
#include <iostream>

int main()
{
	QVector<QVector<bool> > field = {{false, true, false, false},
	                                {true, false, true, false},
	                                {false, true, false, true},
	                                {false, false, true, false}};
	QVector<bool> robots = {true, false, true, false};

	RobotField rf(field, robots);
	std::cout << rf.isSelfDestructible() << std::endl;

	return 0;
}
