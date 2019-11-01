#pragma once
#include <QLabel>
#include <QPainter>
#include <QPoint>
#include <QSequentialAnimationGroup>
#include <QPropertyAnimation>
#include <QParallelAnimationGroup>
class ArrowLabel :
    public QLabel
{
    Q_OBJECT

public:
    ArrowLabel(QWidget *parent = 0);
    ~ArrowLabel();

protected:
    void paintEvent(QPaintEvent * event);
};

