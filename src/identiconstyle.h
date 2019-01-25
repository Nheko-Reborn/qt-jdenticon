#ifndef IDENTICONSTYLE_H
#define IDENTICONSTYLE_H

#include <QList>
#include <QColor>

class IdenticonStyle
{
private:
    QList<qreal> hues_;
    QColor backColor_ = QColor(0,0,0,0);
    qreal padding_ = 0.08;
    qreal colorSaturation_ = 0.5;
    qreal grayscaleSaturation_ = 0.0;
    qreal minColorLightness_ = 0.4;
    qreal maxColorLightness_ = 0.8;
    qreal minGrayLightness_ = 0.3;
    qreal maxGrayLightness_ = 0.9;
public:
    IdenticonStyle();
    IdenticonStyle(IdenticonStyle &other);
    QList<qreal> hues() { return hues_; }
    QColor backCol() { return backColor_; }
    qreal padding() { return padding_; }
    qreal colorSaturation() { return colorSaturation_; }
    qreal grayscaleSaturation() { return grayscaleSaturation_; }
    qreal minColorLightness() { return minColorLightness_; }
    qreal maxColorLightness() { return maxColorLightness_; }
    qreal minGrayLightness() { return minGrayLightness_; }
    qreal maxGrayLightness() { return maxGrayLightness_; }
    void setHues(QList<qreal> &hues);
    void setBackCol(QColor &color);
    void setPadding(qreal padding);
    void setColorSaturation(qreal saturation);
    void setGrayscaleSaturation(qreal saturation);
    void setMinColorLightness(qreal lightness);
    void setMaxColorLightness(qreal lightness);
    void setMinGrayLightness(qreal lightness);
    void setMaxGrayLightness(qreal lightness);
};

#endif // IDENTICONSTYLE_H
