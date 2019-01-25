#ifndef SHAPEPOSITION_H
#define SHAPEPOSITION_H


namespace shapes {

class ShapePosition
{
private:
    int x_;
    int y_;
public:
    ShapePosition(int x, int y);
    int getX();
    int getY();
};

} // namespace Shapes

#endif // SHAPEPOSITION_H
