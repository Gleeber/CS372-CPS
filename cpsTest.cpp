//cpsTest.cpp
//cs372 spring 201
//Project 2
//Team members: Jonathan Aarhus, Andrew Adler, Ian Ferguson

//Test File for CPS (C++ to PostScript)

#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "shape.h"
#include <utility>
using std::make_pair;

TEST_CASE("Test for Shape class:") {
	SECTION("Test default constructor:") {
		Shape testShape;
		REQUIRE(testShape.getCenter() == make_pair(306.0, 396.0));
		REQUIRE(testShape.getHeight() == 72);
		REQUIRE(testShape.getWidth() == 72);
	}
	SECTION("Test getHeight():") {
		Shape testShape;
		REQUIRE(testShape.getHeight() == 72);
	}
	SECTION("Test getWidth():") {
		Shape testShape;
		REQUIRE(testShape.getWidth() == 72);
	}
	SECTION("Test getCenter():") {
		Shape testShape;
		REQUIRE(testShape.getCenter() == make_pair(306.0, 396.0));
	}
	SECTION("Test setHeight():") {
		Shape testShape;
		testShape.setHeight(144);
		REQUIRE(testShape.getHeight() == 144);
	}
	SECTION("Test setWidth():") {
		Shape testShape;
		testShape.setWidth(144);
		REQUIRE(testShape.getWidth() == 144);
	}
	SECTION("Test setCenter():") {
		Shape testShape;
		testShape.setCenter(200.0,200.0);
		REQUIRE(testShape.getCenter() == make_pair(200.0, 200.0));
	}
}

TEST_CASE("Test for Circle class:")
{
	SECTION("Test default constructor:") {
		Circle testCircle;
		REQUIRE(testCircle.getCenter() == make_pair(306.0, 396.0));
		REQUIRE(testCircle.getHeight() == 72);
		REQUIRE(testCircle.getWidth() == 72);
		REQUIRE(testCircle.getRadius() == 36);
	}
}

TEST_CASE("Test for Rectangle class:")
{
	SECTION("Test default constructor:") {
		Rectangle testRectangle;
		REQUIRE(testRectangle.getCenter() == make_pair(306.0, 396.0));
		REQUIRE(testRectangle.getHeight() == 72);
		REQUIRE(testRectangle.getWidth() == 144);
	}
}

TEST_CASE("Test for Triangle:") {
	SECTION("Test default constructor:") {
		//Triangle testTriangle;
		//REQUIRE(testTriangle.getCenter() == make_pair(306, 396));
		//REQUIRE(testTriangle.getHeight() == 72);
		//REQUIRE(testTriangle.getWidth() == 72);
	}
}

TEST_CASE("Test for Square:") {
	SECTION("Test default constructor") {
		//Square testSquare;
		//REQUIRE(testSquare.getCenter() == make_pair(306, 396));
		//REQUIRE(testSquare.getHeight() == 72);
		//REQUIRE(testSquare.getWidth() == 72);
	}
}

TEST_CASE("Test for Pentagon:") {
	SECTION("Test default constructor:") {
		//Polygon testDefaultPolygon;
		//REQUIRE(testDefaultPolygon.getCenter() == make_pair(306, 396));
		//REQUIRE(testDefaultPolygon.getHeight() == 72);
		//REQUIRE(testDefaultPolygon.getWidth() == 72);
	}
}