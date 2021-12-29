#ifndef SHAPECATEGORY_H
#define SHAPECATEGORY_H

#include <QVector>

#include "../rendering/renderer.h"

namespace shapes {

class ShapeCategory
{
private:
    int colorIndex_;
    int shapeIndex_;
    int rotationIndex_;
    QVector<QPoint> positions_;
    QVector<void (*)(rendering::Renderer &, int, int)> definitions_;

public:
    ShapeCategory(int colorIndex,
                  int shapeIndex,
                  int rotationIndex,
                  const QVector<QPoint> &positions,
                  const QVector<void (*)(rendering::Renderer &, int, int)> &);
    int getColorIndex() const;
    int getShapeIndex() const;
    int getRotationIndex() const;
    QVector<void (*)(rendering::Renderer &, int, int)> getDefinitions() const;
    QVector<QPoint> getPositions() const;
    void setColorIndex(int colIndex) { colorIndex_ = colIndex; }
    void setShapeIndex(int shapeIndex) { shapeIndex_ = shapeIndex; }
    void setRotationIndex(int rotationIndex) { rotationIndex_ = rotationIndex; }
    void setDefinitions(const QVector<void (*)(rendering::Renderer &, int, int)> &definitions);
};

} // namespace shapes

#endif // SHAPECATEGORY_H
