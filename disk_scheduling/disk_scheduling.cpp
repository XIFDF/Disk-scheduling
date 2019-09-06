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
		InsertTableWidget(ui.tableWidget_2, id);
		list << id.toInt();
		ui.lineEdit->clear();
	}
}

void disk_scheduling::InsertTableWidget(QTableWidget * tableWidget, const int &number)
{
	int Row = tableWidget->rowCount();
	tableWidget->insertRow(Row);
	QTableWidgetItem *item = new QTableWidgetItem(QString::number(number));
	item->setTextAlignment(Qt::AlignCenter);
	tableWidget->setItem(Row, 0, item);
}

void disk_scheduling::InsertTableWidget(QTableWidget * tableWidget, QString &number)
{
	int Row = tableWidget->rowCount();
	tableWidget->insertRow(Row);
	QTableWidgetItem *item = new QTableWidgetItem(number);
	item->setTextAlignment(Qt::AlignCenter);
	tableWidget->setItem(Row, 0, item);
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
	setbegin();
	if (0 != begin) {
		ui.tableWidget->setRowCount(0);
		int disk = begin;
		for (int i = 0; i < list.count(); ++i) {
			InsertTableWidget(ui.tableWidget, list.at(i));
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
	setbegin();
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
			if (right >= slist.count() ||
				(left >= 0 && qAbs(disk - slist.at(left) < qAbs(disk - slist.at(right)))))
			{
				InsertTableWidget(ui.tableWidget, slist.at(left));
				int dmin = qAbs(disk - slist.at(left));
				ui.tableWidget->setItem(i, 1, new QTableWidgetItem(QString::number(dmin)));
				distance_sum += dmin;
				disk = slist.at(left);
				left--;
			}
			else {
				InsertTableWidget(ui.tableWidget, slist.at(right));
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

void disk_scheduling::SCAN()
{
	setbegin();
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
				InsertTableWidget(ui.tableWidget, slist.at(i));
				int dmin = qAbs(disk - slist.at(i));
				ui.tableWidget->setItem(row, 1, new QTableWidgetItem(QString::number(dmin)));
				distance_sum += dmin;
				disk = slist.at(i);
			}
			for (int i = left; i >= 0; i--, row++) {
				InsertTableWidget(ui.tableWidget, slist.at(i));
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
				InsertTableWidget(ui.tableWidget, slist.at(i));
				int dmin = qAbs(disk - slist.at(i));
				ui.tableWidget->setItem(row, 1, new QTableWidgetItem(QString::number(dmin)));
				distance_sum += dmin;
				disk = slist.at(i);
			}
			for (int i = right; i < slist.count(); i++, row++) {
				InsertTableWidget(ui.tableWidget, slist.at(i));
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
	setbegin();
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
					InsertTableWidget(ui.tableWidget, slist.at(i));
					int dmin = qAbs(disk - slist.at(i));
					ui.tableWidget->setItem(row, 1, new QTableWidgetItem(QString::number(dmin)));
					distance_sum += dmin;
					disk = slist.at(i);
				}
				for (int i = 0; i <= left; i++, row++) {
					InsertTableWidget(ui.tableWidget, slist.at(i));
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
					InsertTableWidget(ui.tableWidget, slist.at(i));
					int dmin = qAbs(disk - slist.at(i));
					ui.tableWidget->setItem(row, 1, new QTableWidgetItem(QString::number(dmin)));
					distance_sum += dmin;
					disk = slist.at(i);
				}
				for (int i = slist.count() - 1; i >= right; i--, row++) {
					InsertTableWidget(ui.tableWidget, slist.at(i));
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
			InsertTableWidget(ui.tableWidget_2, randnum);
			list << randnum;
		}
	}
}

void disk_scheduling::clearall()
{
	ui.tableWidget_2->setRowCount(0);
	list.clear();
}

