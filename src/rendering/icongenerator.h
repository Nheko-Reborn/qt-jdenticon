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

class IconGenerator
{
private:
    static QList<QPoint> shapeOne_;
    static QList<QPoint> shapeTwo_;
    static QList<QPoint> shapeThree_;
    static QList<QPoint> shapeFour_;

    static QList<void (*)(rendering::Renderer &, int, int)> outerShapes_;

    static QList<void (*)(rendering::Renderer &, int, int)> centerShapes_;
    static QList<shapes::ShapeCategory> defaultCategories_;
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
    virtual QList<shapes::Shape> getShapes(ColorTheme &theme, QString &hash);
    virtual void RenderBackground(Renderer &renderer,
                                  Rectangle rect,
                                  IdenticonStyle &style,
                                  ColorTheme &colorTheme,
                                  QString &hash)
    {
        Q_UNUSED(rect);
        Q_UNUSED(style);
        Q_UNUSED(colorTheme);
        Q_UNUSED(hash);
        QColor backCol = style.backCol();
        renderer.setBackgroundColor(backCol);
    }
    virtual Rectangle normalizeRectangle(Rectangle &rect)
    {
        auto size = qMin(rect.width(), rect.height());

        // Make size a multiple of the cell count
        size -= size % cellCount();

        return Rectangle(
          rect.x() + (rect.width() - size) / 2, rect.y() + (rect.height() - size) / 2, size, size);
    }
    virtual void RenderForeground(Renderer &renderer,
                                  Rectangle &rect,
                                  IdenticonStyle &style,
                                  ColorTheme &colorTheme,
                                  QString &hash)
    {
        Q_UNUSED(style);
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
    virtual int cellCount() { return 4; }
    void generate(Renderer &renderer, Rectangle &rect, IdenticonStyle &style, QString &hash);
    virtual ~IconGenerator() = default;
};

} // namespace rendering

#endif // ICONGENERATOR_H
