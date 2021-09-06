#ifndef SVGPATH_H
#define SVGPATH_H

#include <QList>
#include <QString>
#include <QPointF>

namespace rendering {

class SvgPath
{
private:
    QList<QString> dataString_;
public:
    SvgPath();
    void addCircle(QPointF &location, qreal diameter, bool counterClockwise);
    void addPolygon(QList<QPointF> &points);
    QString toString() const;
};

} // namespace rendering

#endif // SVGPATH_H
