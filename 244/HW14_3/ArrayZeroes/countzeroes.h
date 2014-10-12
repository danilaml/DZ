#ifndef COUNTZEROES_H
#define COUNTZEROES_H

#include <QVector>

class CountZeroes
{
public:
	CountZeroes();
	template<typename T>
	static uint count(QVector<T> const vec);
};

template<typename T>
uint CountZeroes::count(QVector<T> const vec)
{
	uint c = 0;
	for (const T &elem : vec)
	{
		if (elem == 0)
			c++;
	}
	return c;
}

#endif // COUNTZEROES_H
