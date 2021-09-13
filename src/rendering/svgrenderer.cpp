#include "svgrenderer.h"

namespace rendering {

SvgRenderer::SvgRenderer(int width, int height)
{
    width_  = width;
    height_ = height;
}

void
SvgRenderer::addCircleNoTransform(QPointF &location, qreal diameter, bool counterClockwise)
{
    path_->addCircle(location, diameter, counterClockwise);
}

void
SvgRenderer::addPolygonNoTransform(QList<QPointF> &points)
{
    path_->addPolygon(points);
}

void
SvgRenderer::setBackgroundColor(const QColor &color)
{
    backColor_ = color;
}

void
SvgRenderer::beginShape(const QColor &color)
{
    if (pathsByColor_.contains(color.name())) {
        path_ = pathsByColor_.value(color.name());
    } else {
        path_ = new SvgPath();
        pathsByColor_.insert(color.name(), path_);
    }
}

void
SvgRenderer::save(QTextStream &stream, bool fragment)
{
    stream << toSvg(fragment) << endl;
}

QString
SvgRenderer::toSvg(bool fragment)
{
    auto svg            = QList<QString>();
    auto widthAsString  = QString::number(width_);
    auto heightAsString = QString::number(height_);

    if (!fragment) {
        svg.append("<svg xmlns=\"http://www.w3.org/2000/svg\" width=\"" + widthAsString +
                   "\" height=\"" + heightAsString + "\" viewBox=\"0 0 " + widthAsString + " " +
                   heightAsString + "\" preserveAspectRatio=\"xMidYMid meet\">");
    }

    if (backColor_.alpha() > 0) {
        svg.append("<rect fill=\"" + backColor_.name() + "\" fill-opacity=\"" +
                   QString::number(backColor_.alphaF()) + "\" x=\"0\" y=\"0\" width=\"" +
                   widthAsString + "\" height=\"" + heightAsString + "\"/>");
    }

    for (auto pair : pathsByColor_.keys()) {
        svg.append("<path fill=\"" + pair + "\" d=\"" + pathsByColor_.value(pair)->toString() +
                   "\"/>");
    }

    if (!fragment) {
        svg.append("</svg>");
    }

    return QStringList(svg).join("");
}

} // namespace rendering
