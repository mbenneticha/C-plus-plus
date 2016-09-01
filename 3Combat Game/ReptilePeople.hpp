

#ifndef ReptilePeople_hpp
#define ReptilePeople_hpp

#include "Creature.hpp"
#include "Die.hpp"
#include <iostream>

class Reptile: public Creature
{
public:
    Reptile();
    
    int attack();
    int defense();
    
private:

};

#endif 
