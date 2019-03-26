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
private:
    pair<int, int> _center;
    int _height;
    int _width;
};

#endif //CS372_CPS_SHAPE_H
