

#ifndef Shadow_hpp
#define Shadow_hpp

#include <stdio.h>
#include "Creature.hpp"
#include "Die.hpp"
#include <iostream>
#include <cstdlib>
#include <string>

class Shadow: public Creature
{
public:
    Shadow();
    
    int attack();
    int defense();
    std::string identify();
    int get_armor();
    
private:
};

#endif 
