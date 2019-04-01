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

string Shape::generatePostScript() const
{
    return "Nothing to generate";
}

void Shape::draw()
{
    ofstream postScriptOutput;
    postScriptOutput.open (_filename);
    postScriptOutput << "newpath\n"
                        + to_string(getCenter().first) + " "
                        + to_string(getCenter().second) + " "
                        + "moveto\n";
    postScriptOutput << generatePostScript();
    postScriptOutput << "stroke\n\nshowpage";
    postScriptOutput.close();
}

string Shape::getFilename() const
{
    return _filename;
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

string Circle::generatePostScript() const
{
    return  std::to_string(getCenter().first) + " " +
            std::to_string(getCenter().second) + " " +
            std::to_string(getRadius()) + " " +
            "0 360 arc\n";
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
    return  "-" + std::to_string(getWidth()/2)
            + " -" + std::to_string(getHeight()/2) + " rmoveto\n"

            + std::to_string(getWidth()) + " 0 rlineto\n"
            + "0 " + std::to_string(getHeight()) + " rlineto\n"
            + "-" + std::to_string(getWidth()) + " 0 rlineto\n"
            + "0 -" + std::to_string(getHeight()) + " rlineto\n";
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
    return + "-" + std::to_string(getWidth() / 2)
           + " -" + std::to_string(getHeight() / 2) + " rmoveto\n"

           + to_string((getWidth() - _sideLength) / 2) + " 0 rmoveto\n"

           + "1 1 " + to_string(_numberOfSides) + " {\n"
           + to_string(_sideLength) + " 0 rlineto\n"
           + to_string(360 / _numberOfSides) + " rotate\n"
           + "} for\n";
}

// *********************************************************************
// Triangle class definitions
// *********************************************************************

Triangle::Triangle(double sideLength):Polygon(3, sideLength) {}

// *********************************************************************
// Square class definitions
// *********************************************************************

Square::Square(double sidelength): Polygon(4, sidelength){}

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
// Rotated class definitions
// *********************************************************************

Rotated::Rotated(const Shape &shape, int rotationAngle): _shape(shape), _rotation(rotationAngle)
{
    if(rotationAngle == 0 || rotationAngle == 180)
    {
        setWidth(_shape.getWidth());
        setHeight(_shape.getHeight());
    }
    else //Rotation angle is 90 or 270
    {
        setWidth(_shape.getHeight());
        setHeight(_shape.getWidth());
    }

}

string Rotated::generatePostScript() const
{
    return to_string(_rotation) + " rotate\n"
           + _shape.generatePostScript();
}

// *********************************************************************
// Scaled class definitions
// *********************************************************************

Scaled::Scaled(const Shape &shape, double fx, double fy) :_shape(shape), _scaleFactorX(fx), _scaleFactorY(fy)
{
    setWidth(_shape.getWidth()*fx);
    setHeight(_shape.getHeight()*fy);
}

string Scaled::generatePostScript() const
{
    return to_string(_scaleFactorX) + " "
           + to_string(_scaleFactorY) + " scale\n"
           + _shape.generatePostScript();
}

// *********************************************************************
// Layered class definitions
// *********************************************************************

void Layered::updateWidthAndHeight()
{
    double maxWidth = 0, maxHeight = 0;
    for (auto eachShapeReference : _shapeReferences)
    {
        const Shape & eachShape = eachShapeReference.get();
        maxWidth = max(maxWidth, eachShape.getWidth());
        maxHeight = max(maxHeight, eachShape.getHeight());
    }

    setWidth(maxWidth);
    setHeight(maxHeight);
}

string Layered::generatePostScript() const 
{
    string postscriptOutput = "";
    for (auto eachShapeReference : _shapeReferences)
    {
        postscriptOutput += "newpath\n"
                         + to_string(getCenter().first) + " "
                         + to_string(getCenter().second) + " "
                         + "moveto\n";
        const Shape & eachShape = eachShapeReference.get();
        postscriptOutput += eachShape.generatePostScript() += "stroke\n\n";
    }
    return postscriptOutput;
}

// *********************************************************************
// Vertical class definitions
// *********************************************************************

void Vertical::updateWidthAndHeight()
{
    double width = 0, height = 0;
    for (auto eachShapeReference : _shapeReferences)
    {
        const Shape & eachShape = eachShapeReference.get();
        width = max(width, eachShape.getWidth());
        height += eachShape.getHeight();
    }

    setWidth(width);
    setHeight(height);
}

string Vertical::generatePostScript() const
{
    string postscriptOutput = "";
    postscriptOutput += to_string(getCenter().first - getWidth() / 2) + " "
                      + to_string(getCenter().second - getHeight() / 2) + " "
                      + "moveto\n";

    for (auto eachShapeReference : _shapeReferences)
    {
        const Shape & eachShape = eachShapeReference.get();
        postscriptOutput += to_string(getWidth() / 2) + " "
                          + to_string(eachShape.getHeight() / 2) + " "
                          + "rmoveto\n";

        postscriptOutput += eachShape.generatePostScript();

        postscriptOutput += to_string((eachShape.getWidth() - getWidth()) / 2) + " "
                          + to_string(eachShape.getHeight()) + " "
                          + "rmoveto\n"
                          + "\n";
    }

    postscriptOutput += "stroke\n";
    return postscriptOutput;
}

// *********************************************************************
// Horizontal class definitions
// *********************************************************************

void Horizontal::updateWidthAndHeight()
{

}

string Horizontal::generatePostScript() const
{
    return "";
}
