#ifndef COLORTHEME_H
#define COLORTHEME_H

#include <QColor>

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
    ColorTheme(qreal hue);
    int count() const { return 5; }
    QColor operator[](int index) const;
};

} // namespace rendering

#endif // COLORTHEME_H
