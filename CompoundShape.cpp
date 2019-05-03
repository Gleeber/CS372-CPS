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

/*
string Rotated::generatePostScript() const
{
    return "newpath\n"
           + to_string(getCenter().first) + " "
           + to_string(getCenter().second) + " "
           + "moveto\n"
           + generatePostScript()
           + "closepath\n"
           + "stroke\n";
}
 */

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
// Layered class definitions
// *********************************************************************

void MultipleShapes::updateWidthAndHeight()
{
    double width = 0, height = 0;
    if (multipleType == "Layered") {
        for (auto eachShapeReference : _shapeReferences) {
            const Shape &eachShape = eachShapeReference.get();
            width = max(width, eachShape.getWidth());
            height = max(height, eachShape.getHeight());
        }
    }
    if(multipleType == "Vertical"){
        for (auto eachShapeReference : _shapeReferences)
        {
            const Shape & eachShape = eachShapeReference.get();
            width = max(width, eachShape.getWidth());
            height += eachShape.getHeight();
        }
    }
    if(multipleType == "Horizontal"){
        for (auto eachShapeReference : _shapeReferences)
        {
            const Shape & eachShape = eachShapeReference.get();
            height = max(height, eachShape.getHeight());
            width += eachShape.getWidth();
        }
    }
    setWidth(width);
    setHeight(height);
}

/*
string Layered::generatePostScript() const
{
    return generatePostScript();
}
 */

string MultipleShapes::generatePostScript() const
{
    string postscriptOutput;
    if(multipleType == "Layered") {
        for (auto eachShapeReference : _shapeReferences) {
            const Shape &eachShape = eachShapeReference.get();
            postscriptOutput += "gsave\n"
                                + eachShape.generatePostScript();
            postscriptOutput += "grestore\n\n";
        }
    }
    if(multipleType=="Vertical"){
        postscriptOutput += "0 "
                            + to_string( - getHeight() / 2) + " "
                            + "translate\n";
        for (auto eachShapeReference : _shapeReferences)
        {
            const Shape & eachShape = eachShapeReference.get();
            postscriptOutput += "0 "
                                + to_string(eachShape.getHeight() / 2) + " "
                                + "translate\n";
            postscriptOutput += "gsave\n"
                                + eachShape.generatePostScript();
            postscriptOutput += "grestore\n\n";
            postscriptOutput += "0 "
                                + to_string(eachShape.getHeight() / 2) + " "
                                + "translate\n"
                                + "\n";
        }
    }
    if(multipleType=="Horizontal"){
        postscriptOutput += to_string( - getWidth() / 2) + " "
                            + "0 "
                            + "translate\n";
        for (auto eachShapeReference : _shapeReferences)
        {
            const Shape & eachShape = eachShapeReference.get();
            postscriptOutput += to_string(eachShape.getWidth() / 2) + " "
                                + "0 "
                                + "translate\n";
            postscriptOutput += "gsave\n"
                                + eachShape.generatePostScript();
            postscriptOutput += "grestore\n\n";
            postscriptOutput += to_string(eachShape.getWidth() / 2) + " "
                                + "0 "
                                + "translate\n"
                                + "\n";
        }
    }
    return postscriptOutput;
}
