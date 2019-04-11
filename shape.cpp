#include <utility>

//
// Created by Ian Ferguson on 2019-03-26.
//

#include "shape.h"

#include <iostream>
using std::ofstream;
#include <cmath>
using std::sin;
using std::cos;
#include <algorithm>
using std::max;

// *********************************************************************
// Shape class definitions
// *********************************************************************

Shape::Shape():
    _center(306, 396), _height(72), _width(72), _filename("postScriptFile.ps")
{}

// Getters for Shape

    pair<double, double> Shape::getCenter() const
    {
        return _center;
    }

    double Shape::getHeight() const
    {
        return _height;
    }

    double Shape::getWidth() const
    {
        return _width;
    }

// Setters for Shape

    void Shape::setHeight(double num)
    {
        _height = num;
    }

    void Shape::setWidth(double num)
    {
        _width = num;
    }

    void Shape::setCenter(double x, double y)
    {
        _center=std::make_pair(x, y);
    }


// Other base Shape functions

    string Shape::generatePostScript() const
    {
        return "Nothing to generate\n";
    }

    void Shape::draw()
    {
        ofstream postScriptOutput;
        postScriptOutput.open (_filename);
        postScriptOutput << to_string(getCenter().first) + " "
                            + to_string(getCenter().second) + " "
                            + "translate\n\n";
        postScriptOutput << generatePostScript();
        postScriptOutput << "\nshowpage";
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

double Circle::getRadius() const
{
    return _radius;
}

/*
string Circle::generatePostScript() const
{
    return  generatePostScript(getCenter().first, getCenter().second);
}
 */

string Circle::generatePostScript() const
{
    return "0 0 "
           + std::to_string(getRadius()) + " "
           + "0 360 arc\n"
           + "stroke\n";
}

// *********************************************************************
// Rectangle class definitions
// *********************************************************************

Rectangle::Rectangle()
{
    setWidth(getWidth() * 2);
}

Rectangle::Rectangle(double width, double height)
{
    setWidth(width);
    setHeight(height);
}

string Rectangle::generatePostScript() const
{
    return "newpath\n"

           + std::to_string(-getWidth()/2) + " "
           + std::to_string(-getHeight()/2) + " "
           + "moveto\n"

           + std::to_string(getWidth()) + " 0 rlineto\n"
           + "0 " + std::to_string(getHeight()) + " rlineto\n"
           + "-" + std::to_string(getWidth()) + " 0 rlineto\n"
           + "0 -" + std::to_string(getHeight()) + " rlineto\n"

           + "closepath\n"
           + "stroke\n";
}

// *********************************************************************
// Polygon class definitions
// *********************************************************************

Polygon::Polygon():
    _numberOfSides(5), _sideLength(50)
{
    updateHeightAndWidth();
}

Polygon::Polygon(int numberOfSides, double sideLength):
    _numberOfSides(numberOfSides), _sideLength(sideLength)
{
    updateHeightAndWidth();
}

void Polygon::updateHeightAndWidth()
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

    else  //case 3: n is divisible by 2, but not 4.
    {
        setHeight(_sideLength*(cos(M_PI/ _numberOfSides)) / (sin(M_PI/_numberOfSides)));
        setWidth(_sideLength/(sin(M_PI/_numberOfSides)));
    }
}

int Polygon::getNumSides() const
{
    return _numberOfSides;
}

double Polygon::getSideLength() const
{
    return _sideLength;
}

string Polygon::generatePostScript() const
{
    return "newpath\n"
           + std::to_string( - _sideLength / 2) + " "
           + std::to_string(- getHeight() / 2) + " moveto\n"

           + "1 1 " + to_string(_numberOfSides) + " {\n"
           + to_string(_sideLength) + " 0 rlineto\n"
           + to_string(360.0 / _numberOfSides) + " rotate\n"
           + "} for\n"
           + "clear\n"

           + "closepath\n"
           + "stroke\n";
}

// *********************************************************************
// Triangle class definitions
// *********************************************************************

Triangle::Triangle(double sideLength)
    :Polygon(3, sideLength)
{}

// *********************************************************************
// Square class definitions
// *********************************************************************

Square::Square(double sideLength)
    : Polygon(4, sideLength)
{}

// *********************************************************************
// Spacer class definitions
// *********************************************************************

Spacer::Spacer(double width, double height)
{
    setWidth(width);
    setHeight(height);
}

string Spacer::generatePostScript() const
{
    return "";
}

// *********************************************************************
// Spacer class definitions
// *********************************************************************

Asterisk::Asterisk(int numberOfArms, double armLength):
    _numberOfArms(numberOfArms), _armLength(armLength),
    _innerShape(Polygon(numberOfArms,armLength * 2/3))
{
    double height = 0, width = 0;
    if (_numberOfArms % 2 != 0) //Case 1: n is odd.
    {
        height = _innerShape.getHeight() + _armLength
               + _armLength * (cos(M_PI / _numberOfArms));
        if (_numberOfArms > 3)
        {
            width = _innerShape.getWidth()
                    + 2 * _armLength * cos(M_PI / 180 * (90.0 - (floor(_numberOfArms / 4.0)) * (360.0 / _numberOfArms)));
        }

        else
        {
            width = _innerShape.getWidth()
                    + 2 * _armLength * cos(M_PI / 180 * (90.0 - (180.0 / _numberOfArms)));
        }

    }

    else if (_numberOfArms % 4 == 0) // Case 2: n is divisible by 4.
    {
        height = _innerShape.getHeight() + 2 * _armLength;
        width = _innerShape.getWidth() + 2 * _armLength;
    }

    else  //case 3: n is divisible by 2, but not 4.
    {
        height = _innerShape.getHeight() + 2 * _armLength;
        width = _innerShape.getWidth()
              + 2 * _armLength * cos(M_PI / _numberOfArms);
    }

    setHeight(height);
    setWidth(width);
}

string Asterisk::generatePostScript() const
{
    string outputString;
    outputString += "newpath\n";

    if (_numberOfArms % 2 != 2)
    {
        outputString += "180 rotate\n";
    }

    outputString += std::to_string( -_innerShape.getSideLength() / 2) + " "
           + std::to_string(- (getHeight() / 2 - _armLength)) + " "
           + "moveto\n"

           + "0 1 " + to_string(_numberOfArms) + " { \n"
           + "    0 " + to_string(-_armLength) + " rlineto\n"
           + "    " + to_string( _armLength * 2.0 / 3.0) + " 0 rlineto\n"
           + "    0 " + to_string(_armLength) + " rlineto\n"

           + "    " + to_string(360.0 / _numberOfArms) + " rotate\n"
           + "} for\n"
           + "clear\n"
           + "stroke\n";

    return outputString;
}

const Polygon & Asterisk::getInnerShape()
{
    return _innerShape;
}
