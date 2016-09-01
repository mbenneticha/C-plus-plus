
#include <iostream>
#include "Die.hpp"
#include "LoadedDie.hpp"
#include "Game.hpp"
#include <cstdlib>
#include <cmath>
#include <ctime>


int main()
{
    // declare variables and prompt user for inputs
    unsigned seed;
    seed = time_t(0);
    srand(seed);
    
    int sides;
    int p1;
    int p2;
    int num_rounds;
    int p1_current_roll;
    int p2_current_roll;
    
    std::cout << "How many sides do you want the dice to have?" << std::endl;
    std::cin >> sides;
    
    switch (sides) {
        case 0:
            std::cout << "How many sides do you want the dice to have?" << std::endl;
            std::cin >> sides;
            break;
        case 1:
            std::cout << "How many sides do you want the dice to have?" << std::endl;
            std::cin >> sides;
            break;
        default:
            break;
    }
    
    std::cout << "Which type of die will player one use?" << std::endl;
    std::cout << "1: Fair Die" << std::endl;
    std::cout << "2: Loaded Die" << std::endl;
    std::cin >> p1;
    
    
    std::cout << "Which type of die will player two use?" << std::endl;
    std::cout << "1: Fair Die" << std::endl;
    std::cout << "2: Loaded Die" << std::endl;
    std::cin >> p2;
    
    Game my_game;
    Die p1_fair_die(sides);
    Die p2_fair_die(sides);
    LoadedDie p1_loaded_die(sides);
    LoadedDie p2_loaded_die(sides);
    
    my_game.die_type(p1);
    my_game.die_type(p2);

    
    std::cout << "How may rounds would you like to play?" << std::endl;
    std::cin >> num_rounds;
    
    switch (num_rounds) {
        case 0:
            std::cout << "How may rounds would you like to play?" << std::endl;
            std::cin >> num_rounds;
            break;
        default:
            break;
    }

    
    // rolls p1_die and prints results
    for (int counter = 0; counter < num_rounds; counter++)
    {
        //roll player 1 die
        p1_current_roll = (my_game.die_type(p1) == true) ? p1_fair_die.Roll() : p1_loaded_die.Roll();
        
        //roll player 2 die
        p2_current_roll = (my_game.die_type(p2) == true) ? p2_fair_die.Roll() : p2_loaded_die.Roll();

        //keep track of game score, winner, and rounds played
        my_game.war_game(p1_current_roll, p2_current_roll, num_rounds);
    }
    return 0;
}

