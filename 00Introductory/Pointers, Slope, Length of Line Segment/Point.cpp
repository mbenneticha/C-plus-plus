/********************************************
 *Class: Point.cpp
 *Author: Mariam Ben-Neticha
 *Date: 7/26/15
 *Description: This sets and gets the variables, functions and accessors and mutators of a Point and solves the distance between 2 points.
 *********************************************/

#include <iostream>
#include <math.h>
#include "Point.hpp"
using namespace std;

Point::Point()
{
}

//Construct other points for calculating the points
Point::Point(const Point &OtherPoint)
{
    Xcoord = OtherPoint.Xcoord;
    Ycoord = OtherPoint.Ycoord;
}

//Destructor
Point::~Point()
{
}

//Assign X-coordinate the Value that is put into the main
void Point::setXCoord(const double Value)
{
    Xcoord = Value;
}

//Assing Y-coordinate the Value that is put into the main
void Point::setYCoord(const double Value)
{
    Ycoord = Value;
}

//Return X-coordinate
double Point::getXCoord() const
{
    return Xcoord;
}

//Return Y-coordinate
double Point::getYCoord() const
{
    return Ycoord;
}

//Calculates distance between two points and outputs
double Point::distanceTo(const Point OtherPoint) const
{
    double First = Xcoord;
    double Second = OtherPoint.Xcoord;
    double Third = Ycoord;
    double Fourth = OtherPoint.Ycoord;
    
    double Distance = sqrt((Second - First)*(Second-First) + (Fourth - Third)*(Fourth-Third));
    cout << "The distance is: " << Distance << endl;
    return Distance;
}

//Prints the points
void Point::Print() const
{
    cout << "Point is: (" << Xcoord << ", " << Ycoord << ")" << endl;
}