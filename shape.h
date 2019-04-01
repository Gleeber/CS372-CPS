//
// Created by Ian Ferguson on 2019-03-26.
//

#ifndef CS372_CPS_SHAPE_H
#define CS372_CPS_SHAPE_H

#include <iostream>
#include <fstream>
#include <utility>
using std::pair;
#include <string>
using std::string;
using std::to_string;
#include <vector>
using std::vector;
#include <functional>
using std::reference_wrapper;
#include <cstdarg>


#include <type_traits>
using std::is_base_of;
using std::enable_if;

// *********************************************************************
// Shape class
// *********************************************************************

class Shape
{
public:
    Shape();

    pair<double, double> getCenter() const;
    double getHeight() const;
    double getWidth() const;

    void setHeight(double num);
    void setWidth(double num);
    void setCenter(double x, double y);

    virtual string generatePostScript() const;
    void draw();

protected:
    std::ofstream file;

private:
    pair<double, double> _center;
    double _height;
    double _width;
    string _filename;
};


// *********************************************************************
// Circle class
// *********************************************************************

class Circle : public Shape
{
public:
    Circle();
    Circle(double radius);

    double getRadius() const;

    virtual string generatePostScript() const override;

private:
    double _radius;
};

// *********************************************************************
// Rectangle class
// *********************************************************************

class Rectangle : public Shape
{
public:
    Rectangle();
    Rectangle(double width, double height);

    virtual string generatePostScript() const override;

private:

};

// *********************************************************************
// Polygon class
// *********************************************************************

class Polygon : public Shape
{
public:
    Polygon();
    Polygon(int numberOfSides, double sideLength);

    void updateHeightAndWidth();

    int getNumSides() const;
    double getSideLength() const;

    virtual string generatePostScript() const override;

private:
    int _numberOfSides;
    double _sideLength;
};

// *********************************************************************
// Triangle class
// *********************************************************************
class Triangle: public Polygon
{
public:
    Triangle(double sideLength);
};

// *********************************************************************
// Square class
// *********************************************************************

class Square: public Polygon
{
public:
    Square(double sidelength);
};

// *********************************************************************
// Spacer class
// *********************************************************************

class Spacer : public Shape
{
public:
    Spacer(double width, double height);

    virtual string generatePostScript() const override;
};

#endif //CS372_CPS_SHAPE_H
