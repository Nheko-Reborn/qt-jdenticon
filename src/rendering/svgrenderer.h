#ifndef SVGRENDERER_H
#define SVGRENDERER_H

#include <QColor>
#include <QMap>
#include <QPointF>
#include <QString>
#include <QTextStream>
#include <QVector>

#include "renderer.h"
#include "svgpath.h"

namespace rendering {

class SvgRenderer : public Renderer
{
private:
    QMap<QString, SvgPath *> pathsByColor_;
    SvgPath *path_;
    int width_, height_;
    QColor backColor_;

protected:
    void addCircleNoTransform(QPointF &location, qreal diameter, bool counterClockwise) override;
    void addPolygonNoTransform(const QVector<QPointF> &points) override;

public:
    SvgRenderer(int width, int height);
    void setBackgroundColor(const QColor &color) override;
    void beginShape(const QColor &color) override;
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
