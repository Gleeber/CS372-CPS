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
    Shape(const Shape &s);

    pair<double, double> getCenter() const;
    double getHeight() const;
    double getWidth() const;

    void setHeight(double num);
    void setWidth(double num);
    void setCenter(double x, double y);

    void openfile(const char filename[]);
    void closefile();

    virtual string generatePostScript();
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
    Circle(const Circle &c);
    Circle(double radius);

    double getRadius() const;

    virtual string generatePostScript() override;

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

    virtual string generatePostScript() override;

private:

};

// *********************************************************************
// Polygon class
// *********************************************************************

class Polygon : public Shape
{
public:
    Polygon();
    Polygon(const Polygon &p);

    int getNumSides() const;
    double getSideLength() const;

    virtual string generatePostScript() override;

private:
    int _numberOfSides;
    double _sideLength;
};


// *********************************************************************
// Rotated class
// *********************************************************************

class Rotated : public Shape
{
public:
    Rotated(const Shape &shape, int rotationAngle);
    //virtual string generatePostScript() override;
private:
    int _rotation;
};

#endif //CS372_CPS_SHAPE_H
