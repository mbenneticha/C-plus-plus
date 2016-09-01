/********************************************
 *Class: Point.cpp
 *Author: Mariam Ben-Neticha
 *Date: 7/26/15
 *Description: This sets and gets the variables, functions and accessors and mutators of a line segment and solves for the length and slope of a line segment.
 *********************************************/

#include <iostream>
#include <math.h>
#include "LineSegment.hpp"
using namespace std;

Line::Line()
{
}

Line::Line(const Line &OtherLine)
{
    end1 = OtherLine.end1;
    end2 = OtherLine.end2;
}

Line::~Line()
{
}

void Line::setEnd1(const Point SomePoint)
{
    end1 = SomePoint;
}

void Line::setEnd2 (const Point SomePoint)
{
    end2 = SomePoint;
}

Point Line::getEnd1() const
{
    return end1;
}

Point Line::getEnd2() const
{
    return end2;
}

void Line::length()const
{
    double length = end2.distanceTo(end1);
    std::cout << "Length of segment is " << length <<endl;
}

void Line::slope() const
{
    double slope, changeInX, changeInY;
    //Problem subdivided to make formula easier to read
    changeInX = end2.getXCoord() - end1.getXCoord();
    changeInY = end2.getYCoord() - end1.getYCoord();
    slope = changeInY / changeInX;
    std::cout << "Slope of segment is " << slope <<endl;
}
