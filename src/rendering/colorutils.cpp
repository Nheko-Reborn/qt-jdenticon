#include "colorutils.h"

namespace rendering {

QList<qreal> ColorUtils::lightnessCompensation_ = {0.55, 0.5, 0.5, 0.46, 0.6, 0.55, 0.55};

QColor
ColorUtils::fromHslCompensated(qreal hue, qreal saturation, qreal lightness)
{
    if (hue < 0)
        throw new std::out_of_range("hue");
    if (hue > 1)
        throw new std::out_of_range("hue");

    qreal lightnessCompensation = lightnessCompensation_[qFloor(hue * 6 + 0.5)];

    // Adjust the input lightness relative to the compensation
    lightness = lightness < 0.5
                  ? lightness * lightnessCompensation * 2.0
                  : lightnessCompensation + (lightness - 0.5) * (1 - lightnessCompensation) * 2.0;

    return QColor::fromHslF(hue, saturation, lightness);
}

} // namespace rendering
