#ifndef IDENTICON_H
#define IDENTICON_H

#include <QByteArray>

#include "identiconstyle.h"
#include "rendering/icongenerator.h"
#include "rendering/rectangle.h"
#include "rendering/svgrenderer.h"

class Identicon
{
private:
    QString hash_;
    int size_;
    rendering::IconGenerator iconGenerator_;
    IdenticonStyle style_;

public:
    Identicon(QString &hash, int size);
    int size() { return size_; }
    rendering::Rectangle getIconBounds();
    static QString generateSvg(Identicon &identicon, bool fragment);
    void draw(rendering::Renderer &renderer, rendering::Rectangle &rect);
};

#endif // IDENTICON_H
