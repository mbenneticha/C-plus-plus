

#include <iostream>


int display_menu()
{
    int menu;
    std::cout <<std::endl;
    std::cout << "Please choose what you would like to do." <<std::endl;
    std::cout << "1: Add an Item." <<std::endl;
    std::cout << "2: Remove an Item." <<std::endl;
    std::cout << "3: Exit." <<std::endl;
    std::cin >> menu;
    
    return menu;
}