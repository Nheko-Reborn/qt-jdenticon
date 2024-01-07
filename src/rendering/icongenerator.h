#ifndef ICONGENERATOR_H
#define ICONGENERATOR_H

#include <QString>
#include <QVector>
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
    static bool isDuplicate(const QVector<int> &source,
                            int newValue,
                            const QVector<int> &duplicateValues)
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
    const QVector<shapes::ShapeCategory> &getCategories();
    QVector<shapes::Shape> getShapes(const ColorTheme &theme, const QByteArray &hash);
    void RenderBackground(Renderer &renderer) { renderer.setBackgroundColor(QColor(0, 0, 0, 0)); }
    Rectangle normalizeRectangle(const Rectangle &rect)
    {
        auto size = qMin(rect.width(), rect.height());

        // Make size a multiple of the cell count
        size -= size % cellCount();

        return Rectangle(
          rect.x() + (rect.width() - size) / 2, rect.y() + (rect.height() - size) / 2, size, size);
    }
    void RenderForeground(Renderer &renderer,
                          const Rectangle &rect,
                          const ColorTheme &colorTheme,
                          const QByteArray &hash)
    {
        // Ensure rect is quadratic and a multiple of the cell count
        auto normalizedRect = normalizeRectangle(rect);
        qDebug() << "cellCount" << cellCount();
        qDebug() << "width" << normalizedRect.width();
        auto cellSize = normalizedRect.width() / cellCount();

        auto shapes = getShapes(colorTheme, hash);
        for (const auto &shape : std::as_const(shapes)) {
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

    static qreal getHue(const QByteArray &input)
    {
        // Create a color for the input
        uint32_t hash =
          (input.at(0) << 24) ^ (input.at(1) << 16) ^ (input.at(2) << 8) ^ input.at(3);
        // create a hue value based on the hash of the input.
        // Adapted to make Nico blue
        auto userHue = static_cast<double>(hash - static_cast<uint32_t>(0x60000000)) /
                       std::numeric_limits<uint32_t>::max();
        return userHue;
    }

    static uint8_t getOctet(const QByteArray &arr, const int index)
    {
        uint8_t byte_ = arr.at(index / 2);
        if (index % 2 == 0)
            byte_ &= 0x0f;
        else
            byte_ >>= 4;
        return byte_;
    }

public:
    IconGenerator() = default;
    int cellCount() const { return 4; }
    void generate(Renderer &renderer, const Rectangle &rect, const QString &hash);
};

} // namespace rendering

#endif // ICONGENERATOR_H
