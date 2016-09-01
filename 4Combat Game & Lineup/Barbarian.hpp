
#ifndef Barbarian_hpp
#define Barbarian_hpp

#include <stdio.h>
#include "Creature.hpp"
#include "Die.hpp"
#include <iostream>
#include <string>

class Barbarian: public Creature
{
public:
    Barbarian();
    
    
    int attack();
    int defense();
    std::string identify();
    
private:
    
};

#endif 