/********************************************
 *Program: main.cpp
 *Author: Mariam Ben-Neticha
 *Date: 7/26/15
 *Description: A main() function to demonstrate the use of the Point and Line Segment classes.
 *********************************************/

#include "LineSegment.hpp"
#include <iostream>
#include <math.h>
using namespace std;


int main() {
    
    //variables
    double xcoord, ycoord;
    
    //Create points and Line
    Point p1, p2;
    Line l1;
    
    //Obtain user-chosen coordinates for p1
    cout <<"Enter the X-coordinate for Point 1." <<endl;
    cin >> xcoord;
    cout <<"Enter the Y-coordinate for Point 1." <<endl;
    cin >> ycoord;
    
    p1.setXCoord(xcoord);
    p1.setYCoord(ycoord);
    p1.Print();
    
    //Obtain user-chosen coordinates for p2
    cout <<"Enter the X-coordinate for Point 2." <<endl;
    cin >> xcoord;
    cout <<"Enter the Y-coordinate for Point 2." <<endl;
    cin >> ycoord;
    
    p2.setXCoord(xcoord);
    p2.setYCoord(ycoord);
    p2.Print();
    
    l1.setEnd1(p1);
    l1.setEnd2(p2);
    
    l1.length();
    l1.slope();
    
    return 0;
};