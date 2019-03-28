//
// Created by Ian Ferguson on 2019-03-26.
//

#ifndef CS372_CPS_SHAPE_H
#define CS372_CPS_SHAPE_H

#include <iostream>
#include <utility>
using std::pair;

class Shape
{
public:
    Shape();

    pair<double, double> getCenter();
    double getHeight();
    double getWidth();
    void setHeight();
    void setWidth();
    void setCenter(double x, double y);
private:
    pair<double, double> _center;
    double _height;
    double _width;
};

class Circle : public Shape
{
public:
    Circle();

    double getRadius();

private:
    double _radius;
};

class Rectangle: public Shape{
public:
    Rectangle();


private:

};

#endif //CS372_CPS_SHAPE_H
