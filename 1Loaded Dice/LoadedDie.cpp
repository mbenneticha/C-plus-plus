/****************
 * Program: LoadedDie.cpp
 * Author: Mariam Ben-Neticha
 * Date: 10/1/15
 * Description: This file defines the constructor function (LoadedDie()) and initializes the data member, numSide, to indicate the number of sides as six. It also has the member function, rollVal() that gives the value of a single roll of a single loaded Die. In this program, the value 5 is set to occur more often than any other number on the die.
 ****************/

#include "LoadedDie.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

//Constructor

LoadedDie::LoadedDie()
{
    numSides = 6;
    loadedValue = 0;
}


// member function to return value of single roll of single die
int LoadedDie::rollVal()
{
    float loadDie[6] = {0.0, 0.1, 0.1, 0.1, 0.6, 0.1};
    
    
    
    float   pct;   // the random "roll" expressed as decimal percent
    int resolution = 10000;
    pct = (float)(rand() % resolution + 1) / resolution;
        
    
    if (pct < loadDie[0])
        loadedValue = 1;
    else if (pct < (loadDie[0] + loadDie[1]))
        loadedValue = 2;
    else if (pct < (loadDie[0] + loadDie[1] + loadDie[2]))
        loadedValue = 2;
    else if (pct < (loadDie[0] + loadDie[1] + loadDie[2] + loadDie[3]))
        loadedValue = 4;
    else if (pct < (loadDie[0] + loadDie[1] + loadDie[2] + loadDie[3] + loadDie[4]))
        loadedValue = 5;
    else
        loadedValue = 6;
    
    std::cout << "Loaded Die rolled " << loadedValue << "." << std::endl;


    return loadedValue;
}





