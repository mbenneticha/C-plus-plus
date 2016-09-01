
#include "BlueMen.hpp"

BlueMen::BlueMen() : Creature(12, 3, 10, 6, 2, 3)
{
    
}


//attack roll function
int BlueMen::attack()
{
    int attack_roll = 0;
    
    
    //get pointer to array of dice
    Die *att_a = get_att_die();
    
    
    //roll each die 1X
    for (int i = 0; i < get_att_dice(); i++)
    {
        attack_roll += att_a[i].Roll();
    }
    return attack_roll;
}


int BlueMen::defense()
{
    int defense_roll = 0;
    
    
    //get pointer to array of dice
    Die *def_a = get_def_die();
    
    
    //roll each die 1X
    for (int i = 0; i < get_def_dice(); i++)
    {
        defense_roll += def_a[i].Roll();
    }
    return defense_roll;
    return 0;
}

std::string BlueMen::identify()
{
    return "Blue Men";
}
