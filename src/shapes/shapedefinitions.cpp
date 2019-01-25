#include "shapedefinitions.h"
namespace shapes {

void(*ShapeDefinitions::outerShapes_[4])(rendering::Renderer &, int , int ) =
{
    &ShapeDefinitions::outerOne,
    &ShapeDefinitions::outerTwo,
    &ShapeDefinitions::outerThree,
    &ShapeDefinitions::outerFour
};

void(*ShapeDefinitions::centerShapes_[14])(rendering::Renderer &, int , int ) =
{
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
    &ShapeDefinitions::centerFourteen
};


QList<void(*)(rendering::Renderer &, int , int )>
ShapeDefinitions::CenterShapes()
{
    return  QList<void(*)(rendering::Renderer&,int,int)>::fromStdList(std::list<void(*)(rendering::Renderer &, int , int )>(centerShapes_,centerShapes_ + sizeof(centerShapes_) / sizeof(void*))) ;
}

QList<void(*)(rendering::Renderer &, int , int )>
ShapeDefinitions::OuterShapes()
{
    return  QList<void(*)(rendering::Renderer&,int,int)>::fromStdList(std::list<void(*)(rendering::Renderer &, int , int )>(outerShapes_,outerShapes_ + sizeof(outerShapes_) / sizeof(void*))) ;
}
}
