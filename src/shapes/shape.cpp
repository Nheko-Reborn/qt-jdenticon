#include "shape.h"

namespace shapes {

Shape::Shape(void (*definition)(rendering::Renderer&, int cell, int index), QColor &color, QList<QPoint> &positions, int startRotationIndex)
{
    definition_ = definition;
    shapeColor_ = color;
    positions_ = positions;
    startRotationIndex_ = startRotationIndex;
}

QColor
Shape::getShapeColor()
{
    return shapeColor_;
}

QList<QPoint>
Shape::getPositions()
{
    return positions_;
}

int
Shape::getStartRotationIndex()
{
    return startRotationIndex_;
}
} // namespace shapes
