#ifndef SVGRENDERER_H
#define SVGRENDERER_H

#include <QColor>
#include <QHash>
#include <QList>
#include <QPointF>
#include <QString>
#include <QTextStream>

#include "renderer.h"
#include "svgpath.h"

namespace rendering {

class SvgRenderer : public Renderer
{
private:
    QHash<QString, SvgPath *> pathsByColor_;
    SvgPath *path_;
    int width_, height_;
    QColor backColor_;

protected:
    void addCircleNoTransform(QPointF &location, qreal diameter, bool counterClockwise);
    void addPolygonNoTransform(QList<QPointF> &points);

public:
    SvgRenderer(int width, int height);
    void setBackgroundColor(const QColor &color);
    void beginShape(const QColor &color);
    void save(QTextStream &stream, bool fragment);
    QString toSvg(bool fragment);
    ~SvgRenderer()
    {
        for (SvgPath *path : pathsByColor_.values()) {
            delete path;
        }
    }
};

} // namespace rendering

#endif // SVGRENDERER_H
