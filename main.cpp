//
// Created by Andrew Adler on 2019-03-30.
//

#include "shape.h"
#include "CompoundShape.h"

int main()
{
    Triangle shape1(100);
    Square shape2(100);
    Polygon shape3(5,100);
    Spacer spacer(20,45);
    Square shape4(100);
    Circle circle(45);
    Vertical combinedShape(shape1, shape2, shape4,circle, shape3);
    Horizontal combinedShape2(combinedShape, shape4);
    combinedShape2.draw();
}
