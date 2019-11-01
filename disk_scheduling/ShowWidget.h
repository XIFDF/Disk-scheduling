#pragma once
#include <QWidget.h>
#include <QSequentialAnimationGroup>
#include <QPropertyAnimation>
#include <QParallelAnimationGroup>
#include <QLabel>
#include <QList>
#include <QPushButton>
#include "DiskBaseLabel.h"
#include "ArrowLabel.h"

class disk_scheduling;

class ShowWidget :
    public QWidget
{
    Q_OBJECT

public:
    ShowWidget(disk_scheduling *parent = nullptr);
    ~ShowWidget();

private:
    
    disk_scheduling *mainWidget = nullptr;
    QLabel *diskBaseLabel = nullptr;
    QLabel *arrow = nullptr;
    //����Qt���Ե��� 
    QPropertyAnimation *arrowAnimation = nullptr;
    //���ж�������
    QSequentialAnimationGroup *posGroup = nullptr;
    std::vector<int> pointsList;

    void getPointsList();
    void addStep();
private slots:
    void simulate();
};

