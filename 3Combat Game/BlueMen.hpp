
#ifndef BlueMen_hpp
#define BlueMen_hpp

#include "Creature.hpp"
#include "Die.hpp"
#include <iostream>

class BlueMen: public Creature
{
public:
    BlueMen();
    
    int attack();
    int defense();
    
private:
    
};

#endif
