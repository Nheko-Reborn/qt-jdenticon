#include "svgpath.h"

#include <array>
#include <charconv>

static const auto formatNumber = [](auto number, std::array<char, 16> &buf) {
    if (auto [ptr, ec] = std::to_chars(buf.data(), buf.data() + buf.size(), number);
        ec == std::errc())
        return QLatin1String(buf.data(), ptr);
    else
        return QLatin1String();
};

namespace rendering {

void
SvgPath::addCircle(const QPointF &location, qreal diameter, bool counterClockwise)
{
    QLatin1String sweepFlag = counterClockwise ? QLatin1String("0") : QLatin1String("1");
    auto radius             = diameter / 2;

    std::array<char, 16> xBuf{};
    std::array<char, 16> yBuf{};
    std::array<char, 16> radiusBuf{};
    std::array<char, 16> diameterBuf{};

    dataString_.append(QStringLiteral("M%1 %2a%3,%3 0 1,%4 %5,0a%3,%3 0 1,%4 -%5,0")
                         .arg(formatNumber(location.x(), xBuf),
                              formatNumber(location.y() + radius, yBuf),
                              formatNumber(radius, radiusBuf),
                              sweepFlag,
                              formatNumber(diameter, diameterBuf)));
}

void
SvgPath::addPolygon(const QVector<QPointF> &points)
{
    dataString_.reserve(dataString_.size() + points.size() * 16 + 1);

    std::array<char, 16> buf{};

    for (int i = 0; i < points.size(); i++) {
        if (i == 0)
            dataString_.append(u'M');
        else
            dataString_.append(u'L');

        dataString_.append(formatNumber(points.at(i).x(), buf));
        dataString_.append(u' ');
        dataString_.append(formatNumber(points.at(i).y(), buf));
    }

    dataString_.append('Z');
}

const QString &
SvgPath::toString() const
{
    return dataString_;
}

} // namespace rendering
