#include "disk_scheduling.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	disk_scheduling w;
    
	w.setFixedSize(680, 485);
	w.show();
	return a.exec();
}
