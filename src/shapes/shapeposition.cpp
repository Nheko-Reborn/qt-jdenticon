#include "shapeposition.h"

namespace shapes {

ShapePosition::ShapePosition(int x, int y)
{
    x_ = x;
    y_ = y;
}

int
ShapePosition::getX()
{
    return x_;
}

int
ShapePosition::getY()
{
    return y_;
}

} // namespace Shapes
