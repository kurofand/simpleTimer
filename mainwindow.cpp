#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);
	main=ui->vlParent;
}

void MainWindow::on_pbAdd_clicked()
{
	timer=new timerClient();
	timerDialog=new TimerCreateDialog();
//	timerDialog->show();
	if(timerDialog->exec())
	{
		QTime time=timerDialog->returnTime();
		timer->setUpTimer(main, timerDialog->returnLabel(), time.hour(), time.minute());
	}
}

MainWindow::~MainWindow()
{
	delete ui;
}
