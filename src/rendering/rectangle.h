#ifndef RECTANGLE_H
#define RECTANGLE_H

namespace rendering {

class Rectangle
{
private:
    int x_;
    int y_;
    int width_;
    int height_;

public:
    Rectangle(int x, int y, int width, int height);
    int x() { return x_; }
    int y() { return y_; }
    int width() { return width_; }
    int height() { return height_; }
};

} // namespace rendering

#endif // RECTANGLE_H
