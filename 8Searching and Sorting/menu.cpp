
#include "menu.hpp"
#include <iostream>


int main_menu()
{
    int menu;
    std::cout << "Please choose an action." <<std::endl;
    std::cout << "1: Create data files." <<std::endl;
    std::cout << "2: Search for target value." <<std::endl;
    std::cout << "3: Sort data files." <<std::endl;
    std::cout << "4: Search for target value(redux)." <<std::endl;
    std::cout << "5: Exit." <<std::endl;
    std::cin >> menu;
    return menu;
}



