/********************************************
 *Class: Line.hpp
 *Author: Mariam Ben-Neticha
 *Date: 7/26/15
 *Description: This class defines the variables, functions and accessors and mutators of a Line segment.
 *********************************************/

#ifndef LineSegment_HPP
#define LineSegment_HPP
#include "Point.hpp"

class Line
{
public:
    
    //constructors and destructor
    Line();
    Line(const Line &OtherLine);
    ~Line();
    
    //getters and setters
    void setEnd1 (const Point SomePoint);
    void setEnd2 (const Point SomePoint);
    Point getEnd1() const;
    Point getEnd2() const;
    
    //other useful methods
    void length() const;
    void slope() const;
    
private:
    Point end1;
    Point end2;
};
#endif

