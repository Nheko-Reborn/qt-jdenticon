#include "svgpath.h"

namespace rendering {

SvgPath::SvgPath() {}

void
SvgPath::addCircle(QPointF &location, qreal diameter, bool counterClockwise)
{
    auto sweepFlag      = counterClockwise ? '0' : '1';
    auto radius         = diameter / 2;
    auto radiusAsString = QString::number(radius);

    dataString_.append("M" + QString::number(location.x()) + " " +
                       QString::number(location.y() + radius) + "a" + radiusAsString + "," +
                       radiusAsString + " 0 1," + sweepFlag + " " + QString::number(diameter) +
                       ",0" + "a" + radiusAsString + "," + radiusAsString + " 0 1," + sweepFlag +
                       " " + QString::number(-diameter) + ",0");
}

void
SvgPath::addPolygon(QList<QPointF> &points)
{
    dataString_.append("M" + QString::number(points.at(0).x()) + " " +
                       QString::number(points.at(0).y()));

    for (int i = 1; i < points.size(); i++) {
        dataString_.append("L" + QString::number(points.at(i).x()) + " " +
                           QString::number(points.at(i).y()));
    }

    dataString_.append("Z");
}

QString
SvgPath::toString() const
{
    return QStringList(dataString_).join("");
}

} // namespace rendering
