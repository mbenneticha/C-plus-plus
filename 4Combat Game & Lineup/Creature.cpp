

#include "Creature.hpp"
Creature::Creature()
{
    this->strength_points = 0;
    this->armor = 0;
    this->att_num_sides = 0;
    this->def_num_sides = 0;
    this->num_att_dice = 0;
    this->num_def_dice = 0;
}


Creature::Creature(int strength, int my_armor, int att_sides, int def_sides, int att_dice, int def_dice)
{
    this->strength_points = strength;
    this->armor = my_armor;
    this->att_num_sides = att_sides;
    this->def_num_sides = def_sides;
    this->num_att_dice = att_dice;
    this->num_def_dice = def_dice;
    
    
    for (int i = 0; i < def_dice; i++)
    {
        def_die[i] = *(new Die(def_sides));
    }
    
    
    for (int i = 0; i < att_dice; i++)
    {
        att_die[i] = *(new Die(att_sides));
    }
}


void Creature::set_strength(int strength_pts)
{
    this->strength_points = strength_pts;
}


int Creature::get_strength()
{
    return this->strength_points;
}


int Creature::get_armor()
{
    return this->armor;
}


int Creature::get_def_dice()
{
    return this->num_def_dice;
}


int Creature::get_def_sides()
{
    return this->def_num_sides;
}


int Creature::get_att_dice()
{
    return this->num_att_dice;
}


int Creature::get_att_sides()
{
    return this->att_num_sides;
}


Die *Creature::get_att_die()
{
    return this->att_die;
}


Die *Creature::get_def_die()
{
    return this->def_die;
}