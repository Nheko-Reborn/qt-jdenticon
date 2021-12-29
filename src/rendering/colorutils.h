#ifndef COLORUTILS_H
#define COLORUTILS_H

#include <QColor>
#include <QVector>
#include <QtMath>

namespace rendering {

class ColorUtils
{
private:
    static QVector<qreal> lightnessCompensation_;

public:
    static QColor fromHslCompensated(qreal hue, qreal saturation, qreal lightness);
};

} // namespace rendering

#endif // COLORUTILS_H
