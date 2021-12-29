#include "shape.h"

namespace shapes {

Shape::Shape(void (*definition)(rendering::Renderer &, int cell, int index),
             QColor color,
             QVector<QPoint> &positions,
             int startRotationIndex)
  : shapeColor_(color)
  , positions_(positions)
  , startRotationIndex_(startRotationIndex)
  , definition_(definition)
{}

QColor
Shape::getShapeColor()
{
    return shapeColor_;
}

QVector<QPoint>
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
