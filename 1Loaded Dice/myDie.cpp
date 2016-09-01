/****************
 * Program: Die.cpp
 * Author: Mariam Ben-Neticha
 * Date: 10/1/15
 * Description: This file defines the constructor function (Die()) and initializes the values for the number of sides of the die to 6 and the fairValue data member to 0. It also programs the member function, rollValue(), to roll the Die once and output the value rolled.
 ****************/

#include "Die.hpp"
#include <cstdlib>
#include <iostream>


//Constructor

Die::Die()
{
    numSide = 6;
    fairValue = 0;
}

int Die::rollValue()
{
    int fairValue = rand() % numSide + 1;
    std::cout << "Fair Die rolled " << fairValue << "." << std::endl;
    return fairValue;
}