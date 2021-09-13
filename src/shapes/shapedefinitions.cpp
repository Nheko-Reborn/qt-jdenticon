#include "shapedefinitions.h"

#include <array>

namespace shapes {
static QList<void (*)(rendering::Renderer &, int, int)> outerShapes_{
  &ShapeDefinitions::outerOne,
  &ShapeDefinitions::outerTwo,
  &ShapeDefinitions::outerThree,
  &ShapeDefinitions::outerFour,
};

static QList<void (*)(rendering::Renderer &, int, int)> centerShapes_{
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

QList<void (*)(rendering::Renderer &, int, int)>
ShapeDefinitions::CenterShapes()
{
    return outerShapes_;
}

QList<void (*)(rendering::Renderer &, int, int)>
ShapeDefinitions::OuterShapes()
{
    return centerShapes_;
}
}
