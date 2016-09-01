/****************
 * Header: Die.hpp
 * Author: Mariam Ben-Neticha
 * Date: 10/1/15
 * Description: This header defines a class called Die that has two data members (numSide to indicate the number of sides and fairValue which is used to store and return the value of the fair Die.  It also has the constructor function (Die()) and a member function prototype, rollValue() that gives the value of a single roll of a single fair Die.
 ****************/

#ifndef DIE_HPP
#define DIE_HPP


class Die
{
private:
    int numSide;
    int fairValue;
    
public:
    Die();                            //Constructor Function
    int rollValue();               //member func gives value of 1 roll of die
    
};

#endif
