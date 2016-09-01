

#ifndef Barbarian_hpp
#define Barbarian_hpp

#include "Creature.hpp"
#include "Die.hpp"
#include <iostream>

class Barbarian: public Creature
{
public:
    Barbarian();
    
    
    int attack();
    int defense();
    
private:

};

#endif
