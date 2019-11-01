#ifndef DISK_SCHEDULING_H
#define DISK_SCHEDULING_H

#include <QtWidgets/QMainWindow>
#include "ui_disk_scheduling.h"
#include "ShowWidget.h"
#include <ctime>

class disk_scheduling : public QMainWindow
{
    Q_OBJECT

    friend ShowWidget;
public:
	disk_scheduling(QWidget *parent = 0);
	~disk_scheduling();
	enum Direction {
		inside_to_out,
		out_to_inside,
		Undefined
	};
	Direction direction = Undefined;
	int begin = 0;
	double distance_sum = 0.0;
	QStringList headers, head;
	QList<int> list, slist;

private:
	Ui::disk_schedulingClass ui;
    QWidget * showWidget = nullptr;

	void InsertTableWidget(QTableWidget *tableWidget, const int &number);
	void InsertTableWidget(QTableWidget *tableWidget, QString &number);

private slots:
	void addid();
	void setbegin();
	void direction_set();
	void FCFS();
	void SSTF();
	void SCAN();
	void CSCAN();
	void getnum();
	void clearall();
    void showAnimationWidget();
};



#endif // DISK_SCHEDULING_H
