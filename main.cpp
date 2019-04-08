//
// Created by Andrew Adler on 2019-03-30.
//

#include "shape.h"
#include "CompoundShape.h"

int main()
{
    Triangle shape1(100);
    Square shape2(100);
    Rectangle defaultRectangle;
    Rectangle rectangle(40,70);
    Polygon shape3(5,100);
    Spacer spacer(20,45);
    Square shape4(100);
    Circle circle(45);
    Rotated rotatedRectangle(rectangle,90);
    Layered combinedShape(shape1, shape2, rotatedRectangle, shape3);
    Vertical combinedShape2(combinedShape, spacer, rectangle, shape4, shape4);
    Horizontal combinedShape3(combinedShape,combinedShape2);
    combinedShape3.draw();
}
