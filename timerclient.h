#ifndef TIMERCLIENT_H
#define TIMERCLIENT_H

#include <QObject>
#include <QTimer>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QLabel>

class timerClient: public QObject
{
	Q_OBJECT

public:
	timerClient(QObject *parent=nullptr);
	void setUpTimer(QLayout *layoutParent, QString label, quint8 h, quint8 m);
private:
	QWidget *widget;
	QTimer *timer;
	QVBoxLayout *lvMain;
	QHBoxLayout *lhButtons;
	QPushButton *pbStartStop, *pbDeleteTimer;
	QLabel *lTimerName, *lTimer;
	quint16 hours, mins, secs=0;
	quint32 totalSecs;

private slots:
	void on_pbStartStop_clicked();
	void on_pbDeleteTimer_clicked();
	void tick();

};

#endif // TIMERCLIENT_H
