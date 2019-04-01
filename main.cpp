//
// Created by Andrew Adler on 2019-03-30.
//

#include "shape.h"

int main()
{
    Polygon shape;
    Scaled rotatedShape(shape, 3,1.8);
    rotatedShape.draw();
}