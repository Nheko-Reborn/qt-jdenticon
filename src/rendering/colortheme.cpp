#include "colortheme.h"

namespace rendering {

ColorTheme::ColorTheme(qreal hue, IdenticonStyle &style)
{
    if (style.hues().size() > 0)
    {
        // Multiply with 0.999 to change the range to [0, 1)
        int hueIndex = qFloor(0.999 * hue * style.hues().size());
        hue = style.hues().at(hueIndex);
    }

    darkGray_ = ColorUtils::fromHslCompensated(hue, style.grayscaleSaturation(), style.minGrayLightness());
    midColor_ = ColorUtils::fromHslCompensated(hue, style.colorSaturation(), (style.minColorLightness() + style.maxColorLightness()) / 2);
    lightGray_ = ColorUtils::fromHslCompensated(hue, style.grayscaleSaturation(), style.maxGrayLightness());
    lightColor_ = ColorUtils::fromHslCompensated(hue, style.colorSaturation(), style.maxColorLightness());
    darkColor_ = ColorUtils::fromHslCompensated(hue, style.colorSaturation(), style.minColorLightness());
}

QColor
&ColorTheme::operator[](int index)
{
    if (index == 0) return darkGray_;
    if (index == 1) return midColor_;
    if (index == 2) return lightGray_;
    if (index == 3) return lightColor_;
    if (index == 4) return darkColor_;
    throw std::out_of_range("index");
}

} // namespace rendering
