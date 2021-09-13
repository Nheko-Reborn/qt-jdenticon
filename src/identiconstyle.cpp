#include "identiconstyle.h"

IdenticonStyle::IdenticonStyle() {}

IdenticonStyle::IdenticonStyle(IdenticonStyle &other)
{
    hues_                = other.hues();
    backColor_           = other.backCol();
    padding_             = other.padding();
    colorSaturation_     = other.colorSaturation();
    grayscaleSaturation_ = other.grayscaleSaturation();
    minColorLightness_   = other.minColorLightness();
    maxColorLightness_   = other.maxColorLightness();
    minGrayLightness_    = other.minGrayLightness();
    maxGrayLightness_    = other.maxGrayLightness();
}

void
IdenticonStyle::setHues(QList<qreal> &hues)
{
    hues_ = hues;
}
void
IdenticonStyle::setBackCol(QColor &color)
{
    backColor_ = color;
}
void
IdenticonStyle::setPadding(qreal padding)
{
    if (padding < 0.0 || padding > 0.4) {
        throw new std::out_of_range("Only padding values in the range [0.0, 0.4] are valid.");
    }
    padding_ = padding;
}
void
IdenticonStyle::setColorSaturation(qreal saturation)
{
    if (saturation < 0 || saturation > 1) {
        throw new std::out_of_range("Only saturation values in the range [0.0, 1.0] are allowed.");
    }

    colorSaturation_ = saturation;
}
void
IdenticonStyle::setGrayscaleSaturation(qreal saturation)
{
    if (saturation < 0 || saturation > 1) {
        throw new std::out_of_range("Only saturation values in the range [0.0, 1.0] are allowed.");
    }

    grayscaleSaturation_ = saturation;
}
void
IdenticonStyle::setMinColorLightness(qreal lightness)
{
    if (lightness < 0.0) {
        throw new std::out_of_range("Only lightness values between [0.0, 1.0] are allowed.");
    }

    minColorLightness_ = lightness;
}
void
IdenticonStyle::setMaxColorLightness(qreal lightness)
{
    if (lightness > 1.0) {
        throw new std::out_of_range("Only lightness values between [0.0, 1.0] are allowed.");
    }

    maxColorLightness_ = lightness;
}
void
IdenticonStyle::setMinGrayLightness(qreal lightness)
{
    if (lightness < 0.0) {
        throw new std::out_of_range("Only lightness values between [0.0, 1.0] are allowed.");
    }

    minGrayLightness_ = lightness;
}
void
IdenticonStyle::setMaxGrayLightness(qreal lightness)
{
    if (lightness > 1.0) {
        throw new std::out_of_range("Only lightness values between [0.0, 1.0] are allowed.");
    }

    maxGrayLightness_ = lightness;
}
