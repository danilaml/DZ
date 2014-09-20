#ifndef GENERICPC_H
#define GENERICPC_H

#include <QObject>
#include <QTimer>
#include <QVector>
#include <random>
#include <chrono>

/**
 * @brief The GenericPC class represents abstract PC in the net
 */
class GenericPC : public QObject
{
	Q_OBJECT
public:
	explicit GenericPC(QObject *parent = 0);
	GenericPC(bool isInf, double vuln, uint id, const QString os = "Generic") :
		isInfected(isInf),
		vulnerability(vuln),
		id(id),
		os(os)
	{
		re.seed(std::chrono::system_clock::now().time_since_epoch().count() * (id + 1));
	}
	~GenericPC();

	/**
	 * @brief setTimer - sets pointer to a timer
	 * @param tm pointer to a timer
	 */
	void setTimer(QTimer *tm);

	bool isInfected;
	double vulnerability;
	uint id;
	QString const os;

signals:
	void infected(int);

public slots:
	void throwDice();
	void infect();

private:
	QTimer *timer;
	std::default_random_engine re;

};

#endif // GENERICPC_H
