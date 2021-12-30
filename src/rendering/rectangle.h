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
    int x() const { return x_; }
    int y() const { return y_; }
    int width() const { return width_; }
    int height() const { return height_; }
};

} // namespace rendering

#endif // RECTANGLE_H
