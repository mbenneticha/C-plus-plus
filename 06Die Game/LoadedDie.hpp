
#include "Die.hpp"
#ifndef LoadedDie_hpp
#define LoadedDie_hpp

class LoadedDie : public Die
{
public:
    //constructor
    LoadedDie();
    LoadedDie(int user_sides);
    int Roll();        
};

#endif
