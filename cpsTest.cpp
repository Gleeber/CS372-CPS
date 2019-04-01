//cpsTest.cpp
//cs372 spring 201
//Project 2
//Team members: Jonathan Aarhus, Andrew Adler, Ian Ferguson

//Test File for CPS (C++ to PostScript)

#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#define CATCH_CONFIG_FAST_COMPILE
#include "catch.hpp"
#include "shape.h"
#include <utility>
using std::make_pair;
#include <cmath>
using std::sqrt;
using std::make_shared;

TEST_CASE("Test for Shape class:") {
	SECTION("Test default constructor:")
	{
		Shape testShape;
		REQUIRE(testShape.getCenter() == make_pair(306.0, 396.0));
		REQUIRE(testShape.getHeight() == 72);
		REQUIRE(testShape.getWidth() == 72);
	}

	SECTION("Test getHeight():")
	{
		Shape testShape;
		REQUIRE(testShape.getHeight() == 72);
	}

	SECTION("Test getWidth():")
	{
		Shape testShape;
		REQUIRE(testShape.getWidth() == 72);
	}

	SECTION("Test getCenter():")
	{
		Shape testShape;
		REQUIRE(testShape.getCenter() == make_pair(306.0, 396.0));
	}

	SECTION("Test setHeight():")
	{
		Shape testShape;
		testShape.setHeight(144);
		REQUIRE(testShape.getHeight() == 144);
	}

	SECTION("Test setWidth():")
	{
		Shape testShape;
		testShape.setWidth(144);
		REQUIRE(testShape.getWidth() == 144);
	}

	SECTION("Test setCenter():")
	{
		Shape testShape;
		testShape.setCenter(200.0,200.0);
		REQUIRE(testShape.getCenter() == make_pair(200.0, 200.0));
	}
}

TEST_CASE("Test for Circle class:")
{
	SECTION("Test default constructor:")
	{
		Circle testCircle;
		REQUIRE(testCircle.getCenter() == make_pair(306.0, 396.0));
		REQUIRE(testCircle.getHeight() == 72);
		REQUIRE(testCircle.getWidth() == 72);
		REQUIRE(testCircle.getRadius() == 36);
	}

	SECTION("Test constructor that takes radius:")
	{
		Circle testCircle(100);
		REQUIRE(testCircle.getHeight() == 200);
		REQUIRE(testCircle.getWidth() == 200);
		REQUIRE(testCircle.getRadius() == 100);
	}
}

TEST_CASE("Test for Rectangle class:")
{
	SECTION("Test default constructor:")
	{
		Rectangle testRectangle;
		REQUIRE(testRectangle.getCenter() == make_pair(306.0, 396.0));
		REQUIRE(testRectangle.getHeight() == 72);
		REQUIRE(testRectangle.getWidth() == 144);
	}
	SECTION("Test constructor that takes width and height as parameters: ")
    {
	    Rectangle testRectangle(96, 96);
	    REQUIRE(testRectangle.getHeight() == 96);
	    REQUIRE(testRectangle.getWidth() == 96);
    }
}

TEST_CASE("Test for Polygon class:")
{
	SECTION("Test default constructor:")
	{
		Polygon testPolygon;
		REQUIRE(testPolygon.getCenter() == make_pair(306.0, 396.0));
		REQUIRE(testPolygon.getHeight() == 25 * sqrt(5 + 2 * sqrt(5)));
		REQUIRE(testPolygon.getWidth() == 25 * (1 + sqrt(5)));
		REQUIRE(testPolygon.getNumSides() == 5);
	}

	SECTION("Test Polygon constructor with number of sides:")
	{
		//Polygon testPolygon(6);
		//REQUIRE(testPolygon.getCenter() == make_pair(306.0, 396.0));
		//REQUIRE(testPolygon.getHeight() == 72);
		//REQUIRE(testPolygon.getWidth() == 72);
		//REQUIRE(testPolygon.getNumSides() == 5);
	}
}

TEST_CASE("Test for Triangle:") {
	SECTION("Test default constructor:")
	{
		//Triangle testTriangle;
		//REQUIRE(testTriangle.getCenter() == make_pair(306, 396));
		//REQUIRE(testTriangle.getHeight() == 72);
		//REQUIRE(testTriangle.getWidth() == 72);
	}
}

TEST_CASE("Test for Square:") {
	SECTION("Test default constructor")
	{
		//Square testSquare;
		//REQUIRE(testSquare.getCenter() == make_pair(306, 396));
		//REQUIRE(testSquare.getHeight() == 72);
		//REQUIRE(testSquare.getWidth() == 72);
	}
}

TEST_CASE("Test for Pentagon:") {
	SECTION("Test default constructor:")
	{
		//Polygon testDefaultPolygon;
		//REQUIRE(testDefaultPolygon.getCenter() == make_pair(306, 396));
		//REQUIRE(testDefaultPolygon.getHeight() == 72);
		//REQUIRE(testDefaultPolygon.getWidth() == 72);
	}
}
TEST_CASE("Compound Shapes:")
{
	Circle circle(5.0);
	SECTION("Rotated")
	{
		//Circle
		Rotated shape1(make_shared<Circle> (circle), 0);
		Rotated shape2(make_shared<Circle> (circle), 90);
		Rotated shape3(make_shared<Circle> (circle), 180);
		Rotated shape4(make_shared<Circle> (circle), 270);
		//Rectangle

		//Height
		REQUIRE(shape1.getHeight() == circle.getHeight());
		REQUIRE(shape2.getHeight() == circle.getWidth());
		REQUIRE(shape3.getHeight() == circle.getHeight());
		REQUIRE(shape4.getHeight() == circle.getWidth());

		//Width
		REQUIRE(shape1.getWidth() == circle.getWidth());
		REQUIRE(shape2.getWidth() == circle.getHeight());
		REQUIRE(shape3.getWidth() == circle.getWidth());
		REQUIRE(shape4.getWidth() == circle.getHeight());
	}
}
