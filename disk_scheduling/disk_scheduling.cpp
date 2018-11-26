#include "disk_scheduling.h"

disk_scheduling::disk_scheduling(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	ui.lineEdit->setValidator(new QIntValidator(1, 999, ui.lineEdit));
	ui.lineEdit_2->setValidator(new QIntValidator(1, 999, ui.lineEdit));

	ui.tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
	ui.tableWidget->setColumnCount(2);
	headers << QStringLiteral("访问磁道号") << QStringLiteral("移动距离");
	ui.tableWidget->setHorizontalHeaderLabels(headers);
	ui.tableWidget_2->setColumnCount(1);
	head << QStringLiteral("磁道号");
	ui.tableWidget_2->setHorizontalHeaderLabels(head);
	ui.tableWidget->setColumnWidth(0, 90);
	ui.tableWidget->setColumnWidth(1, 70);
	ui.tableWidget_2->setColumnWidth(0, 80);

	connect(ui.pushButton_5, SIGNAL(clicked()), this, SLOT(addid()));
	connect(ui.pushButton_8, SIGNAL(clicked()), this, SLOT(setbegin()));
	connect(ui.pushButton, SIGNAL(clicked()), this, SLOT(FCFS()));
	connect(ui.pushButton_2, SIGNAL(clicked()), this, SLOT(SSTF()));
	connect(ui.pushButton_3, SIGNAL(clicked()), this, SLOT(SCAN()));
	connect(ui.pushButton_4, SIGNAL(clicked()), this, SLOT(CSCAN()));
	connect(ui.radioButton, SIGNAL(clicked()), this, SLOT(direction_set()));
	connect(ui.radioButton_2, SIGNAL(clicked()), this, SLOT(direction_set()));
	connect(ui.pushButton_6, SIGNAL(clicked()), this, SLOT(getnum()));
	connect(ui.pushButton_7, SIGNAL(clicked()), this, SLOT(clearall()));

}

disk_scheduling::~disk_scheduling()
{

}

void disk_scheduling::addid() {
	QString id = ui.lineEdit->text();
	if (0 == id.isEmpty()) {
		int Row = ui.tableWidget_2->rowCount();
		ui.tableWidget_2->insertRow(Row);
		QTableWidgetItem *item = new QTableWidgetItem(id);
		ui.tableWidget_2->setItem(Row, 0, item);
		list << id.toInt();
		ui.lineEdit->clear();
	}
}

void disk_scheduling::setbegin()
{
	QString sbegin = ui.lineEdit_2->text();
	if (0 == sbegin.isEmpty())
		begin = sbegin.toInt();
	ui.label_9->setText(sbegin);
}

void disk_scheduling::direction_set()
{
	QString get = this->sender()->objectName();
	if ("radioButton" == get) {
		direction = inside_to_out;
		ui.label_10->setText(QStringLiteral("从里到外"));
	}
	else if ("radioButton_2" == get) {
		direction = out_to_inside;
		ui.label_10->setText(QStringLiteral("从外到里"));
	}
}

void disk_scheduling::FCFS()
{
	if (0 != begin) {
		ui.tableWidget->setRowCount(0);
		int disk = begin;
		for (int i = 0; i < list.count(); ++i) {
			int Row = ui.tableWidget->rowCount();
			ui.tableWidget->insertRow(Row);
			QTableWidgetItem *item = new QTableWidgetItem(QString::number(list.at(i)));
			item->setTextAlignment(Qt::AlignCenter);
			ui.tableWidget->setItem(i, 0, item);
			int distance = qAbs(list.at(i) - disk);
			distance_sum += distance;
			disk = list.at(i);
			ui.tableWidget->setItem(i, 1, new QTableWidgetItem(QString::number(distance)));
		}
		ui.label_7->setText(QString::number(distance_sum / list.count()));
		distance_sum = 0;
	}
}

void disk_scheduling::SSTF()
{
	if (0 != begin) {
		ui.tableWidget->setRowCount(0);
		slist = list;
		int disk = begin, left = 0, right = 0;
		qSort(slist.begin(), slist.end());
		for (int i = 0; i < slist.count(); i++) {
			if (slist.at(i) > begin) {
				right = i;
				left = i - 1;
				break;
			}
			else {
				left = slist.count() - 1;
				right = slist.count();
			}
		}
		for (int i = 0; i < slist.count(); i++) {
			int Row = ui.tableWidget->rowCount();
			ui.tableWidget->insertRow(Row);
			if (right >= slist.count() ||
				(left >= 0 && qAbs(disk - slist.at(left) < qAbs(disk - slist.at(right)))))
			{
				QTableWidgetItem *item = new QTableWidgetItem(QString::number(slist.at(left)));
				item->setTextAlignment(Qt::AlignCenter);
				ui.tableWidget->setItem(i, 0, item);
				int dmin = qAbs(disk - slist.at(left));
				ui.tableWidget->setItem(i, 1, new QTableWidgetItem(QString::number(dmin)));
				distance_sum += dmin;
				disk = slist.at(left);
				left--;
			}
			else {
				QTableWidgetItem *item = new QTableWidgetItem(QString::number(slist.at(right)));
				item->setTextAlignment(Qt::AlignCenter);
				ui.tableWidget->setItem(i, 0, item);
				int dmin = qAbs(disk - slist.at(right));
				ui.tableWidget->setItem(i, 1, new QTableWidgetItem(QString::number(dmin)));
				distance_sum += dmin;
				disk = slist.at(right);
				right++;
			}
		}
		ui.label_7->setText(QString::number(distance_sum / list.count()));
		distance_sum = 0;
	}
}
//第二种算法
/*slist = list;
if (0 != begin) {
for (int i = 0; i < list.count(); ++i) {
int dmin = qAbs(disk - slist.at(0)), min = 0;//最短寻道距离  最短寻道号下标
for(int j = 0; j < slist.count() - 1; j++)
{
if(dmin > qAbs(disk - slist.at(j + 1))){
dmin = qAbs(disk - slist.at(j + 1));
min = j + 1;
}
}
int Row = ui.tableWidget->rowCount();
ui.tableWidget->insertRow(Row);
QTableWidgetItem *item = new QTableWidgetItem(QString::number(slist.at(min)));
item->setTextAlignment(Qt::AlignCenter);
ui.tableWidget->setItem(i, 0, item);
distance_sum += dmin;
disk = slist.at(min);
ui.tableWidget->setItem(i, 1, new QTableWidgetItem(QString::number(dmin)));
slist.removeAt(min);
}
ui.label_7->setText(QString::number(distance_sum / list.count()));
distance_sum = 0;
}*/

void disk_scheduling::SCAN()
{
	if (direction != Undefined && 0 != begin) {
		ui.tableWidget->setRowCount(0);
		slist = list;
		int disk = begin, left = 0, right = 0;
		qSort(slist.begin(), slist.end());
		for (int i = 0; i < slist.count(); i++) {
			if (slist.at(i) > begin) {
				right = i;
				left = i - 1;
				break;
			}
			else {
				left = slist.count() - 1;
				right = slist.count();
			}
		}
		if (direction == inside_to_out) {
			int row = 0;
			for (int i = right; i < slist.count(); i++, row++) {
				int Row = ui.tableWidget->rowCount();
				ui.tableWidget->insertRow(Row);
				QTableWidgetItem *item = new QTableWidgetItem(QString::number(slist.at(i)));
				item->setTextAlignment(Qt::AlignCenter);
				ui.tableWidget->setItem(row, 0, item);
				int dmin = qAbs(disk - slist.at(i));
				ui.tableWidget->setItem(row, 1, new QTableWidgetItem(QString::number(dmin)));
				distance_sum += dmin;
				disk = slist.at(i);
			}
			for (int i = left; i >= 0; i--, row++) {
				int Row = ui.tableWidget->rowCount();
				ui.tableWidget->insertRow(Row);
				QTableWidgetItem *item = new QTableWidgetItem(QString::number(slist.at(i)));
				item->setTextAlignment(Qt::AlignCenter);
				ui.tableWidget->setItem(row, 0, item);
				int dmin = qAbs(disk - slist.at(i));
				ui.tableWidget->setItem(row, 1, new QTableWidgetItem(QString::number(dmin)));
				distance_sum += dmin;
				disk = slist.at(i);
			}
			ui.label_7->setText(QString::number(distance_sum / list.count()));
			distance_sum = 0;
		}
		else {
			int row = 0;
			for (int i = left; i >= 0; i--, row++) {
				int Row = ui.tableWidget->rowCount();
				ui.tableWidget->insertRow(Row);
				QTableWidgetItem *item = new QTableWidgetItem(QString::number(slist.at(i)));
				item->setTextAlignment(Qt::AlignCenter);
				ui.tableWidget->setItem(row, 0, item);
				int dmin = qAbs(disk - slist.at(i));
				ui.tableWidget->setItem(row, 1, new QTableWidgetItem(QString::number(dmin)));
				distance_sum += dmin;
				disk = slist.at(i);
			}
			for (int i = right; i < slist.count(); i++, row++) {
				int Row = ui.tableWidget->rowCount();
				ui.tableWidget->insertRow(Row);
				QTableWidgetItem *item = new QTableWidgetItem(QString::number(slist.at(i)));
				item->setTextAlignment(Qt::AlignCenter);
				ui.tableWidget->setItem(row, 0, item);
				int dmin = qAbs(disk - slist.at(i));
				ui.tableWidget->setItem(row, 1, new QTableWidgetItem(QString::number(dmin)));
				distance_sum += dmin;
				disk = slist.at(i);
			}
			ui.label_7->setText(QString::number(distance_sum / list.count()));
			distance_sum = 0;
		}
	}
}

void disk_scheduling::CSCAN()
{
	if (direction != Undefined && 0 != begin) {
		if (direction != Undefined) {
			ui.tableWidget->setRowCount(0);
			slist = list;
			int disk = begin, left = 0, right = 0;
			qSort(slist.begin(), slist.end());
			for (int i = 0; i < slist.count(); i++) {
				if (slist.at(i) > begin) {
					right = i;
					left = i - 1;
					break;
				}
				else {
					left = slist.count() - 1;
					right = slist.count();
				}
			}
			if (direction == inside_to_out) {
				int row = 0;
				for (int i = right; i < slist.count(); i++, row++) {
					int Row = ui.tableWidget->rowCount();
					ui.tableWidget->insertRow(Row);
					QTableWidgetItem *item = new QTableWidgetItem(QString::number(slist.at(i)));
					item->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(row, 0, item);
					int dmin = qAbs(disk - slist.at(i));
					ui.tableWidget->setItem(row, 1, new QTableWidgetItem(QString::number(dmin)));
					distance_sum += dmin;
					disk = slist.at(i);
				}
				for (int i = 0; i <= left; i++, row++) {
					int Row = ui.tableWidget->rowCount();
					ui.tableWidget->insertRow(Row);
					QTableWidgetItem *item = new QTableWidgetItem(QString::number(slist.at(i)));
					item->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(row, 0, item);
					int dmin = qAbs(disk - slist.at(i));
					ui.tableWidget->setItem(row, 1, new QTableWidgetItem(QString::number(dmin)));
					distance_sum += dmin;
					disk = slist.at(i);
				}
				ui.label_7->setText(QString::number(distance_sum / list.count()));
				distance_sum = 0;
			}
			else {
				int row = 0;
				for (int i = left; i >= 0; i--, row++) {
					int Row = ui.tableWidget->rowCount();
					ui.tableWidget->insertRow(Row);
					QTableWidgetItem *item = new QTableWidgetItem(QString::number(slist.at(i)));
					item->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(row, 0, item);
					int dmin = qAbs(disk - slist.at(i));
					ui.tableWidget->setItem(row, 1, new QTableWidgetItem(QString::number(dmin)));
					distance_sum += dmin;
					disk = slist.at(i);
				}
				for (int i = slist.count() - 1; i >= right; i--, row++) {
					int Row = ui.tableWidget->rowCount();
					ui.tableWidget->insertRow(Row);
					QTableWidgetItem *item = new QTableWidgetItem(QString::number(slist.at(i)));
					item->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(row, 0, item);
					int dmin = qAbs(disk - slist.at(i));
					ui.tableWidget->setItem(row, 1, new QTableWidgetItem(QString::number(dmin)));
					distance_sum += dmin;
					disk = slist.at(i);
				}
				ui.label_7->setText(QString::number(distance_sum / list.count()));
				distance_sum = 0;
			}
		}
	}
}

void disk_scheduling::getnum()
{
	qsrand((quint32)time(0));
	for (int i = 0; i < 10; i++)
	{
		int randnum = qrand() % 100;
		if (randnum != 0) {
			int Row = ui.tableWidget_2->rowCount();
			ui.tableWidget_2->insertRow(Row);
			QTableWidgetItem *item = new QTableWidgetItem(QString::number(randnum));
			ui.tableWidget_2->setItem(Row, 0, item);
			list << randnum;
		}
	}
}

void disk_scheduling::clearall()
{
	ui.tableWidget_2->setRowCount(0);
	list.clear();
}

