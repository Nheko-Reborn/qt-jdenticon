#include "transform.h"

namespace rendering {
Transform::Transform(int x, int y, int size, int rotation)
{
    x_        = x;
    y_        = y;
    size_     = size;
    rotation_ = rotation;
}

QPointF
Transform::TransformPoint(qreal x, qreal y, qreal width, qreal height)
{
    auto right  = x_ + size_;
    auto bottom = y_ + size_;

    return rotation_ == 1   ? QPointF(right - y - height, y_ + x)
           : rotation_ == 2 ? QPointF(right - x - width, bottom - y - height)
           : rotation_ == 3 ? QPointF(x_ + y, bottom - x - width)
                            : QPointF(x_ + x, y_ + y);
}

}
