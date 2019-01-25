#include "identicon.h"

IdenticonStyle
Identicon::defaultStyle_ = {};
Identicon::Identicon(QByteArray &hash, int size)
{
    size_ = size;
    hash_ = hash;
}

Identicon
Identicon::fromHash(QByteArray &hash, int size)
{
    Identicon fromHash(hash, size);
    return fromHash;
}

Identicon
Identicon::fromHash(QString &hash, int size)
{
    QByteArray hashArr = QByteArray::fromStdString(hash.toStdString());
    Identicon identicon(hashArr, size);
    return identicon;
}

QString
Identicon::generateSvg(Identicon &icon, bool fragment)
{
    auto iconBounds = icon.getIconBounds();
    auto renderer = rendering::SvgRenderer(icon.size(), icon.size());
    icon.draw(renderer, iconBounds);
    return renderer.toSvg(fragment);
}

rendering::Rectangle
Identicon::getIconBounds()
{
    // Round to nearest integer
    auto padding = qFloor(defaultStyle_.padding() * size() + 0.5);

    return  rendering::Rectangle(
        padding, padding,
        size() - padding * 2, size() - padding * 2);
}

void
Identicon::draw(rendering::Renderer &renderer, rendering::Rectangle &rect)
{
    iconGenerator_.generate(renderer, rect, defaultStyle_, hash_);
}


