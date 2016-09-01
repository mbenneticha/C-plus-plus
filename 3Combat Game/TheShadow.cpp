

#include "TheShadow.hpp"

Shadow::Shadow() : Creature(12, 0, 10, 6, 2, 1)
{
    
}


int Shadow::get_armor()
{
    std::cout << "The Shadow's armor: " <<std::endl;
    int chance = (rand() % 2);
    if (chance == 1)
    {
        std::cout << "The Shadow is safe. "<<std::endl;
        return -1;
    }
    else
    {
        std::cout << "The Shadow is damaged. "<<std::endl;
        return 0;
    }

    
}

//attack roll function
int Shadow::attack()
{
    int attack_roll = 0;
    
    
    //get pointer to array of dice
    Die *att_a = get_att_die();
    
    
    //roll each die 1X
    for (int i = 0; i < get_att_dice(); i++)
    {
        attack_roll += att_a[i].Roll();
    }
    
    std::cout << "Shadow Attack Roll: " << attack_roll <<std::endl;
    return attack_roll;
}


int Shadow::defense()
{
    int defense_roll = 0;
    
    
    //get pointer to array of dice
    Die *def_a = get_def_die();
    
    
    //roll each die 1X
    for (int i = 0; i < get_def_dice(); i++)
    {
        defense_roll += def_a[i].Roll();
    }
    
    std::cout << "Shadow Defense Roll: " << defense_roll <<std::endl;
    return defense_roll;
    return 0;
}

