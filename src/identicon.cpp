#include "identicon.h"

Identicon::Identicon(const QString &hash, int size)
  : hash_(hash)
  , size_(size)
{}

QString
Identicon::generateSvg(Identicon &icon, bool fragment)
{
    auto iconBounds = icon.getIconBounds();
    auto renderer   = rendering::SvgRenderer(icon.size(), icon.size());
    icon.draw(renderer, iconBounds);
    return renderer.toSvg(fragment);
}

rendering::Rectangle
Identicon::getIconBounds()
{
    // Round to nearest integer
    auto padding = qFloor(IdenticonStyle::padding() * size() + 0.5);

    return rendering::Rectangle(padding, padding, size() - padding * 2, size() - padding * 2);
}

void
Identicon::draw(rendering::Renderer &renderer, rendering::Rectangle &rect)
{
    iconGenerator_.generate(renderer, rect, hash_);
}
