//
// Created by Andrew Adler on 2019-04-01.
//

#ifndef CPS_COMPOUNDSHAPE_H
#define CPS_COMPOUNDSHAPE_H

#include "shape.h"


// *********************************************************************
// Rotated class
// *********************************************************************

class Rotated : public Shape
{
public:
    Rotated(const Shape &shape, int rotationAngle);

    //virtual string generatePostScript() const override;
    string generatePostScript() const override;

private:
    const Shape & _shape;
    int _rotation;
};

// *********************************************************************
// Scaled class
// *********************************************************************

class Scaled: public Shape
{
public:
    Scaled(const Shape &shape, double fx, double fy);

    string generatePostScript() const override;

private:
    double _scaleFactorX;
    double _scaleFactorY;
    const Shape & _shape;
};

// *********************************************************************
// Layered class
// *********************************************************************

class MultipleShapes : public Shape
{
public:
    template <typename Arg, typename... Ts,
            typename enable_if<is_base_of<Shape,Arg>::value>::type * = nullptr>
    explicit MultipleShapes(Arg &i, Ts &... all, string multipleType)
    {
        _shapeReferences = {i, all... };
        updateWidthAndHeight();
    }

    void updateWidthAndHeight();

    //virtual string generatePostScript() const override;
    string generatePostScript() const override;

private:
    vector<reference_wrapper<const Shape>> _shapeReferences;
    string multipleType;
};

// *********************************************************************
// Vertical class
// *********************************************************************



#endif //CPS_COMPOUNDSHAPE_H
