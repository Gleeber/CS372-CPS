//cpsTest.cpp
//cs372 spring 201
//Project 2
//Team members: Jonathan Aarhus, Andrew Adler, Ian Ferguson

//Test File for CPS (C++ to PostScript)

#define CATCH_CONFIG_FAST_COMPILE

#include "catch.hpp"
#include "shape.h"
#include "CompoundShape.h"

#include <utility>
using std::make_pair;
using std::make_shared;

#include <cmath>
using std::sqrt;

// *********************************************************************
// Basic shape tests
// *********************************************************************

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

TEST_CASE("Test for Polygon class:")
{
    SECTION("Test default constructor:")
    {
        Polygon testPolygon;
        REQUIRE(testPolygon.getCenter() == make_pair(306.0, 396.0));
        REQUIRE(testPolygon.getHeight() == Approx(25 * sqrt(5 + 2 * sqrt(5))));
        REQUIRE(testPolygon.getWidth() == Approx(25 * (1 + sqrt(5))));
        REQUIRE(testPolygon.getNumSides() == 5);
    }

    SECTION("Test Polygon constructor with even number of sides:")
    {
        Polygon testPolygon(6, 82);
        REQUIRE(testPolygon.getCenter() == make_pair(306.0, 396.0));
        REQUIRE(testPolygon.getHeight() == Approx (82 * sqrt(3)));
        REQUIRE(testPolygon.getWidth() == Approx(164.0));
        REQUIRE(testPolygon.getNumSides() == 6);
    }

    SECTION("Test Polygon constructor with divisible by 4 sides:")
    {
        Polygon testPolygon(8, 39);
        REQUIRE(testPolygon.getCenter() == make_pair(306.0, 396.0));
        REQUIRE(testPolygon.getHeight() == Approx(94.1545232316));
        REQUIRE(testPolygon.getWidth() == Approx(94.1545232316));
        REQUIRE(testPolygon.getNumSides() == 8);
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

TEST_CASE("Test for Spacer:")
{
    SECTION("Test Spacer Constructor:")
    {
        Spacer testSpacer(10.0, 20.0);
        REQUIRE(testSpacer.getHeight() == 20.0);
        REQUIRE(testSpacer.getWidth() == 10.0);
        REQUIRE(testSpacer.getCenter() == make_pair(306.0,396.0));
    }
}

TEST_CASE("Test for Square:") {
    SECTION("Test default constructor")
    {
        Square testSquare(61);
        REQUIRE(testSquare.getCenter() == make_pair(306.0, 396.0));
        REQUIRE(testSquare.getHeight() == Approx(61.0));
        REQUIRE(testSquare.getWidth() == Approx(61.0));
    }
}

TEST_CASE("Test for Triangle:") {
	SECTION("Test side length 64:")
	{
		Triangle testTriangle(64);
		REQUIRE(testTriangle.getCenter() == make_pair(306.0, 396.0));
		REQUIRE(testTriangle.getHeight() == Approx(32 * sqrt(3)));
		REQUIRE(testTriangle.getWidth() == 64);
	}
}


// *********************************************************************
// Compound shape tests
// *********************************************************************

TEST_CASE("Tests for Rotated shapes:")
{
	Circle circle(5.0);
	Rectangle rect(15.0 ,10.0);
	SECTION("Rotated")
	{
		//Circle
		Rotated shape1(circle, 0);
		Rotated shape2(circle, 90);
		Rotated shape3(circle, 180);
		Rotated shape4(circle, 270);
		//Rectangle
		Rotated shape5(rect, 0);
		Rotated shape6(rect, 90);
		Rotated shape7(rect, 180);
		Rotated shape8(rect, 270);


		//Height
		//Circle
		REQUIRE(shape1.getHeight() == circle.getHeight());
		REQUIRE(shape2.getHeight() == circle.getWidth());
		REQUIRE(shape3.getHeight() == circle.getHeight());
		REQUIRE(shape4.getHeight() == circle.getWidth());

		//Width
		//Circle
		REQUIRE(shape1.getWidth() == circle.getWidth());
		REQUIRE(shape2.getWidth() == circle.getHeight());
		REQUIRE(shape3.getWidth() == circle.getWidth());
		REQUIRE(shape4.getWidth() == circle.getHeight());
		//Radius(exclusive to circle
	}
}

TEST_CASE("Tests for Scaled shapes")
{
    Polygon pentagon(5,50);
    Scaled scaledPentagon(pentagon, 2,.3);

    REQUIRE(scaledPentagon.getWidth() == Approx(pentagon.getWidth() * 2));
    REQUIRE(scaledPentagon.getHeight() == Approx(pentagon.getHeight() * 0.3));
}

TEST_CASE("Tests for Layered shapes")
{
    Square testSquare(81);
    Circle testCircle(40);
    Triangle testTriangle(73);

    Layered testLayered(testSquare, testCircle, testTriangle);

    REQUIRE( testLayered.getHeight() == Approx( testSquare.getHeight() ) );
    REQUIRE( testLayered.getWidth()  == Approx( testSquare.getWidth()  ) );
}
