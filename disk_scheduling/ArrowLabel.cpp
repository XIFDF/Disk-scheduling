#include "ArrowLabel.h"



ArrowLabel::ArrowLabel(QWidget *parent)
    :QLabel(parent)
{
}


ArrowLabel::~ArrowLabel()
{
}

void ArrowLabel::paintEvent(QPaintEvent * event)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.setRenderHint(QPainter::SmoothPixmapTransform, true);
    QPen pen(Qt::blue, 2, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin);
    painter.setPen(pen);
    QPolygon pts;
    pts.setPoints(8, 20, 0,   20, 50,   0, 50,   30, 70,   60, 50,   40, 50,   40, 0,   20, 0);
    //painter.drawConvexPolygon(pts);

    QPainterPath path;
    path.addPolygon(pts);//添加一个圆

    QBrush brush(Qt::blue, Qt::SolidPattern);
    painter.setBrush(brush);
    path.setFillRule(Qt::WindingFill); //填充规则
    painter.drawPath(path);
}
