//
// Created by Ian Ferguson on 2019-03-26.
//

#include "shape.h"
#include <iostream>
using std::ofstream;
#include <cmath>
using std::sin;
using std::cos;

// *********************************************************************
// Shape class definitions
// *********************************************************************

Shape::Shape():
    _center(306, 396), _height(72), _width(72), _filename("../CS372-CPS/postScriptFile.ps")
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

void Shape::openfile(const char *filename)
{
    file.open(filename);
}

void Shape::closefile()
{
    file.close();
}

string Shape::generatePostScript()
{
    return std::string();
}

void Shape::draw()
{
    ofstream postScriptOutput;
    postScriptOutput.open (_filename);
    postScriptOutput << generatePostScript();
    postScriptOutput.close();
}

// *********************************************************************
// Circle class definitions
// *********************************************************************

Circle::Circle():
    _radius(getHeight() / 2)
{}

Circle::Circle(double radius):
    _radius(radius)
{
    setHeight(_radius * 2);
    setWidth( _radius * 2);
}

double Circle::getRadius()
{
    return _radius;
}

string Circle::generatePostScript()
{
    return "newpath\n" +
            std::to_string(getCenter().first) + " " +
            std::to_string(getCenter().second) + " " +
            std::to_string(getRadius()) + " " +
            "0 360 arc\n" "stroke";
}

// *********************************************************************
// Rectangle class definitions
// *********************************************************************

Rectangle::Rectangle()
{
    setWidth(getWidth() * 2);
}

// *********************************************************************
// Polygon class definitions
// *********************************************************************

Polygon::Polygon():
    _numberOfSides(5), _sideLength(50)
{
    if (_numberOfSides % 2 != 0) //Case 1: n is odd.
    {
        setHeight(_sideLength * (1 + cos(M_PI / _numberOfSides)) / (2 * sin(M_PI / _numberOfSides)));
        setWidth(_sideLength * sin(M_PI * (_numberOfSides - 1) / (2 * _numberOfSides)) / sin(M_PI / _numberOfSides));
    }

    else if (_numberOfSides % 4 == 0) // Case 2: n is divisible by 4.
    {
        setHeight(_sideLength * cos(M_PI / _numberOfSides) / sin(M_PI / _numberOfSides));
        setWidth(_sideLength * cos(M_PI / _numberOfSides) / sin(M_PI / _numberOfSides));
    }

    /*
    Case 3: n is divisible by 2, but not by 4.
    height = e(cos(π/n))/(sin(π/n))
    width = e/(sin(π/n))
     */

}

int Polygon::getNumSides()
{
    return _numberOfSides;
}
