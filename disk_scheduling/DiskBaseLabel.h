#pragma once
#include <QLabel>
#include <QPainter>
#include <QPoint>
#include <QSequentialAnimationGroup>
#include <QPropertyAnimation>
#include <QParallelAnimationGroup>

class DiskBaseLabel :
    public QLabel
{
    Q_OBJECT

public:
    DiskBaseLabel(QWidget *parent = 0);
    ~DiskBaseLabel();

protected:
    void paintEvent(QPaintEvent * event);
};

