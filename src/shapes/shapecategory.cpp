#include "shapecategory.h"

namespace shapes {

ShapeCategory::ShapeCategory(int colorIndex,
                             int shapeIndex,
                             int rotationIndex,
                             const QVector<QPoint> &positions,
                             const QVector<void (*)(rendering::Renderer &, int, int)> &definitions)
{
    colorIndex_    = colorIndex;
    shapeIndex_    = shapeIndex;
    rotationIndex_ = rotationIndex;
    positions_     = positions;
    definitions_   = definitions;
}

int
ShapeCategory::getShapeIndex() const
{
    return shapeIndex_;
}

int
ShapeCategory::getRotationIndex() const
{
    return rotationIndex_;
}

int
ShapeCategory::getColorIndex() const
{
    return colorIndex_;
}

QVector<QPoint>
ShapeCategory::getPositions() const
{
    return positions_;
}

QVector<void (*)(rendering::Renderer &, int, int)>
ShapeCategory::getDefinitions() const
{
    return definitions_;
}

} // namespace shapes
