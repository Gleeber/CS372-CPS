//
// Created by Andrew Adler on 2019-04-01.
//

#include "shape.h"
#include "CompoundShape.h"

#include <cmath>
using std::sin;
using std::cos;
#include <algorithm>
using std::max;

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
           + _shape.generatePostScript()
           + to_string(- _rotation) + " rotate\n";
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
    return "gsave\n"
           + to_string(_scaleFactorX) + " "
           + to_string(_scaleFactorY) + " scale\n"

           + _shape.generatePostScript()

           + "grestore\n";
}

// *********************************************************************
// CompoundShape class definitions
// *********************************************************************

string CompoundShape::generatePostScript() const
{
    string postscriptOutput;
    postscriptOutput += moveToStartPosition();

    for (auto eachShapeReference : _shapeReferences)
    {
        const Shape & eachShape = eachShapeReference.get();

        postscriptOutput += moveByShape(eachShape);

        postscriptOutput += "gsave\n"
                            + eachShape.generatePostScript();

        postscriptOutput += "grestore\n\n";

        postscriptOutput += moveByShape(eachShape);

        postscriptOutput += "\n";
    }
    return postscriptOutput;
}

string CompoundShape::moveByShape(Shape shapeToMoveBy) const
{
    return "";
}

string CompoundShape::moveToStartPosition() const
{
    return "";
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

string Vertical::moveByShape(Shape shapeToMoveBy) const
{
    return "0 "
           + to_string(shapeToMoveBy.getHeight() / 2) + " "
           + "translate\n";
}

string Vertical::moveToStartPosition() const
{
    return "0 "
           + to_string( - getHeight() / 2) + " "
           + "translate\n";;
}

// *********************************************************************
// Horizontal class definitions
// *********************************************************************

void Horizontal::updateWidthAndHeight()
{
    double width = 0, height = 0;
    for (auto eachShapeReference : _shapeReferences)
    {
        const Shape & eachShape = eachShapeReference.get();
        height = max(height, eachShape.getHeight());
        width += eachShape.getWidth();
    }

    setWidth(width);
    setHeight(height);
}

string Horizontal::moveByShape(Shape shapeToMoveBy) const
{
    return to_string(shapeToMoveBy.getWidth() / 2) + " "
           + "0 "
           + "translate\n";
}

string Horizontal::moveToStartPosition() const
{
    return to_string( - getWidth() / 2) + " "
           + "0 "
           + "translate\n";
}
