

#include "Die.hpp"
#include <cstdlib>
#include <iostream>

//default constructor
Die::Die()
{
    num_sides = 6;
    rolled_value = 0;
}

//constructor with parameter
Die::Die(int user_sides)
{
    num_sides = user_sides;
    rolled_value = 0;
}

//die rolling function (rolls die once)
int Die::Roll()
{
    rolled_value = rand() % num_sides + 1;
    //std::cout << "Fair Die rolled " << fairValue << "." << std::endl;
    return rolled_value;
    
}