//
// Created by Andrew Adler on 2019-04-01.
//

#ifndef CPS_COMPOUNDSHAPE_H
#define CPS_COMPOUNDSHAPE_H

#include "shape.h"


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
