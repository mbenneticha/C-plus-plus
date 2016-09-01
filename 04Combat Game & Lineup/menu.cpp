

#include "menu.hpp"

void display_creatures()
{
    std::cout <<"Enter the value corresponding to the creature:" <<std::endl;
    std::cout <<"1: Goblin" <<std::endl;
    std::cout <<"2: Barbarian" <<std::endl;
    std::cout <<"3: Reptile People" <<std::endl;
    std::cout <<"4: Blue Men" <<std::endl;
    std::cout <<"5: The Shadow" <<std::endl;
}



void display_creature_prompt(int num_creat)
{
    //Prompt P1 to enter the types of creatures on their team
    std::cout << "Player 1: Enter " <<num_creat <<" creature types and names for " <<std::endl;
    std::cout << "your team in the order they will fight." <<std::endl;
    std::cout << "Format: Creature # [ENTER] name [ENTER] Creature# [ENTER] name, etc." <<std::endl;
    display_creatures();
}


void display_win_team_points(int p1_points, int p2_points)
{
    if (p1_points > p2_points)
    {
        std::cout <<"Player 1 wins with " <<p1_points <<"!" <<std::endl;
        std::cout <<"Player 2 lost with " <<p2_points <<"." <<std::endl;
    }
    else
    {
        std::cout <<"Player 2 wins with " <<p2_points <<"!" <<std::endl;
        std::cout <<"Player 1 lost with " <<p1_points <<"." <<std::endl;
    }
}