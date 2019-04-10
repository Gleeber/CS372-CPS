//
// Created by Andrew Adler on 2019-03-30.
//

#include "shape.h"
#include "CompoundShape.h"

#include <iostream>
using std::cout;
using std::endl;

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

    Asterisk asterisk(6,60);
    Vertical verticalAsterisk(shape2,asterisk,shape2);
    Horizontal horizontalAsterisk(shape2,verticalAsterisk,shape2);
    horizontalAsterisk.draw();
}

int mainj()
{
    Polygon heptagon(7,80);
    Circle circle(40);
    Square square(120);
    Rectangle rectangle(60,120);
    Rotated rotatedHeptagon(heptagon,90);
    Scaled scaledCircle(circle,1.8,.7);
    Horizontal modifiedShape(rotatedHeptagon,scaledCircle,circle,square);
    Scaled scaledCombined(modifiedShape,.7,2.3);
    scaledCombined.draw();
}
