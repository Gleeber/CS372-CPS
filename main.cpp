//
// Created by Andrew Adler on 2019-03-30.
//

#include "shape.h"

int main()
{
    Circle shape1;
    shape1.setHeight(4);
    Rectangle shape2(shape1);
    std::cout << shape2.getHeight() << std::endl;
    std::cout << shape1.getWidth() << std::endl;
}