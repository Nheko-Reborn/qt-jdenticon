#ifndef SHAPEDEFINITIONS_H
#define SHAPEDEFINITIONS_H

#include <QList>
#include <QtDebug>
#include <QtMath>

#include "../rendering/renderer.h"

namespace shapes {

class ShapeDefinitions
{
public:
    static QList<void (*)(rendering::Renderer &, int, int)> OuterShapes();
    static QList<void (*)(rendering::Renderer &, int, int)> CenterShapes();

    static void outerOne(rendering::Renderer &renderer, int cell, int index)
    {
        Q_UNUSED(index);
        qDebug() << "outerOne";
        renderer.addTriangle(0, 0, cell, cell, rendering::TriangleDirection::SouthWest);
    }
    static void outerTwo(rendering::Renderer &renderer, int cell, int index)
    {
        Q_UNUSED(index);
        qDebug() << "outerTwo";
        renderer.addTriangle(
          0, cell / 2.0, cell, cell / 2.0, rendering::TriangleDirection::SouthWest);
    }
    static void outerThree(rendering::Renderer &renderer, int cell, int index)
    {
        Q_UNUSED(index);
        qDebug() << "outerThree";
        renderer.addRhombus(0, 0, cell, cell);
    }
    static void outerFour(rendering::Renderer &renderer, int cell, int index)
    {
        Q_UNUSED(index);
        qDebug() << "outerFour";
        auto m = cell * 0.16667;
        renderer.addCircle(m, m, cell - 2 * m);
    }
    static void centerOne(rendering::Renderer &renderer, int cell, int index)
    {
        Q_UNUSED(index);
        qDebug() << "centerOne";
        qreal k                = cell * 0.42;
        QList<QPointF> polygon = {QPointF(0, 0),
                                  QPointF(cell, 0),
                                  QPointF(cell, cell - k * 2),
                                  QPointF(cell - k, cell),
                                  QPointF(0, cell)};
        renderer.addPolygon(polygon);
    }
    static void centerTwo(rendering::Renderer &renderer, int cell, int index)
    {
        Q_UNUSED(index);
        qDebug() << "centerTwo";
        auto w = qFloor(cell * 0.5);
        auto h = qFloor(cell * 0.8);
        renderer.addTriangle(cell - w, 0, w, h, rendering::TriangleDirection::NorthEast);
    }
    static void centerThree(rendering::Renderer &renderer, int cell, int index)
    {
        Q_UNUSED(index);
        qDebug() << "centerThree";
        auto s = cell / 3;
        renderer.addRectangle(s, s, cell - s, cell - s);
    }
    static void centerFour(rendering::Renderer &renderer, int cell, int index)
    {
        Q_UNUSED(index);
        qDebug() << "centerFour";
        qreal tmp = cell * 0.1;

        auto inner = tmp > 1 ? qFloor(tmp) : // large icon => truncate decimals
                       tmp > 0.5 ? 1
                                 : // medium size icon => fixed width
                       tmp;        // small icon => anti-aliased border

        // Use fixed outer border widths in small icons to ensure the border is drawn
        auto outer = cell < 6 ? 1 : cell < 8 ? 2 : cell / 4;

        renderer.addRectangle(outer, outer, cell - inner - outer, cell - inner - outer);
    }
    static void centerFive(rendering::Renderer &renderer, int cell, int index)
    {
        Q_UNUSED(index);
        qDebug() << "centerFive";
        auto m = qFloor(cell * 0.15);
        auto s = qFloor(cell * 0.5);
        renderer.addCircle(cell - s - m, cell - s - m, s);
    }
    static void centerSix(rendering::Renderer &renderer, int cell, int index)
    {
        Q_UNUSED(index);
        qDebug() << "centerSix";

        qreal inner = cell * 0.1;
        qreal outer = inner * 4;

        // Align edge to nearest pixel in large icons
        if (outer > 3) {
            outer = qFloor(outer);
        }

        renderer.addRectangle(0, 0, cell, cell);
        QList<QPointF> polygon = {QPointF(outer, outer),
                                  QPointF(cell - inner, outer),
                                  QPointF(outer + (cell - outer - inner) / 2, cell - inner)};
        renderer.addPolygon(polygon, true);
    }
    static void centerSeven(rendering::Renderer &renderer, int cell, int index)
    {
        Q_UNUSED(index);
        qDebug() << "centerSeven";

        QList<QPointF> polygon = {QPointF(0, 0),
                                  QPointF(cell, 0),
                                  QPointF(cell, cell * 0.7),
                                  QPointF(cell * 0.4, cell * 0.4),
                                  QPointF(cell * 0.7, cell),
                                  QPointF(0, cell)};
        renderer.addPolygon(polygon);
    }
    static void centerEight(rendering::Renderer &renderer, int cell, int index)
    {
        Q_UNUSED(index);
        qDebug() << "centerEight";

        renderer.addTriangle(
          cell / 2.0, cell / 2.0, cell / 2.0, cell / 2.0, rendering::TriangleDirection::SouthEast);
    }
    static void centerNine(rendering::Renderer &renderer, int cell, int index)
    {
        Q_UNUSED(index);
        qDebug() << "centerNine";

        QList<QPointF> polygons = {QPointF(0, 0),
                                   QPointF(cell, 0),
                                   QPointF(cell, cell / 2),
                                   QPointF(cell / 2, cell),
                                   QPointF(0, cell)};
        renderer.addPolygon(polygons);
    }
    static void centerTen(rendering::Renderer &renderer, int cell, int index)
    {
        Q_UNUSED(index);
        qDebug() << "centerTen";

        qreal tmp  = cell * 0.14;
        auto inner = cell < 8 ? tmp : // small icon => anti-aliased border
                       qFloor(tmp);   // large icon => truncate decimals

        // Use fixed outer border widths in small icons to ensure the border is drawn
        auto outer = cell < 4 ? 1 : cell < 6 ? 2 : qFloor(cell * 0.35);

        renderer.addRectangle(0, 0, cell, cell);
        renderer.addRectangle(outer, outer, cell - outer - inner, cell - outer - inner, true);
    }
    static void centerEleven(rendering::Renderer &renderer, int cell, int index)
    {
        Q_UNUSED(index);
        qDebug() << "center11";

        qreal inner = cell * 0.12;
        qreal outer = inner * 3;

        renderer.addRectangle(0, 0, cell, cell);
        renderer.addCircle(outer, outer, cell - inner - outer, true);
    }
    static void centerTwelve(rendering::Renderer &renderer, int cell, int index)
    {
        Q_UNUSED(index);
        qDebug() << "center12";

        renderer.addTriangle(
          cell / 2.0, cell / 2.0, cell / 2.0, cell / 2.0, rendering::TriangleDirection::SouthEast);
    }
    static void centerThirteen(rendering::Renderer &renderer, int cell, int index)
    {
        Q_UNUSED(index);

        qDebug() << "center13";

        qreal m = cell * 0.25;

        renderer.addRectangle(0, 0, cell, cell);
        renderer.addRhombus(m, m, cell - m, cell - m, true);
    }
    static void centerFourteen(rendering::Renderer &renderer, int cell, int index)
    {
        Q_UNUSED(index);

        qDebug() << "center14";

        qreal m = cell * 0.4;
        qreal s = cell * 1.2;

        if (index != 0) {
            renderer.addCircle(m, m, s);
        }
    }
};

} // namespace shapes

#endif // SHAPEDEFINITIONS_H
