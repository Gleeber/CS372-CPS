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

TEST_CASE("Test for shape class:") {
	Shape testShape;
	REQUIRE(testShape.getMidPoint() == auto std::make_pair(306, 396))
	SECTION("") {
		
	}
}