#include "shapecategory.h"

namespace shapes {

ShapeCategory::ShapeCategory(int colorIndex, int shapeIndex, int rotationIndex, QList<QPoint> &positions, QList<void(*)(rendering::Renderer&, int, int)>
 &definitions)
{
    colorIndex_ = colorIndex;
    shapeIndex_ = shapeIndex;
    rotationIndex_ = rotationIndex;
    positions_ = positions;
    definitions_ = definitions;
}

int
ShapeCategory::getShapeIndex()
{
    return shapeIndex_;
}

int
ShapeCategory::getRotationIndex()
{
    return rotationIndex_;
}

int
ShapeCategory::getColorIndex()
{
    return colorIndex_;
}

QList<QPoint>
ShapeCategory::getPositions()
{
    return positions_;
}

QList<void(*)(rendering::Renderer&, int, int)>
ShapeCategory::getDefinitions()
{
    return definitions_;
}

} // namespace shapes
