#ifndef RENDERERINTERFACE_H
#define RENDERERINTERFACE_H

#include <QColor>
#include <QPointF>
#include <QtDebug>

#include <algorithm>

#include "transform.h"

namespace rendering {
enum class TriangleDirection
{
    /// <summary>
    /// The 90 degree angle is pointing to South West.
    /// </summary>
    SouthWest = 0,
    /// <summary>
    /// The 90 degree angle is pointing to North West.
    /// </summary>
    NorthWest = 1,
    /// <summary>
    /// The 90 degree angle is pointing to North East.
    /// </summary>
    NorthEast = 2,
    /// <summary>
    /// The 90 degree angle is pointing to South East.
    /// </summary>
    SouthEast = 3
};
class Renderer
{
private:
    Transform transform_ = Transform::empty();
    void addPolygonCore(QList<QPointF> &points, bool invert)
    {
        if (invert) {
            std::reverse(std::begin(points), std::end(points));
        }

        QList<QPointF> transformedPoints;
        for (QPointF point : points) {
            auto transPoint = transform_.TransformPoint(point.x(), point.y());
            transformedPoints.append(transPoint);
        }

        addPolygonNoTransform(transformedPoints);
    }

protected:
    virtual void addCircleNoTransform(QPointF &location,
                                      qreal diameter,
                                      bool counterClockwise = false) = 0;
    virtual void addPolygonNoTransform(QList<QPointF> &points)       = 0;

public:
    Renderer()          = default;
    virtual ~Renderer() = default;
    Transform getTransform() { return transform_; }
    void setTransform(Transform &value) { transform_ = value; }
    void addCircle(qreal x, qreal y, qreal size, bool invert = false)
    {
        auto northWest = transform_.TransformPoint(x, y, size, size);
        addCircleNoTransform(northWest, size, invert);
    }
    void addPolygon(QList<QPointF> &points, bool invert = false)
    {
        QList<QPointF> pointsClone = points;
        addPolygonCore(pointsClone, invert);
    }
    void addRectangle(qreal x, qreal y, qreal width, qreal height, bool invert = false)
    {
        QList<QPointF> points = {QPointF(x, y),
                                 QPointF(x + width, y),
                                 QPointF(x + width, y + height),
                                 QPointF(x, y + height)};
        addPolygonCore(points, invert);
    }
    void addTriangle(qreal x,
                     qreal y,
                     qreal width,
                     qreal height,
                     TriangleDirection direction,
                     bool invert = false)
    {
        QList<QPointF> points = {QPointF(x + width, y),
                                 QPointF(x + width, y + height),
                                 QPointF(x, y + height),
                                 QPointF(x, y)};

        points.removeAt(static_cast<int>(direction));

        addPolygonCore(points, invert);
    }
    void addRhombus(qreal x, qreal y, qreal width, qreal height, bool invert = false)
    {
        QList<QPointF> points = {QPointF(x + width / 2, y),
                                 QPointF(x + width, y + height / 2),
                                 QPointF(x + width / 2, y + height),
                                 QPointF(x, y + height / 2)};
        addPolygonCore(points, invert);
    }
    virtual void setBackgroundColor(const QColor &color) = 0;
    virtual void beginShape(const QColor &color)         = 0;
};

} // namespace rendering

#endif // RENDERER_H
