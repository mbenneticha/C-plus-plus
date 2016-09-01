
#ifndef Goblin_hpp
#define Goblin_hpp

#include "Creature.hpp"
#include "Die.hpp"
#include <iostream>


class Goblin: public Creature
{
public:
    Goblin(); 
    
    int attack();
    int defense();
    
private:

};

#endif

