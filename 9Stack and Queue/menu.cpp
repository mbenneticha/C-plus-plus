

#include "menu.hpp"
#include <iostream>


int display_menu()
{
    int menu;
    std::cout << "Please choose what you would like to do." <<std::endl;
    std::cout << "1: Add to Stack List." <<std::endl;
    std::cout << "2: Remove from Stack List." <<std::endl;
    std::cout << "3: Add to Queue List." <<std::endl;
    std::cout << "4: Remove from Queue List." <<std::endl;
    std::cout << "5: Exit." <<std::endl;
    std::cin >> menu;
    return menu;
}