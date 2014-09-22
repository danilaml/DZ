#include "genericpc.h"

GenericPC::GenericPC(QObject *parent) :
	QObject(parent)
{
}

GenericPC::~GenericPC()
{
}

void GenericPC::setTimer(QTimer *tm)
{
	timer = tm;
}


void GenericPC::throwDice()
{
	if (std::generate_canonical<double, 10>(re) < vulnerability) // buggy in mvsc, mingw works fine
	{
		isInfected = true;
		connect(timer, SIGNAL(timeout()), this, SLOT(infect()));
		disconnect(timer, SIGNAL(timeout()), this, SLOT(throwDice()));
	}
}

void GenericPC::infect()
{
	emit infected(id);
}
