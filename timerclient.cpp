#include "timerclient.h"

timerClient::timerClient(QObject *parent):QObject(parent)
{

}

void timerClient::setUpTimer(QLayout *layoutParent, QString label, quint8 h, quint8 m)
{
	widget=new QWidget();
	lvMain=new QVBoxLayout(widget);
	lTimerName=new QLabel(label);
	lvMain->addWidget(lTimerName);
	hours=h;
	mins=m;
	lTimer=new QLabel(QString::number(h)+":"+QString::number(m)+":00");
	lvMain->addWidget(lTimer);
	pbStartStop=new QPushButton();
	pbStartStop->setText("Start timer");
	pbDeleteTimer=new QPushButton();
	pbDeleteTimer->setText("Delete timer");
	connect(pbStartStop, SIGNAL(clicked(bool)), this, SLOT(on_pbStartStop_clicked()));
	connect(pbDeleteTimer, SIGNAL(clicked(bool)), this, SLOT(on_pbDeleteTimer_clicked()));
	lhButtons=new QHBoxLayout();
	lhButtons->addWidget(pbStartStop);
	lhButtons->addWidget(pbDeleteTimer);
	lvMain->addLayout(lhButtons);
	timer=new QTimer();
	timer->setInterval(1000);
	connect(timer, SIGNAL(timeout()), this, SLOT(tick()));
	layoutParent->addWidget(widget);
	totalSecs=mins*60+hours*60*60;
}

void timerClient::on_pbStartStop_clicked()
{
	if(!timer->isActive())
	{
		pbStartStop->setText("Stop timer");
		timer->start();
	}
	else
	{
		pbStartStop->setText("Resume timer");
		timer->stop();
	}
}

void timerClient::tick()
{
	totalSecs--;
	if(totalSecs!=0)
	{
		hours=totalSecs/3600;
		mins=(totalSecs-hours*3600)/60;
		secs=totalSecs-hours*3600-mins*60;
		lTimer->setText(QString::number(hours)+":"+QString::number(mins)+":"+QString::number(secs));
	}
	else
	{
		timer->stop();
		lTimer->setText("Time is over!");
	}
}

void timerClient::on_pbDeleteTimer_clicked()
{
	delete(widget);
	this->deleteLater();
}

