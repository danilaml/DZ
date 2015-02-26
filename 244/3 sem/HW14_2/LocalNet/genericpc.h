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
	/**
	 * @brief GenericPC construtor for GenericPC
	 * @param isInf true if infected
	 * @param vuln chance of getting infected in [0,1]
	 * @param id pc id
	 * @param os name of pc os
	 * @param rsd additional random seed (will be multiplied)
	 */
	GenericPC(bool isInf, double vuln, uint id, const QString os = "Generic", uint rsd = 1) :
		isInfected(isInf),
		vulnerability(vuln),
		id(id),
		os(os)
	{
		re.seed(std::chrono::system_clock::now().time_since_epoch().count() * (id + 1) * rsd);
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
	void infected(uint);

public slots:
	void throwDice();
	void infect();

private:
	QTimer *timer;
	std::default_random_engine re;

};

#endif // GENERICPC_H
