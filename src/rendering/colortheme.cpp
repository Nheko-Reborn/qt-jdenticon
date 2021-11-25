#include <stdexcept>

#include "colortheme.h"
#include "../identiconstyle.h"

#include <stdexcept>

namespace rendering {

ColorTheme::ColorTheme(qreal hue)
{
    darkGray_ =
      ColorUtils::fromHslCompensated(hue, IdenticonStyle::grayscaleSaturation(), IdenticonStyle::minGrayLightness());
    midColor_ = ColorUtils::fromHslCompensated(
      hue, IdenticonStyle::colorSaturation(), (IdenticonStyle::minColorLightness() + IdenticonStyle::maxColorLightness()) / 2);
    lightGray_ =
      ColorUtils::fromHslCompensated(hue, IdenticonStyle::grayscaleSaturation(), IdenticonStyle::maxGrayLightness());
    lightColor_ =
      ColorUtils::fromHslCompensated(hue, IdenticonStyle::colorSaturation(), IdenticonStyle::maxColorLightness());
    darkColor_ =
      ColorUtils::fromHslCompensated(hue, IdenticonStyle::colorSaturation(), IdenticonStyle::minColorLightness());
}

QColor &
ColorTheme::operator[](int index)
{
    if (index == 0)
        return darkGray_;
    if (index == 1)
        return midColor_;
    if (index == 2)
        return lightGray_;
    if (index == 3)
        return lightColor_;
    if (index == 4)
        return darkColor_;
    throw std::out_of_range("index");
}

} // namespace rendering
