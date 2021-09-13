#ifndef COLORUTILS_H
#define COLORUTILS_H

#include <QColor>
#include <QList>
#include <QtMath>

namespace rendering {

class ColorUtils
{
private:
    static QList<qreal> lightnessCompensation_;

public:
    static QColor fromHslCompensated(qreal hue, qreal saturation, qreal lightness);
};

} // namespace rendering

#endif // COLORUTILS_H
