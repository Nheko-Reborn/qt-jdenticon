#include "identicon.h"

static rendering::Rectangle
iconBounds(int size)
{
    // Round to nearest integer
    auto padding = qFloor(IdenticonStyle::padding() * size + 0.5);

    return rendering::Rectangle(padding, padding, size - padding * 2, size - padding * 2);
}

QString
Identicon::generateSvg(const QString &hash_, int size, bool fragment)
{
    auto renderer = rendering::SvgRenderer(size, size);
    rendering::IconGenerator{}.generate(renderer, iconBounds(size), hash_);
    return renderer.toSvg(fragment);
}
