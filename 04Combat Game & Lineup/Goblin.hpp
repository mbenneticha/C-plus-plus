

#ifndef Goblin_hpp
#define Goblin_hpp

#include <stdio.h>
#include "Creature.hpp"
#include "Die.hpp"
#include <iostream>
#include <string>


class Goblin: public Creature
{
public:
    Goblin();
    
    int attack();
    int defense();
    std::string identify();
    
private:
    
};

#endif
