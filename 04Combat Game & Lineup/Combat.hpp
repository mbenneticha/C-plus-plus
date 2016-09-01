

#ifndef Combat_hpp
#define Combat_hpp

#include <stdio.h>
#include "Creature.hpp"
#include <typeinfo>
#include <iostream>


class Combat
{
public:
    Combat();
    
    int calc_damage(int attack, int defense);
    int apply_damage(int armor, int damage, int strength);
    void replenish_points(Creature* win_creature);
    bool same_subclass(Creature* cr_1, Creature* cr_2);
    int do_combat(Creature* cr_1, Creature* cr_2, int same_sub);
    int tournament(Creature *p1, Creature *p2);
    
private:
    
};

#endif 
