//
// Created by Ian Ferguson on 2019-03-26.
//

#ifndef CS372_CPS_SHAPE_H
#define CS372_CPS_SHAPE_H

#include <iostream>
#include <fstream>
#include <utility>
using std::pair;
#include <string>
using std::string;
using std::to_string;

// *********************************************************************
// Shape class
// *********************************************************************

class Shape
{
public:
    Shape();

    pair<double, double> getCenter() const;
    double getHeight() const;
    double getWidth() const;

    void setHeight(double num);
    void setWidth(double num);
    void setCenter(double x, double y);

    void openfile(const char filename[]);
    void closefile();

    virtual string generatePostScript() const;
    void draw();
    string getFilename() const;

protected:
    std::ofstream file;

private:
    pair<double, double> _center;
    double _height;
    double _width;
    string _filename;
};


// *********************************************************************
// Circle class
// *********************************************************************

class Circle : public Shape
{
public:
    Circle();
    Circle(double radius);

    double getRadius() const;

    virtual string generatePostScript() const override;

private:
    double _radius;
};

// *********************************************************************
// Rectangle class
// *********************************************************************

class Rectangle : public Shape
{
public:
    Rectangle();
    Rectangle(double width, double height);

    virtual string generatePostScript() const override;

private:

};

// *********************************************************************
// Polygon class
// *********************************************************************

class Polygon : public Shape
{
public:
    Polygon();

    int getNumSides() const;
    double getSideLength() const;

    virtual string generatePostScript() const override;

private:
    int _numberOfSides;
    double _sideLength;
};

// *********************************************************************
// Spacer class definitions
// *********************************************************************

class Spacer : public Shape
{
public:
    Spacer(double width, double height);

    virtual string generatePostScript() const override;
};

// *********************************************************************
// Rotated class
// *********************************************************************

class Rotated : public Shape
{
public:
    Rotated(const Shape &shape, int rotationAngle);

    virtual string generatePostScript() const override;

private:
    const Shape & _shape;
    int _rotation;
};

// *********************************************************************
// Rotated class
// *********************************************************************
 class Scaled: public Shape
 {
 public:
     Scaled(const Shape &shape, double fx, double fy);

 private:
     double _scaleFactorX;
     double _scaleFactorY;
     const Shape & _shape;
 };



#endif //CS372_CPS_SHAPE_H
