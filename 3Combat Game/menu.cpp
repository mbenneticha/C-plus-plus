

#include "menu.hpp"
#include <iostream>


int main_menu()
{
    int menu;
    std::cout << "Please choose an action." <<std::endl;
    std::cout << "1: Combat." <<std::endl;
    std::cout << "2: Exit." <<std::endl;
    std::cin >> menu;
    return menu;
}

int combat_menu()
{
    int creature;
    
    std::cout << "Please choose a Creature for combat." <<std::endl;
    std::cout << "1: Goblin." <<std::endl;
    std::cout << "2: Barbarian." <<std::endl;
    std::cout << "3: Reptile People." <<std::endl;
    std::cout << "4: Blue Men." <<std::endl;
    std::cout << "5: The Shadow." <<std::endl;
    std::cin >> creature;
    return creature;
}

