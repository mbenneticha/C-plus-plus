
#ifndef TheShadow_hpp
#define TheShadow_hpp

#include "Creature.hpp"
#include "Die.hpp"
#include <iostream>
#include <stdlib.h>

class Shadow: public Creature
{
public:
    Shadow();
    
    int attack();
    int defense();
    int get_armor();
    
private:
};

#endif

