
#ifndef Reptile_hpp
#define Reptile_hpp

#include <stdio.h>
#include "Creature.hpp"
#include "Die.hpp"
#include <iostream>
#include <string>

class Reptile: public Creature
{
public:
    Reptile();
    
    int attack();
    int defense();
    std::string identify();
    
private:
    
};

#endif 
