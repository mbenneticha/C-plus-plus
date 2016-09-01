/****************
 * Program: main.cpp
 * Author: Mariam Ben-Neticha
 * Date: 10/1/15
 * Description: This program prompts the user to determine how many times they which to roll the dice. We seed the random number generator so a new value is rolled for each roll of each die. The class functions LoadedDie.cpp and Die.cpp include prining the value of a  single roll of a single die. Using a loop, we can roll each die and print out it's value each time we roll. We continue rolling until we have reached the number of rolls indicated by the user. At this point, the tallies we have within the loop that keep track of the sum of the values rolled by each die (fairScore and loadedScore) will print the total sum of the values rolled by each die.
 ****************/

#include "LoadedDie.hpp"
#include "Die.hpp"

#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>

int main() {
    
    int nRolls;                //variable for the number of rolls
    
    //seed random generator
    srand(static_cast<unsigned int>(time(0)));
    
    //Prompt user for number of times they wish to roll each die.
    std::cout << "How many times will you roll the dice?" << std::endl;
    std::cin >> nRolls;
    std::cout << "You will roll each die " << nRolls << " times." << std::endl;
    
    
    //create Die called fair and initialize score counter, fairScore, to zero.
    Die(fair);
    int fairScore = 0;
    
    //create LoadedDie called loaded and initialize score counter, loadedScore, to zero.
    LoadedDie(loaded);
    int loadedScore = 0;
    
    //use loop to roll each die N number of times (N = nRolls)
    for (int i = 0; i < nRolls; i++)
    {
        
        
        fairScore += fair.rollValue();
        loadedScore += loaded.rollVal();
        
    }
    
    //Print total values of fair die and loaded die.
    std::cout << "Total Fair Value is " << fairScore << "." << std::endl;
    std::cout << "Total Loaded Value is " << loadedScore << "." << std::endl;
    
    return 0;
}
