//
// Created by Ian Ferguson on 2019-03-26.
//

#include "shape.h"

// ****************************** Shape Class ******************************

Shape::Shape():
    _center(306, 396), _height(72), _width(72)
{}

pair<double, double> Shape::getCenter()
{
    return _center;
}

double Shape::getHeight()
{
    return _height;
}

double Shape::getWidth()
{
    return _width;
}

void Shape::setCenter(double x, double y)
{
    _center=std::make_pair(x, y);
}

void Shape::setHeight(double num)
{
    _height = num;
}

void Shape::setWidth(double num)
{
    _width = num;
}


// ****************************** Circle Class ******************************

Circle::Circle():
    _radius(getHeight() / 2)
{}

double Circle::getRadius()
{
    return _radius;
}

// ****************************** Rectangle Class ******************************

Rectangle::Rectangle()
{}

