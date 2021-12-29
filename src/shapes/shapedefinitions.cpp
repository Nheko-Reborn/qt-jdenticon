#include "shapedefinitions.h"

#include <array>

namespace shapes {

const QVector<void (*)(rendering::Renderer &, int, int)> &
ShapeDefinitions::CenterShapes()
{
    static QVector<void (*)(rendering::Renderer &, int, int)> v{
      &ShapeDefinitions::centerOne,
      &ShapeDefinitions::centerTwo,
      &ShapeDefinitions::centerThree,
      &ShapeDefinitions::centerFour,
      &ShapeDefinitions::centerFive,
      &ShapeDefinitions::centerSix,
      &ShapeDefinitions::centerSeven,
      &ShapeDefinitions::centerEight,
      &ShapeDefinitions::centerNine,
      &ShapeDefinitions::centerTen,
      &ShapeDefinitions::centerEleven,
      &ShapeDefinitions::centerTwelve,
      &ShapeDefinitions::centerThirteen,
      &ShapeDefinitions::centerFourteen,
    };
    return v;
}

const QVector<void (*)(rendering::Renderer &, int, int)> &
ShapeDefinitions::OuterShapes()
{
    static QVector<void (*)(rendering::Renderer &, int, int)> v{
      &ShapeDefinitions::outerOne,
      &ShapeDefinitions::outerTwo,
      &ShapeDefinitions::outerThree,
      &ShapeDefinitions::outerFour,
    };
    return v;
}
}
