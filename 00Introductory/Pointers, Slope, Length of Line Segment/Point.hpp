/********************************************
 *Class: Point.hpp
 *Author: Mariam Ben-Neticha
 *Date: 7/26/15
 *Description: This class defines the variables, functions and accessors and mutators of a Point.
*********************************************/



#ifndef POINT_HPP
#define POINT_HPP

class Point
{
public:
    Point();
    Point(const Point &OtherPoint);
    ~Point();
    void Print()const;
    
    void setXCoord(const double Value);
    void setYCoord(const double Value);
    double getXCoord() const;
    double getYCoord() const;
    
    double distanceTo(const Point OtherPoint) const;
private:
    double Xcoord;
    double Ycoord;
};
#endif //POINT_HPP