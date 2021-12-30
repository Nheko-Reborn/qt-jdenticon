#include "shape.h"

namespace shapes {

Shape::Shape(void (*definition)(rendering::Renderer &, int cell, int index),
             QColor color,
             QVector<QPoint> positions,
             int startRotationIndex)
  : shapeColor_(color)
  , positions_(std::move(positions))
  , startRotationIndex_(startRotationIndex)
  , definition_(definition)
{}

QColor
Shape::getShapeColor() const
{
    return shapeColor_;
}

const QVector<QPoint> &
Shape::getPositions() const
{
    return positions_;
}

int
Shape::getStartRotationIndex() const
{
    return startRotationIndex_;
}
} // namespace shapes
