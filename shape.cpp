//
// Created by Ian Ferguson on 2019-03-26.
//

#include "shape.h"

Shape::Shape():
    _center(306, 396), _height(72), _width(72)
{}

pair<int, int> Shape::getCenter()
{
    return _center;
}

int Shape::getHeight()
{
    return _height;
}

int Shape::getWidth()
{
    return _width;
}
