#include "DiskBaseLabel.h"


DiskBaseLabel::DiskBaseLabel(QWidget *parent)
    :QLabel(parent)
{
}


DiskBaseLabel::~DiskBaseLabel()
{
}

void DiskBaseLabel::paintEvent(QPaintEvent * event)
{
    Q_UNUSED(event);

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.setRenderHint(QPainter::SmoothPixmapTransform, true);

    QPen pen(Qt::red, 4, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin);
    painter.setPen(pen);
    painter.drawEllipse(20, 20, 500, 500);

    QPen pen2(Qt::blue, 1, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin);
    painter.setPen(pen2);
    for (int i = 11, j = 20; i > 0; i--, j += 20)
    {
        painter.drawEllipse(20 + j, 20 + j, 500 - 2 * j, 500 - 2 * j);
    }

    QFont font("Microsoft YaHei", 8, 2, true);
    painter.setFont(font);
    for (int i = 12, j = 20, max = 110; i > 0; i--, j += 20, max -= 10)
    {
        painter.drawText(j, 270, QString::number(max));
    }
}
