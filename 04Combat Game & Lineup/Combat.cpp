

#include "Combat.hpp"


//Constructor
Combat::Combat()
{
}



//subtract attack roll-defense roll
int Combat::calc_damage(int attack, int defense)
{
    int damage;
    damage = attack - defense;
    return damage;
}



//adjust strenth points of defender
int Combat::apply_damage(int armor, int damage, int strength)
{
    int strength_pts = strength;
    
    //if Shadow did not manipulate perception (Shadow not safe)
    if (armor != -1)
    {
        if (damage >= 0)
        {
            damage = (damage - armor);
        }
        
        if (damage <= 0)
        {
            damage = 0;
        }
        
        strength_pts = (strength - damage); //_dealt);
        
        //if damage dealt is more than the strength points, set s.p. to 0
        if (strength_pts <= 0)
        {
            strength_pts = 0;
        }
    }
    return strength_pts;
}


//replenish winning creature's points
void Combat::replenish_points(Creature* win_creature)
{
    int replenish_pts;
    replenish_pts = win_creature->get_strength();
    replenish_pts += 5;
    win_creature->set_strength(replenish_pts);
}



//check if same type are fighting each other
bool Combat::same_subclass(Creature* cr_1, Creature* cr_2)
{
    int same_sub = 0;
    if (cr_1 == cr_2)
    {
        same_sub = 1;  //true
        return same_sub;
    }
    else
        return same_sub; //false
}



//commence combat between creatures until one loses
int Combat::do_combat(Creature* cr_1, Creature* cr_2, int same_sub)
{
    //set booleans to false at start of fight
    bool done = false;
    
    //if the same creatures are fighting, do this combat
    if (same_sub != 0)
    {
        do {
            int att_1 = cr_1->attack();
            int def_1 = cr_2->defense();
            
            if(att_1 == 0)
            {
                //return goblins original attack value
                att_1 = 12;
            }
            
            //initialize damage to zero
            int dmg = 0;
            dmg = calc_damage(att_1, def_1);
            
            //initialize adjusted strength points to zero
            int new_sp = 0;
            new_sp = apply_damage(cr_2->get_armor(), dmg, cr_2->get_strength());
            
            //set adjusted strength points to defending creature
            cr_2->set_strength(new_sp);
            
            //check if defending character still has strength
            if (cr_2->get_strength() != 0)
            {
                int att_2 = cr_2->attack();
                int def_2 = cr_1->defense();
                
                if(att_2 == 0)
                {
                    //return goblins original attack value
                    att_2 = 12;
                }
                
                //re-initialize damage to zero
                dmg = 0;
                dmg = calc_damage(att_2, def_2);
                
                //re-initialize adjusted strength points to zero
                new_sp = 0;
                new_sp = apply_damage(cr_1->get_armor(), dmg, cr_1->get_strength());
                
                //set adjusted strength points to defending creature
                cr_1->set_strength(new_sp);
            }
            
            //check if either character has lost all s.p.
            done = (cr_1->get_strength() == 0) || (cr_2->get_strength() == 0);
            
        } while (!done);  //repeat until a creature is out of s.p.
    }
    else
        do {
            bool ach_1 = false;
            bool ach_2 = false;
            
            int att_1 = cr_1->attack();
            int def_1 = cr_2->defense();
            
            //check to see if a goblin rolled a twelve
            if(att_1 == 0)
            {
                //set bool to true
                ach_1 = true;
                //return goblins original attack value
                att_1 = 12;
            }
            
            //if goblin cut attacker's Achilles
            if (ach_2)
            {
                //cut attacking creature's attack in half
                //for remainder of game
                att_1 /= 2;
            }
            
            //initialize damage to zero
            int dmg = 0;
            dmg = calc_damage(att_1, def_1);
            
            //initialize adjusted s.p. to zero
            int new_sp = 0;
            new_sp = apply_damage(cr_2->get_armor(), dmg, cr_2->get_strength());
            
            //set adjusted strength points to defending creature
            cr_2->set_strength(new_sp);
            
            //check if defending character still has strength
            if (cr_2->get_strength() != 0)
            {
                //round 1 part two, switch attacker and defender
                int att_2 = cr_2->attack();
                int def_2 = cr_1->defense();
                
                //check to see if a goblin rolled a twelve
                if (att_2 == 0)
                {
                    //set bool to true
                    ach_2 = true;
                    //return goblins original attack value
                    att_2 = 12;
                }
                
                //if goblin cut attacker's Achilles
                if (ach_1)
                {
                    //cut attacking creature's attack in half
                    //for remainder of game
                    att_2 /= 2;
                }
                
                //re-initialize damage to zero
                dmg = 0;
                dmg = calc_damage(att_2, def_2);
                
                //re-initialize adjusted strength points to zero
                new_sp = 0;
                new_sp = apply_damage(cr_1->get_armor(), dmg, cr_1->get_strength());
                
                //set adjusted strength points to defending creature
                cr_1->set_strength(new_sp);
            }
            
            //check if either character has lost all s.p.
            done = (cr_1->get_strength() == 0) || (cr_2->get_strength() == 0);
            
        } while (!done);   //repeat until a creature is out of s.p.
    
    //print winner
    if (cr_1->get_strength() == 0)
    {
        return 2;
    }
    else
        return 1;
}


//tournament round
int Combat::tournament(Creature *p1, Creature *p2)
{
    Combat combat;
    int same;
    same = combat.same_subclass(p1, p2);
    
    int winner;
    winner = combat.do_combat(p1, p2, same);
    
    return winner;
}