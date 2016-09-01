

#include <iostream>
#include "List.hpp"
#include "menu.hpp"
#include <vector>
#include <string>

int main()
{
    std::string item_name;
    std::string item_type;
    double item_price;
    int item_quantity;
    
    List grocery_list;
    
    int menu;
    
    do{
        menu = display_menu();
        
        
        if(menu == 1)
        {
            std::cout << "Enter item name to add." <<std::endl;
            std::cin.ignore(80, '\n');
            getline(std::cin, item_name);
            std::cout << "Enter unit type, unit price, and the quantity to add." <<std::endl;
            std::cin >> item_type >> item_price >> item_quantity;
            Item grocery(item_name, item_type, item_price, item_quantity);
            grocery_list.add_item(grocery, item_quantity);
            grocery_list.display_list();
        }
        else if (menu == 2)
        {
            std::cout << "Enter item name to remove." <<std::endl;
            std::cin.ignore(80, '\n');
            getline(std::cin, item_name);
            std::cout << "Enter unit type, unit price, and the quantity to remove." <<std::endl;
            std::cin >> item_type >> item_price >> item_quantity;
            Item grocery(item_name, item_type, item_price, item_quantity);
            grocery_list.remove_item(grocery, item_quantity);
            grocery_list.display_list();
        }
        else if (menu == 3)
        {
            std::cout << "Program End" <<std::endl;
        }
        else
        {
            std::cout << "Please select the number corresponding to the action you wish to complete." << std::endl;
        }
    } while (menu != 3);
    return 0;
}
