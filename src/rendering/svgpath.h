#ifndef SVGPATH_H
#define SVGPATH_H

#include <QPointF>
#include <QString>
#include <QStringList>
#include <QVector>

namespace rendering {

class SvgPath
{
private:
    QStringList dataString_;

public:
    SvgPath();
    void addCircle(const QPointF &location, qreal diameter, bool counterClockwise);
    void addPolygon(const QVector<QPointF> &points);
    QString toString() const;
};

} // namespace rendering

#endif // SVGPATH_H
