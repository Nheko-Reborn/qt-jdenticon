#ifndef IDENTICONSTYLE_H
#define IDENTICONSTYLE_H

#include <QColor>

class IdenticonStyle
{
public:
    static QColor backCol() { return QColor(0,0,0,0); }
    static qreal padding() { return 0.08; }
    static qreal colorSaturation() { return 0.5; }
    static qreal grayscaleSaturation() { return 0.0; }
    static qreal minColorLightness() { return 0.4; }
    static qreal maxColorLightness() { return 0.8; }
    static qreal minGrayLightness() { return 0.3; }
    static qreal maxGrayLightness() { return 0.9; }
};

#endif // IDENTICONSTYLE_H
