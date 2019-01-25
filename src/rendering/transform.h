#ifndef TRANSFORM_H
#define TRANSFORM_H

#include <QPointF>

namespace rendering {

class Transform {
private:
    int x_;
    int y_;
    int size_;
    int rotation_;

public:
    Transform(int x, int y, int size, int rotation);

    static Transform empty() {
        return Transform(0,0,0,0);
    }
    int x() { return x_; }
    int y() { return y_; }
    int size() { return size_; }
    int rotation() { return rotation_; }

    QPointF TransformPoint(qreal x, qreal y, qreal width = 0, qreal height = 0);
};
}
#endif // TRANSFORM_H
