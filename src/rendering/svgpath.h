#ifndef SVGPATH_H
#define SVGPATH_H

#include <QPointF>
#include <QString>
#include <QVector>

namespace rendering {

class SvgPath
{
private:
    QString dataString_;

public:
    SvgPath() = default;
    void addCircle(const QPointF &location, qreal diameter, bool counterClockwise);
    void addPolygon(const QVector<QPointF> &points);
    const QString &toString() const;
};

} // namespace rendering

#endif // SVGPATH_H
