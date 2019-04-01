//
// Created by Andrew Adler on 2019-03-30.
//

#include "shape.h"

int main()
{
    Rectangle rectangle;
    Rotated rotatedRectangle(rectangle, 90);
    rotatedRectangle.draw();
}