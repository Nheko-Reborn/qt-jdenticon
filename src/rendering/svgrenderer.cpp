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
SvgRenderer::addPolygonNoTransform(const QVector<QPointF> &points)
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
    stream << toSvg(fragment) << Qt::endl;
}

QString
SvgRenderer::toSvg(bool fragment)
{
    auto svg = QStringList();
    svg.reserve(pathsByColor_.size() + 3);
    auto widthAsString  = QString::number(width_);
    auto heightAsString = QString::number(height_);

    if (!fragment) {
        svg.append(
          QStringLiteral("<svg xmlns=\"http://www.w3.org/2000/svg\" width=\"%1\" height=\"%2\" "
                         "viewBox=\"0 0 %1 %2\" preserveAspectRatio=\"xMidYMid meet\">")
            .arg(widthAsString, heightAsString));
    }

    if (backColor_.alpha() > 0) {
        svg.append(
          QStringLiteral(
            "<rect fill=\"%2\" fill-opacity=\"%1\" x=\"0\" y=\"0\" width=\"%3\" height=\"%4\"/>")
            .arg(backColor_.alphaF())
            .arg(backColor_.name(), widthAsString, heightAsString));
    }

    for (auto pair : pathsByColor_.keys()) {
        svg.append(QStringLiteral("<path fill=\"%1\" d=\"%2\"/>")
                     .arg(pair, pathsByColor_.value(pair)->toString()));
    }

    if (!fragment) {
        svg.append(QStringLiteral("</svg>"));
    }

    return QStringList(svg).join(QStringLiteral(""));
}

} // namespace rendering
