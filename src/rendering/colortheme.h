#ifndef COLORTHEME_H
#define COLORTHEME_H

#include <QColor>

#include "../identiconstyle.h"
#include "colorutils.h"

namespace rendering {

class ColorTheme
{
private:
    QColor darkGray_;
    QColor darkColor_;
    QColor midGray_;
    QColor midColor_;
    QColor lightGray_;
    QColor lightColor_;

public:
    ColorTheme(qreal hue, IdenticonStyle &style);
    int count() { return 5; }
    QColor &operator[](int index);
};

} // namespace rendering

#endif // COLORTHEME_H
