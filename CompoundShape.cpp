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
        const Shape & eachShape = eachShapeReference.get();

        /*
        postscriptOutput += to_string(getCenter().first) + " "
                            + to_string(getCenter().second) + " "
                            + "rmoveto\n";
                            */

        postscriptOutput += eachShape.generatePostScript() += "\n";

        postscriptOutput += to_string(eachShape.getWidth() / 2) + " "
                            + to_string(eachShape.getHeight() / 2) + " "
                            + "rmoveto\n";
    }

    postscriptOutput += to_string(- getWidth() / 2) + " "
                        + to_string(- getHeight() / 2) + " "
                        + "rmoveto\n";
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
    postscriptOutput += to_string( - getWidth() / 2) + " "
                        + to_string( - getHeight() / 2) + " "
                        + "rmoveto\n";

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

    postscriptOutput += "0 "
                        + to_string(- getHeight()) + " "
                        + "rmoveto\n";

    return postscriptOutput;
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

string Horizontal::generatePostScript() const
{
    string postscriptOutput = "";
    postscriptOutput += to_string(- getWidth() / 2) + " "
                        + to_string(- getHeight() / 2) + " "
                        + "rmoveto\n";

    for (auto eachShapeReference : _shapeReferences)
    {
        const Shape & eachShape = eachShapeReference.get();
        postscriptOutput += to_string(eachShape.getWidth() / 2) + " "
                            + to_string(getHeight() / 2) + " "
                            + "rmoveto\n";

        postscriptOutput += eachShape.generatePostScript();

        postscriptOutput += to_string(eachShape.getWidth()) + " "
                            + to_string((eachShape.getHeight() - getHeight()) / 2) + " "
                            + "rmoveto\n"
                            + "\n";
    }

    postscriptOutput += to_string(- getWidth()) + " "
                        + "0 "
                        + "rmoveto\n";
    return postscriptOutput;
}