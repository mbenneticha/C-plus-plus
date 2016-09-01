

#ifndef Combat_hpp
#define Combat_hpp

#include "Creature.hpp"
#include <typeinfo>
#include <iostream>


class Combat
{
public:
    Combat();

    int calc_damage(int attack, int defense);
    int apply_damage(int armor, int damage, int strength);
    bool same_subclass( Creature *c_1, Creature *c_2);
    void do_combat(Creature* cr_1, Creature* cr_2, int same_sub);
    
private:
    
};

#endif


