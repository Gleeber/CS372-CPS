//cpsTest.cpp
//cs372 spring 201
//Project 2
//Team members: Jonathan Aarhus, Andrew Adler, Ian Ferguson

//Test File for CPS (C++ to PostScript)

#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "shape.h"
#include <utility>
using std::pair;

TEST_CASE("Test for Shape class:") {
	SECTION("Test default constructor:") {
		Shape testShape;
		REQUIRE(testShape.getCenter() == std::make_pair(306, 396));
		REQUIRE(testShape.getHeight() == 72);
		REQUIRE(testShape.getWidth() == 72);
	}
}

TEST_CASE("Test for Circle class:")
{
	SECTION("Test default constructor:") {
		Circle testCircle;
		REQUIRE(testCircle.getCenter() == std::make_pair(306, 396));
		REQUIRE(testCircle.getHeight() == 72);
		REQUIRE(testCircle.getWidth() == 72);
		REQUIRE(testCircle.getRadius() == 36);
	}
}

TEST_CASE("Test for Rectangle class:") {
<<<<<<< HEAD
	Rectangle testRectangle;
	REQUIRE(testRectangle.getCenter() == std::make_pair(306, 396));
	REQUIRE(testRectangle.getHeight() == 72);
	REQUIRE(testRectangle.getWidth() == 144);
=======
	SECTION("Test default constructor:") {
		Rectangle testRectangle;
		REQUIRE(testShape.getCenter() == std::make_pair(306, 396));
		REQUIRE(testShape.getHeight() == 72);
		REQUIRE(testShape.getWidth() == 144);
	}
>>>>>>> 50efeaec9b2a133a5fc2c9ccd580661b01dee3f5
}