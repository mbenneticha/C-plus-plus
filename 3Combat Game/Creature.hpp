

#ifndef Creature_hpp
#define Creature_hpp

#include "Die.hpp"
#include <iostream>

class Creature
{
public:
    Creature();
    Creature(int strength, int my_armor, int att_sides, int def_sides, int att_dice, int def_dice);
    
    //pure virtual functions
    virtual int attack() = 0;
    virtual int defense() = 0;
    
    //virtual function
    virtual int get_armor();
    
    void set_strength(int strength_pts);
    int get_strength();
    
    
    int get_def_dice();
    int get_def_sides();
    int get_att_dice();
    int get_att_sides();
    
    Die *get_att_die();
    Die *get_def_die();
    
private:
    int strength_points;
    int armor;
    int att_num_sides;
    int def_num_sides;
    int num_att_dice;
    int num_def_dice;
    
    Die def_die[3];
    Die att_die[3];

};

#endif
