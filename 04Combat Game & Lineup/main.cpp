
#include "menu.hpp"
#include "Queue.hpp"
#include "Stack.hpp"
#include "Die.hpp"
#include "Combat.hpp"
#include "Creature.hpp"
#include "Goblin.hpp"
#include "Barbarian.hpp"
#include "Reptile.hpp"
#include "BlueMen.hpp"
#include "Shadow.hpp"

#include <iostream>
#include <string>

int main() {
    
    
    
    Queuenode p1_lineup;
    Queuenode p1_lineup_val;
    
    Queuenode p2_lineup;
    Queuenode p2_lineup_val;
    
    //value to store number of creatures on each team
    int num_creat;
    
    //Prompt user for number of creatures on each team
    std::cout << "Enter the number of creatures each player will choose." <<std::endl;
    std::cin >> num_creat;
    
    display_creature_prompt(num_creat);
    int value;
    std::string name;
    
    // Instantiate P1 Creatures
    for (int i = 0; i < num_creat; i++)
    {
        std::cin >> value;
        p1_lineup_val.add_lineup_val(value);
        
        if (value == 1)
        {
            std::cin >> name;
            
            Creature* p1_creature = new Goblin();
            p1_lineup.add_lineup(p1_creature, name, p1_creature->identify());
        }
        else if (value == 2)
        {
            std::cin >> name;
            
            Creature* p1_creature = new Barbarian();
            p1_lineup.add_lineup(p1_creature, name, p1_creature->identify());
        }
        else if (value == 3)
        {
            std::cin >> name;
            
            Creature* p1_creature = new Reptile();
            p1_lineup.add_lineup(p1_creature, name, p1_creature->identify());
        }
        else if (value == 4)
        {
            std::cin >> name;
            
            Creature* p1_creature = new BlueMen();
            p1_lineup.add_lineup(p1_creature, name, p1_creature->identify());
        }
        else if (value == 5)
        {
            std::cin >> name;
            
            Creature* p1_creature = new Shadow();
            p1_lineup.add_lineup(p1_creature, name, p1_creature->identify());
        }
    }

    
    display_creature_prompt(num_creat);
    int p2_value;
    std::string p2_name;
    
    // Instantiate P2 Creatures
    for (int i = 0; i < num_creat; i++)
    {
        std::cin >> p2_value;
        p2_lineup_val.add_lineup_val(p2_value);
        
        if (p2_value == 1)
        {
            std::cin >> p2_name;
            
            Creature* p2_creature = new Goblin();
            p2_lineup.add_lineup(p2_creature, p2_name, p2_creature->identify());
        }
        else if (p2_value == 2)
        {
            std::cin >> p2_name;
            
            Creature* p2_creature = new Barbarian();
            p2_lineup.add_lineup(p2_creature, p2_name, p2_creature->identify());
        }
        else if (p2_value == 3)
        {
            std::cin >> p2_name;
            
            Creature* p2_creature = new Reptile();
            p2_lineup.add_lineup(p2_creature, p2_name, p2_creature->identify());
        }
        else if (p2_value == 4)
        {
            std::cin >> p2_name;
            
            Creature* p2_creature = new BlueMen();
            p2_lineup.add_lineup(p2_creature, p2_name, p2_creature->identify());
        }
        else if (p2_value == 5)
        {
            std::cin >> p2_name;
            
            Creature* p2_creature = new Shadow();
            p2_lineup.add_lineup(p2_creature, p2_name, p2_creature->identify());
        }
    }

    Stacknode loser_pile;
    Combat tournament;
    
    int winner;
    int rounds = 0;
    int p1_points = 0;
    int p2_points = 0;
    int is_empty = 0;
    
    do {
        rounds++;
        
        Creature *p1 = p1_lineup.get_Front_Creature();
        Creature *p2 = p2_lineup.get_Front_Creature();
        
        winner = tournament.tournament(p1, p2);
        
        if (winner == 1)        //p1 creature wins round
        {
            p1_points++;
            std::cout <<"Round " <<rounds <<":" <<std::endl;
            std::cout <<p1_lineup.get_Front_Type() <<" " <<p1_lineup.get_Front_Name() <<" won!" <<std::endl;
            std::cout <<p2_lineup.get_Front_Type() <<" " <<p2_lineup.get_Front_Name() <<" lost :-(" <<std::endl <<std::endl;
            
            //replenish winner's points
            tournament.replenish_points(p1);
            
            //add loser to loser pile
            loser_pile.add(p2_lineup.get_Front_Creature(), p2_lineup.get_Front_Name(), "Team 2");
            
            //check if team 2 is all DEAD
            is_empty = p2_lineup.remove_lineup();
            
            //if no more creatures in team 2
            if (is_empty == -1)
            {
                break;
            }
            else
            {
                //move winner to end of their queue
                p1_lineup.move_Back();
            }
        }
        else if (winner == 2)        //p2 creature wins round
        {
            p2_points++;
            std::cout <<"Round " <<rounds <<":" <<std::endl;
            std::cout <<p2_lineup.get_Front_Type() <<" " <<p2_lineup.get_Front_Name() <<" won!" <<std::endl;
            std::cout <<p1_lineup.get_Front_Type() <<" " <<p1_lineup.get_Front_Name() <<" lost :-(" <<std::endl <<std::endl;
            
            //replenish winner's points
            tournament.replenish_points(p2);
            
            loser_pile.add(p1_lineup.get_Front_Creature(), p1_lineup.get_Front_Name(), "Team 1");
            
            is_empty = p1_lineup.remove_lineup();
            
            if (is_empty != -1)
            {
                p2_lineup.move_Back();
            }
        }
    } while (is_empty != -1);
    
    
    
    //Print Winning Team + Team Points
    display_win_team_points(p1_points, p2_points);
    
    
    
    //Print Placements
    std::string team;
    std::string creature_type;
    std::string creature_name;
    
    //Print First Place (team 2)
    if (p1_lineup.is_Empty() == -1)
    {
        //P2 has 1st place winner;
        std::cout <<"1st Place: Team 2 " <<p2_lineup.get_Front_Type() <<" " <<p2_lineup.get_Front_Name() <<std::endl;
        p2_lineup.remove_lineup();
        
        //Print Second Place
        if (p2_lineup.is_Empty() == -1)
        {
            Stacknode::stack_node *loser = loser_pile.removeNode();
            std::string team = loser->team;
            std::string creature_type = loser->creature->identify();
            std::string creature_name = loser->name;
            std::cout <<"2nd Place: " <<team <<" " <<creature_type <<" " <<creature_name <<std::endl;;
        }
        else
        {
            std::cout <<"2nd Place: Team 2 " <<p2_lineup.get_Front_Type() <<" " <<p2_lineup.get_Front_Name() <<std::endl;
            p2_lineup.remove_lineup();
        }
        
        //Print Third Place
        if (p2_lineup.is_Empty() == -1)
        {
            Stacknode::stack_node *loser = loser_pile.removeNode();
            std::string team = loser->team;
            std::string creature_type = loser->creature->identify();
            std::string creature_name = loser->name;
            std::cout <<"3rd Place: " <<team <<" " <<creature_type <<" " <<creature_name <<std::endl;;
        }
        else
        {
            std::cout <<"3rd Place: Team 2 " <<p2_lineup.get_Front_Type() <<" " <<p2_lineup.get_Front_Name() <<std::endl;
            p2_lineup.remove_lineup();
        }
    }
    //Print First Place (team 1)
    else if (p2_lineup.is_Empty() == -1)
    {
        //p1 has first place winner;
        std::cout <<"1st Place: Team 1 " <<p1_lineup.get_Front_Type() <<" " <<p1_lineup.get_Front_Name() <<std::endl;
        p1_lineup.remove_lineup();
        
        //Print Second Place
        if (p1_lineup.is_Empty() == -1)
        {
            Stacknode::stack_node *loser = loser_pile.removeNode();
            std::string team = loser->team;
            std::string creature_type = loser->creature->identify();
            std::string creature_name = loser->name;
            std::cout <<"2nd Place: " <<team <<" " <<creature_type <<" " <<creature_name <<std::endl;;
        }
        else
        {
            std::cout <<"2nd Place: Team 1 " <<p1_lineup.get_Front_Type() <<" " <<p1_lineup.get_Front_Name() <<std::endl;
            p1_lineup.remove_lineup();
        }
        
        //Print Third Place
        if (p1_lineup.is_Empty() == -1)
        {
            Stacknode::stack_node *loser = loser_pile.removeNode();
            std::string team = loser->team;
            std::string creature_type = loser->creature->identify();
            std::string creature_name = loser->name;
            std::cout <<"3nd Place: " <<team <<" " <<creature_type <<" " <<creature_name <<std::endl;;
        }
        else
        {
            std::cout <<"3rd Place: Team 1 " <<p1_lineup.get_Front_Type() <<" " <<p1_lineup.get_Front_Name() <<std::endl;
            p1_lineup.remove_lineup();
        }
    }

    
    //Option to display remaining rankings
    int display;
    std::cout <<"Display the remaining rankings? [1 = YES; 0 = NO]..." <<std::endl;
    std::cin >> display;
    
    if (display == 1) {
        int counter = 3;
        if ((p1_lineup.is_Empty() == -1) && (p2_lineup.is_Empty() == -1))
        {
            bool empty = false;
            while (!empty) {
                counter++;
                Stacknode::stack_node *loser = loser_pile.removeNode();
                empty = (loser == 0);
                if (!empty){
                    team = loser->team;
                    creature_type = loser->creature->identify();
                    creature_name = loser->name;
                    std::cout <<counter <<"th Place: " <<team <<" " <<creature_type <<" " <<creature_name <<std::endl <<std::endl;
                }
            }
        }
        else
        {
            if (p1_points > p2_points)
            {
                is_empty = 0;
                do {
                    counter++;
                    std::cout <<counter <<"th Place: Team 1 " <<p1_lineup.get_Front_Type() <<" " <<p1_lineup.get_Front_Name() <<std::endl <<std::endl;
                    is_empty = p1_lineup.remove_lineup();
                    
                } while (is_empty != -1);
                
                if (is_empty == -1)
                {
                    bool empty = false;
                    while (!empty)
                    {
                        counter++;
                        Stacknode::stack_node *loser = loser_pile.removeNode();
                        empty = (loser == 0);
                        if (!empty)
                        {
                            team = loser->team;
                            creature_type = loser->creature->identify();
                            creature_name = loser->name;
                            std::cout <<counter <<"th Place: " <<team <<" " <<creature_type <<" " <<creature_name <<std::endl <<std::endl;
                        }
                    }
                }
            }
            else if (p2_points > p1_points)
            {
                is_empty = 0;
                do
                {
                    counter++;
                    std::cout <<counter <<"th Place: Team 2 " <<p2_lineup.get_Front_Type() <<" " <<p2_lineup.get_Front_Name() <<std::endl <<std::endl;
                    
                    is_empty = p2_lineup.remove_lineup();
                    
                } while (is_empty != -1);
                
                if (is_empty == -1)
                {
                    bool empty = false;
                    while (!empty)
                    {
                        counter++;
                        Stacknode::stack_node *loser = loser_pile.removeNode();
                        empty = (loser == 0);
                        if (!empty)
                        {
                            team = loser->team;
                            creature_type = loser->creature->identify();
                            creature_name = loser->name;
                            std::cout <<counter <<"th Place: " <<team <<" " <<creature_type <<" " <<creature_name <<std::endl <<std::endl;
                        }
                    }
                }
            }
        }
    }
    return 0;
}
