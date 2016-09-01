
#include "LoadedDie.hpp"
#include <iostream>
#include <cstdlib>

// default constructor
LoadedDie::LoadedDie():Die()
{

}

// constructor with parameters
LoadedDie::LoadedDie(int user_sides):Die(user_sides)
{

}


/*************************************************************
 * Function: Roll()
 * Description: Rolls the dice
 * Parameters: None
 * Pre-Conditions: Random number generator needs to be seeded.
 * Post-Conditions: None
 *************************************************************/



int LoadedDie::Roll()
{
    if (rand() % 100 + 1 <= 60)
        return num_sides;
    else
        return rand() % (num_sides - 1) + 1;
}
