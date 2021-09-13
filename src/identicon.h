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
    QByteArray hash_;
    int size_;
    rendering::IconGenerator iconGenerator_;
    IdenticonStyle style_;
    static IdenticonStyle defaultStyle_;

public:
    Identicon(QByteArray &hash, int size);
    int size() { return size_; }
    rendering::Rectangle getIconBounds();
    static Identicon fromHash(QByteArray &hash, int size);
    static Identicon fromHash(QString &hash, int size);
    static QString generateSvg(Identicon &identicon, bool fragment);
    void draw(rendering::Renderer &renderer, rendering::Rectangle &rect);
};

#endif // IDENTICON_H
