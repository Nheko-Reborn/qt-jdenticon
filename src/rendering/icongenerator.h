#ifndef ICONGENERATOR_H
#define ICONGENERATOR_H

#include <QList>
#include <QString>
#include <QtDebug>

#include "../shapes/shape.h"
#include "../shapes/shapecategory.h"
#include "../shapes/shapedefinitions.h"
#include "colortheme.h"
#include "rectangle.h"

namespace rendering {

class IconGenerator final
{
private:
    static bool isDuplicate(QList<int> &source, int newValue, QList<int> &duplicateValues)
    {
        if (duplicateValues.contains(newValue)) {
            for (int i = 0; i < duplicateValues.size(); i++) {
                if (source.contains(duplicateValues[i])) {
                    return true;
                }
            }
        }
        return false;
    }

protected:
    QList<shapes::ShapeCategory> getCategories();
    QList<shapes::Shape> getShapes(ColorTheme &theme, QString &hash);
    void RenderBackground(Renderer &renderer)
    {
        renderer.setBackgroundColor(QColor(0,0,0,0));
    }
    Rectangle normalizeRectangle(Rectangle &rect)
    {
        auto size = qMin(rect.width(), rect.height());

        // Make size a multiple of the cell count
        size -= size % cellCount();

        return Rectangle(
          rect.x() + (rect.width() - size) / 2, rect.y() + (rect.height() - size) / 2, size, size);
    }
    void RenderForeground(Renderer &renderer,
                          Rectangle &rect,
                          ColorTheme &colorTheme,
                          QString &hash)
    {
        // Ensure rect is quadratic and a multiple of the cell count
        auto normalizedRect = normalizeRectangle(rect);
        qDebug() << "cellCount" << cellCount();
        qDebug() << "width" << normalizedRect.width();
        auto cellSize = normalizedRect.width() / cellCount();

        auto shapes = getShapes(colorTheme, hash);
        for (auto shape : shapes) {
            auto rotation = shape.getStartRotationIndex();

            QColor shapeColor = shape.getShapeColor();
            renderer.beginShape(shapeColor);

            for (int i = 0; i < shape.getPositions().size(); i++) {
                auto position = shape.getPositions()[i];

                Transform transform(normalizedRect.x() + position.x() * cellSize,
                                    normalizedRect.y() + position.y() * cellSize,
                                    cellSize,
                                    rotation++ % 4);
                renderer.setTransform(transform);

                shape.getDefinition()(renderer, cellSize, i);
            }

            // renderer.endShape();
        }
    }

    static uint32_t hashQString(const QString &input);

    static qreal getHue(const QString &input)
    {
        // Create a color for the input
        auto hash = hashQString(input);
        // create a hue value based on the hash of the input.
        // Adapted to make Nico blue
        auto userHue = static_cast<double>(hash - static_cast<uint32_t>(0x60000000)) /
                       std::numeric_limits<uint32_t>::max();
        return userHue;
    }

    static char getOctet(QString &arr, const int index)
    {
        char at     = arr.at(index).toLatin1();
        char decval = (at >= 'A') ? (at - 'A' + 10) : (at - '0');
        return decval;
    }

public:
    IconGenerator();
    int cellCount() const { return 4; }
    void generate(Renderer &renderer, Rectangle &rect, QString &hash);
};

} // namespace rendering

#endif // ICONGENERATOR_H
