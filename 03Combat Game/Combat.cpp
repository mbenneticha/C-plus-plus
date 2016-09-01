

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

    std::cout << "    Damage: " <<damage <<std::endl;
    
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
    
    std::cout << "    Armor: " <<armor <<std::endl;
    std::cout << "    Damage Dealt: " <<damage <<std::endl;
    std::cout << "    New S.P.: " <<strength_pts <<std::endl <<std::endl;
    
    return strength_pts;
}


//check if same type are fighting each other
bool Combat::same_subclass(Creature *c_1, Creature *c_2)
{
    int same_sub = 0;
    if (typeid(*c_1) == typeid(*c_2))
    {
        same_sub = 1;  //true
        return same_sub;
    }
    else
        return same_sub; //false
}



//commence combat between creatures until one loses
void Combat::do_combat(Creature* cr_1, Creature* cr_2, int same_sub)
{
    //set booleans to false at start of fight
    bool done = false;
    int round = 1;
    
    //if the same creatures are fighting, do this combat
    if (same_sub != 0)
    {
        do {
            
            std::cout << "Round " << round++ <<std::endl;
            std::cout << "Attacker: " << typeid(*cr_1).name() <<std::endl;
            std::cout << "Defender: " << typeid(*cr_2).name() <<std::endl;
            
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
            //std::cout << "STRENGTH " <<cr_2->get_strength() <<std::endl;   testing
            //std::cout << "STRENGTH " <<cr_1->get_strength() <<std::endl;   testing
            new_sp = apply_damage(cr_2->get_armor(), dmg, cr_2->get_strength());
            
            //set adjusted strength points to defending creature
            cr_2->set_strength(new_sp);
            
            //check if defending character still has strength
            if (cr_2->get_strength() != 0)
            {
                //round 1 part two, switch attacker and defender
                std::cout << "Creature Attacker: " <<typeid(*cr_2).name() <<std::endl;
                std::cout << "Creature Defender: " <<typeid(*cr_1).name() <<std::endl;
                
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
                //std::cout << "STRENGTH " <<cr_2->get_strength() <<std::endl;  test
                //std::cout << "STRENGTH " <<cr_1->get_strength() <<std::endl;  test
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
        
            std::cout << "Round " << round++ <<std::endl;
            std::cout << "Creature Attacker: " <<typeid(*cr_1).name() <<std::endl;
            std::cout << "Creature Defender: " <<typeid(*cr_2).name() <<std::endl;

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
                std::cout << "Creature Attacker: " <<typeid(*cr_2).name() <<std::endl;
                std::cout << "Creature Defender: " <<typeid(*cr_1).name() <<std::endl;
                
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
        std::cout <<typeid(*cr_2).name() <<" is the WINNER!" <<std::endl <<std::endl;
    }
    else if (cr_2->get_strength() == 0)
    {
        std::cout <<typeid(*cr_1).name() <<" is the WINNER!" <<std::endl <<std::endl;
    }
}