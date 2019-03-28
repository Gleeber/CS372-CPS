//
// Created by Ian Ferguson on 2019-03-26.
//

#include "shape.h"

// ****************************** Shape Class ******************************

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

void Shape::setCenter(int x, int y)
{
    _center=std::make_pair(x, y);
}



// ****************************** Circle Class ******************************

Circle::Circle():
    _radius(getHeight() / 2)
{}

int Circle::getRadius()
{
    return _radius;
}

// ****************************** Rectangle Class ******************************

Rectangle::Rectangle()
{}

