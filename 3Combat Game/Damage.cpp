

#include <iostream>

//Calc damage function

int calc_damage(int attack, int defense)
{
    int damage;
    
    damage = attack - defense;
    
    std::cout << "damage " << damage <<std::endl;
    
    return damage;
}
