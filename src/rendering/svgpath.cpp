#include "svgpath.h"

#include <array>
#include <charconv>

namespace {
// See http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2015/n4502.pdf.
template<typename...>
using void_t = void;

// Primary template handles all types not supporting the operation.
template<typename, template<typename> class, typename = void_t<>>
struct detect : std::false_type
{};

// Specialization recognizes/validates only types supporting the archetype.
template<typename T, template<typename> class Op>
struct detect<T, Op, void_t<Op<T>>> : std::true_type
{};

// Archetypal expression for assignment operation.
template<typename T>
using to_chars_test = decltype(std::to_chars(std::declval<const char *>(),
                                             std::declval<const char *>(),
                                             std::declval<T>()));

// Trait corresponding to that archetype.
template<typename T>
using is_to_chars_avaiable = detect<T, to_chars_test>;
}

static const auto formatNumber = [](auto number, std::array<char, 16> &buf) {
    if constexpr (is_to_chars_avaiable<decltype(number)>()) {
        if (auto [ptr, ec] = std::to_chars(buf.data(), buf.data() + buf.size(), number);
            ec == std::errc())
            return QLatin1String(buf.data(), ptr);
        else
            return QLatin1String();
    } else {
        if (auto sz = snprintf(buf.data(), buf.size(), "%f", number); sz > 0)
            return QLatin1String(buf.data(), buf.data() + sz);
        else
            return QLatin1String();
    }
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
