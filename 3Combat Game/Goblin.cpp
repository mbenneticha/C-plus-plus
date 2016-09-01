
#include "Goblin.hpp"
#include <iostream>


Goblin::Goblin() : Creature(8, 3, 6, 6, 2, 1)
{
}


//attack roll function
int Goblin::attack()
{
    int attack_roll = 0;
    
    
    //get pointer to array of dice
    Die *att_a = get_att_die();
    
    
    //roll each die 1X
    for (int i = 0; i < get_att_dice(); i++)
    {
        attack_roll += att_a[i].Roll();
    }
    
    if (attack_roll == 12)
    {
        attack_roll = 0;
        std::cout << "Achilles cut!" <<std::endl;
    }
    
    std::cout << "Goblin Attack Roll: " << attack_roll <<std::endl;
    return attack_roll;
}


int Goblin::defense()
{
    int defense_roll = 0;
    
    
    //get pointer to array of dice
    Die *def_a = get_def_die();
    
    
    //roll each die 1X
    for (int i = 0; i < get_def_dice(); i++)
    {
        defense_roll += def_a[i].Roll();
    }
    
    std::cout << "Goblin Defense Roll: " << defense_roll <<std::endl;
    return defense_roll;
    return 0;
}

