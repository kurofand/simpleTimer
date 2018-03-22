#ifndef TIMERCREATEDIALOG_H
#define TIMERCREATEDIALOG_H

#include <QDialog>

namespace Ui {
class TimerCreateDialog;
}

class TimerCreateDialog : public QDialog
{
	Q_OBJECT

public:
	explicit TimerCreateDialog(QWidget *parent = 0);
	QString returnLabel();
	QTime returnTime();
	~TimerCreateDialog();

private:
	Ui::TimerCreateDialog *ui;
};

#endif // TIMERCREATEDIALOG_H
