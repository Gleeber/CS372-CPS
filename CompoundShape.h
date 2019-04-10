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
    virtual string generatePostScript() const override;

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

    virtual string generatePostScript() const override;

private:
    double _scaleFactorX;
    double _scaleFactorY;
    const Shape & _shape;
};

// *********************************************************************
// Layered class
// *********************************************************************

class Layered : public Shape
{
public:
    template <typename Arg, typename... Ts,
            typename enable_if<is_base_of<Shape,Arg>::value>::type * = nullptr>
    Layered(Arg &i, Ts &... all)
    {
        _shapeReferences = {i, all... };
        updateWidthAndHeight();
    }

    void updateWidthAndHeight();

    //virtual string generatePostScript() const override;
    virtual string generatePostScript() const override;

private:
    vector<reference_wrapper<const Shape>> _shapeReferences;
};

// *********************************************************************
// Vertical class
// *********************************************************************

class Vertical : public Shape
{
public:
    template <typename Arg, typename... Ts,
            typename enable_if<is_base_of<Shape,Arg>::value>::type * = nullptr>
    Vertical(Arg &i, Ts &... all)
    {
        _shapeReferences = {i, all... };
        updateWidthAndHeight();
    }

    void updateWidthAndHeight();

    virtual string generatePostScript() const override;

private:
    vector<reference_wrapper<const Shape>> _shapeReferences;
};

// *********************************************************************
// Horizontal class
// *********************************************************************

class Horizontal : public Shape
{
public:
    template <typename Arg, typename... Ts,
            typename enable_if<is_base_of<Shape,Arg>::value>::type * = nullptr>
    Horizontal(Arg &i, Ts &... all)
    {
        _shapeReferences = {i, all... };
        updateWidthAndHeight();
    }

    void updateWidthAndHeight();

    virtual string generatePostScript() const override;

private:
    vector<reference_wrapper<const Shape>> _shapeReferences;
};

#endif //CPS_COMPOUNDSHAPE_H
