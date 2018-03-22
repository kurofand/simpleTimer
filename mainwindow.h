#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVBoxLayout>
#include <QInputDialog>
#include <QTime>
#include "timerclient.h"
#include "timercreatedialog.h"

namespace Ui {
class MainWindow;
}

class timerClient;
class TimerCreateDialog;

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	explicit MainWindow(QWidget *parent = 0);
	~MainWindow();

private:
	Ui::MainWindow *ui;
	timerClient *timer;
	TimerCreateDialog *timerDialog;
	QVBoxLayout *main;

private slots:
	void on_pbAdd_clicked();
};

#endif // MAINWINDOW_H
