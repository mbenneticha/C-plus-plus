

#ifndef BlueMen_hpp
#define BlueMen_hpp

#include <stdio.h>
#include "Creature.hpp"
#include "Die.hpp"
#include <iostream>
#include <string>

class BlueMen: public Creature
{
public:
    BlueMen();
    
    int attack();
    int defense();
    std::string identify();
    
private:
    
};

#endif
