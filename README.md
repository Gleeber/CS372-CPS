# CS372-CPS

This is a C++ to PostScript converter that allows a user of the program to specify various dimensions and values for a variety of shapes and generate the postscript to draw those shapes.

The standalone shape classes are all in contained in shape.h/.cpp and the compound shapes (shapes that take other shapes in their initializations) are contained in CompoundShape.h/.cpp.

## How to Use the Main Program

1. Download the header and source files
2. Modify [main.cpp](https://github.com/Gleeber/CS372-CPS/blob/master/main.cpp) to construct whatever shapes are desired, ending with a call to draw the shapes: `shape.draw();`
3. Compile and run `main.cpp` using a C++ compiler
4. Retrieve the `postScriptFile.ps` from wherever the executable of the program was compiled to.

A sample `main` is shown below:


```cpp
int main() {
    Circle circle(35);            // Circle with radius 35
    Rectangle rectangle(120,60);  // Rectangle with width 120 and height 60
    Polygon pentagon(5,50);       // Polygon with 5 sides and side length 50

    // Combine the three shapes into one shape
    Vertical verticalShape(circle,rectangle,pentagon);

    // Draw the combined shape
    verticalShape.draw();
}

```

## Basic Shapes

The basic shapes that can be created with their argument lists are:

* Circle (double radius)
* Polygon (int numberOfSides, double sideLength)
* Rectangle (double width, double height)
* Spacer (double width, double height)
* Square (double sideLength)
* Triangle (double sideLength)
* Asterisk (int numberOfArms, double armLength)

## Compound Shapes

The compound shapes that can be created with their argument lists are:

* Rotated (Shape shape, int rotationAngle)
* Scaled (Shape shape, double scaleX, double scaleY)
* Layered (Shape... shapes)
* Vertical (Shape... shapes)
* Horizontal (Shape... shapes)

"Shape..." indicates that any number of existing shapes can be given as arguments to the argument list.

## Testing

Testing for this project is done using the [catch framework](https://github.com/catchorg/Catch2 "Catch GitHub Page"), using a test\_main and a test\_suites file to keep the tests separate from the testing framework. Tests are written for almost all of the shapes that check that the shapes are constructed correctly and member variables are initialized and modified to the right values. Currently, no testing exists for the postscript output that is generated for the various shapes, but the plan is to implement these tests by comparing the generated string to an existing string that is confirmed to work correctly.

## Overview / Reflection

Quite a few complex shapes can be drawn using just the shapes provided in this program with the use of compound shapes and spacers to get sizing correct for combined shapes. If the program is used correctly, quite a bit can actually be drawn. The framework is fairly straightforward to use, which is nice.