

#ifndef Die_hpp
#define Die_hpp

#include <stdio.h>

class Die
{
public:
    Die();
    Die(int user_sides);
    int Roll();
    
protected:
    int num_sides;
    int rolled_value;
};


#endif