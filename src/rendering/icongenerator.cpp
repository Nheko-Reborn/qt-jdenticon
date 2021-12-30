#include "icongenerator.h"

#include <QCryptographicHash>
namespace rendering {

static QVector<QPoint> shapeOne_({QPoint(1, 0),
                                  QPoint(2, 0),
                                  QPoint(2, 3),
                                  QPoint(1, 3),
                                  QPoint(0, 1),
                                  QPoint(3, 1),
                                  QPoint(3, 2),
                                  QPoint(0, 2)});
static QVector<QPoint> shapeTwo_({{0, 0}, {3, 0}, {3, 3}, {0, 3}});
static QVector<QPoint> shapeThree_({{1, 1}, {2, 1}, {2, 2}, {1, 2}});
static QVector<void (*)(rendering::Renderer &, int, int)> centerShapes_ =
  shapes::ShapeDefinitions::CenterShapes();
static QVector<void (*)(rendering::Renderer &, int, int)> outerShapes_ =
  shapes::ShapeDefinitions::OuterShapes();

static const QVector<shapes::ShapeCategory> defaultCategories_ = {
  // Sides
  shapes::ShapeCategory(8, 2, 3, shapeOne_, outerShapes_),
  // Corner
  shapes::ShapeCategory(9, 4, 5, shapeTwo_, outerShapes_),
  // Center
  shapes::ShapeCategory(10, 1, -1, shapeThree_, centerShapes_),
};

QVector<shapes::Shape>
IconGenerator::getShapes(const ColorTheme &theme, const QByteArray &hash)
{
    QVector<shapes::Shape> shapes;
    QVector<int> usedColorThemeIndexes;
    shapes.reserve(defaultCategories_.size());
    usedColorThemeIndexes.reserve(defaultCategories_.size());

    for (const auto &category : qAsConst(defaultCategories_)) {
        qDebug() << "themeCount " << theme.count();
        auto colorThemeIndex = getOctet(hash, category.getColorIndex()) % theme.count();

        QVector<int> dupsOne = {0, 4};
        QVector<int> dupsTwo = {2, 3};
        if (isDuplicate(usedColorThemeIndexes,
                        colorThemeIndex,
                        dupsOne) || // Disallow dark gray and dark color combo
            isDuplicate(usedColorThemeIndexes,
                        colorThemeIndex,
                        dupsTwo)) // Disallow light gray and light color combo
        {
            colorThemeIndex = 1;
        }

        usedColorThemeIndexes.append(colorThemeIndex);

        auto startRotationIndex =
          category.getRotationIndex() == -1 ? 0 : getOctet(hash, category.getRotationIndex());
        auto octet          = getOctet(hash, category.getShapeIndex());
        auto definitionSize = category.getDefinitions().size();
        qDebug() << "definitionSize " << definitionSize;
        auto shape = category.getDefinitions()[octet % definitionSize];
        qDebug() << "Shape # " << (octet % definitionSize);
        auto positions = category.getPositions();
        shapes::Shape newShape{
          shape, theme[colorThemeIndex], std::move(positions), startRotationIndex};
        shapes.append(std::move(newShape));
    }
    return shapes;
}

void
IconGenerator::generate(Renderer &renderer, const Rectangle &rect, const QString &input)
{
    QByteArray hash = QCryptographicHash::hash(input.toUtf8(), QCryptographicHash::Sha1);
    auto hue        = getHue(hash);

    qDebug() << "hue" << hue;
    auto colorTheme = ColorTheme(hue);

    RenderBackground(renderer);
    RenderForeground(renderer, rect, colorTheme, hash);
}

} // namespace rendering
