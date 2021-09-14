#include "shapedefinitions.h"

#include <array>

namespace shapes {

QList<void (*)(rendering::Renderer &, int, int)>
ShapeDefinitions::CenterShapes()
{
    return QList<void (*)(rendering::Renderer &, int, int)>{
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
}

QList<void (*)(rendering::Renderer &, int, int)>
ShapeDefinitions::OuterShapes()
{
    return QList<void (*)(rendering::Renderer &, int, int)>{
      &ShapeDefinitions::outerOne,
      &ShapeDefinitions::outerTwo,
      &ShapeDefinitions::outerThree,
      &ShapeDefinitions::outerFour,
    };
}
}
