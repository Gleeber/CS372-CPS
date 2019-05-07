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
// CompoundShape class
// *********************************************************************

class CompoundShape : public Shape
{
public:
    string generatePostScript() const override;

    virtual string moveByShape(Shape shapeToMoveBy) const;
    virtual string moveToStartPosition() const;

protected:
    vector<reference_wrapper<const Shape>> _shapeReferences;

private:
};

// *********************************************************************
// Layered class
// *********************************************************************

class Layered : public CompoundShape
{
public:
    template <typename Arg, typename... Ts,
            typename enable_if<is_base_of<Shape,Arg>::value>::type * = nullptr>
    explicit Layered(Arg &i, Ts &... all)
    {
        _shapeReferences = {i, all... };
        updateWidthAndHeight();
    }

    void updateWidthAndHeight();

    //virtual string generatePostScript() const override;
    //string translate(double lengthToTranslate) const override;
    //string generatePostScript() const override;

private:
};

// *********************************************************************
// Vertical class
// *********************************************************************

class Vertical : public CompoundShape
{
public:
    template <typename Arg, typename... Ts,
            typename enable_if<is_base_of<Shape,Arg>::value>::type * = nullptr>
    explicit Vertical(Arg &i, Ts &... all)
    {
        _shapeReferences = {i, all... };
        updateWidthAndHeight();
    }

    void updateWidthAndHeight();

    string moveByShape(Shape shapeToMoveBy) const override;
    string moveToStartPosition() const override;
    //string generatePostScript() const override;

private:
};

// *********************************************************************
// Horizontal class
// *********************************************************************

class Horizontal : public CompoundShape
{
public:
    template <typename Arg, typename... Ts,
            typename enable_if<is_base_of<Shape,Arg>::value>::type * = nullptr>
    explicit Horizontal(Arg &i, Ts &... all)
    {
        _shapeReferences = {i, all... };
        updateWidthAndHeight();
    }

    void updateWidthAndHeight();

    string moveByShape(Shape shapeToMoveBy) const override;
    string moveToStartPosition() const override;
    //string generatePostScript() const override;

private:
};

#endif //CPS_COMPOUNDSHAPE_H
