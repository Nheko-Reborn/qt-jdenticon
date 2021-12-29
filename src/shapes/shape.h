#ifndef SHAPE_H
#define SHAPE_H

#include <QColor>
#include <QVector>

#include "../rendering/renderer.h"
#include "shapeposition.h"

namespace shapes {

class Shape
{
private:
    QColor shapeColor_;
    QVector<QPoint> positions_;
    int startRotationIndex_;
    void (*definition_)(rendering::Renderer &renderer, int cell, int index);

public:
    Shape(void (*definition)(rendering::Renderer &renderer, int cell, int index),
          QColor color,
          QVector<QPoint> &positions,
          int startRotationIndex);
    QColor getShapeColor();
    QVector<QPoint> getPositions();
    int getStartRotationIndex();
    void (*getDefinition())(rendering::Renderer &, int, int) { return definition_; }
};

} // namespace shapes

#endif // SHAPE_H
