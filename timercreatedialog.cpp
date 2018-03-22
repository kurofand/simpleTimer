#include "timercreatedialog.h"
#include "ui_timercreatedialog.h"

TimerCreateDialog::TimerCreateDialog(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::TimerCreateDialog)
{
	ui->setupUi(this);
}

QString TimerCreateDialog::returnLabel()
{
	return ui->eTimerLabel->text();
}
QTime TimerCreateDialog::returnTime()
{
	return ui->eTime->time();
}

TimerCreateDialog::~TimerCreateDialog()
{
	delete ui;
}
