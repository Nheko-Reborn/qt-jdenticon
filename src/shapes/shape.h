#ifndef SHAPE_H
#define SHAPE_H

#include <QColor>
#include <QList>
#include "shapeposition.h"
#include "../rendering/renderer.h"

namespace shapes {

class Shape
{
private:
    QColor shapeColor_;
    QList<QPoint> positions_;
    int startRotationIndex_;
    void (*definition_)(rendering::Renderer &renderer, int cell, int index);

public:
    Shape(void (*definition)(rendering::Renderer &renderer, int cell, int index), QColor &color, QList<QPoint> &positions, int startRotationIndex);
    QColor getShapeColor();
    QList<QPoint> getPositions();
    int getStartRotationIndex();
    void (*getDefinition())(rendering::Renderer&, int, int) { return definition_; }

};

} // namespace shapes

#endif // SHAPE_H
