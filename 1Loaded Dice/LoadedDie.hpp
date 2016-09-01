/****************
 * Header: LoadedDie.hpp
 * Author: Mariam Ben-Neticha
 * Date: 10/1/15
 * Description: This header defines a class called LoadedDie that has one data member, numSide, to indicate the number of sides. It also has the constructor function (LoadedDie()) and a member function prototype, rollVal() that gives the value of a single roll of a single loaded Die.
 ****************/

#ifndef LOADEDDIE_HPP
#define LOADEDDIE_HPP



class LoadedDie
{
private:
    int numSides;
    int loadedValue;
    
public:
    LoadedDie();
    int rollVal();               //member func gives value of 1 roll of die
    
};

#endif
