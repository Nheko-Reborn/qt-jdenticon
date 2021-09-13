#ifndef SHAPECATEGORY_H
#define SHAPECATEGORY_H

#include <QList>

#include "../rendering/renderer.h"

namespace shapes {

class ShapeCategory
{
private:
    int colorIndex_;
    int shapeIndex_;
    int rotationIndex_;
    QList<QPoint> positions_;
    QList<void (*)(rendering::Renderer &, int, int)> definitions_;

public:
    ShapeCategory(int colorIndex,
                  int shapeIndex,
                  int rotationIndex,
                  QList<QPoint> &positions,
                  QList<void (*)(rendering::Renderer &, int, int)> &);
    int getColorIndex();
    int getShapeIndex();
    int getRotationIndex();
    QList<void (*)(rendering::Renderer &, int, int)> getDefinitions();
    QList<QPoint> getPositions();
    void setColorIndex(int colIndex) { colorIndex_ = colIndex; }
    void setShapeIndex(int shapeIndex) { shapeIndex_ = shapeIndex; }
    void setRotationIndex(int rotationIndex) { rotationIndex_ = rotationIndex; }
    void setDefinitions(QList<void (*)(rendering::Renderer &, int, int)> definitions());
};

} // namespace shapes

#endif // SHAPECATEGORY_H
