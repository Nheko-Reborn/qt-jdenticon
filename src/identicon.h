#ifndef IDENTICON_H
#define IDENTICON_H

#include <QByteArray>

#include "identiconstyle.h"
#include "rendering/icongenerator.h"
#include "rendering/rectangle.h"
#include "rendering/svgrenderer.h"

class Identicon
{
public:
    static QString generateSvg(const QString &hash, int size, bool fragment);
};

#endif // IDENTICON_H
