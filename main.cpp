//
// Created by Andrew Adler on 2019-03-30.
//

#include "shape.h"

int main()
{
    Triangle shape1(100);
    Square shape2(100);
    Polygon shape3(5,100);
    Circle circle(1);
    Vertical combinedShape(shape1, shape2, shape3,circle);
    combinedShape.draw();
}
