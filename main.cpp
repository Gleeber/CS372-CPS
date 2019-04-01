//
// Created by Andrew Adler on 2019-03-30.
//

#include "shape.h"

int main()
{
    Rectangle rectangle;
    Rotated rotated(rectangle, 90);
    rotated.draw();
}