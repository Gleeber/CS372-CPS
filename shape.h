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

    pair<int, int> getCenter();
    int getHeight();
    int getWidth();
private:
    pair<int, int> _center;
    int _height;
    int _width;
};

class Circle : public Shape
{
public:
private:
    int _radius;
};

#endif //CS372_CPS_SHAPE_H
