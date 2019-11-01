#include "ShowWidget.h"
#include "disk_scheduling.h"
ShowWidget::ShowWidget(disk_scheduling *parent)
    : QWidget(0), mainWidget(parent)
{
    posGroup = new QSequentialAnimationGroup(this);
    posGroup->addPause(500);
    diskBaseLabel = new DiskBaseLabel(this);
    diskBaseLabel->setGeometry(QRect(0, 0, 600, 600));
    
    arrow = new ArrowLabel(this);
    arrow->setGeometry(QRect(240, 200, 120, 100));
    
    QPushButton *button = new QPushButton(this);
    button->setText(QStringLiteral("¿ªÊ¼ÑÝÊ¾"));
    button->setGeometry(QRect(480, 50, 80, 41));
    connect(button, SIGNAL(clicked()), this, SLOT(simulate()));
}


ShowWidget::~ShowWidget()
{

}


void ShowWidget::getPointsList()
{
    pointsList.clear();
    pointsList.push_back(0);
    QTableWidget *tableWidget = mainWidget->ui.tableWidget;
    unsigned int total_points = tableWidget->rowCount();
    for (unsigned int i = 0; i < total_points; i++)
    {
        pointsList.push_back(tableWidget->item(i, 0)->text().toInt());
    }
    pointsList.push_back(0);

}

void ShowWidget::addStep()
{
    unsigned int total = pointsList.size();
    for (int i = 1; i < total; i++)
    {
        QPropertyAnimation *arrowAnimation = new QPropertyAnimation(arrow, "pos");
        arrowAnimation->setEasingCurve(QEasingCurve::InOutQuad);
        arrowAnimation->setStartValue(QPoint(240 + pointsList.at(i-1) * 2, 200));
        arrowAnimation->setEndValue(QPoint(240 + pointsList.at(i) * 2, 200));
        arrowAnimation->setDuration(1000);
        posGroup->addAnimation(arrowAnimation);
    }
}

void ShowWidget::simulate()
{
    posGroup->clear();
    getPointsList();
    addStep();
    posGroup->start();
}


