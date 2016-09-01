

#include <iostream>
#include "Stacknode.hpp"
#include "Queuenode.hpp"
#include "menu.hpp"


int main()
{
    int menu;
    Stacknode stack_list;
    int val;
    Queuenode queue_list;
    int value;
    
    
    do
    {
        menu = display_menu();
        
        if (menu == 1)
        {
            std::cout << "Enter an integer to add to the stack list." <<std::endl;
            std::cin >> val;
            
            stack_list.add(val);
            
           /* std::cout << "Now adding pre-determined values to list." <<std::endl;
            std::cout << "Values are 7, 15, 100, and 30." <<std::endl;
            
            stack_list.add(7);
            stack_list.add(15);
            stack_list.add(100);
            stack_list.add(30);
            
            std::cout << "Enter an integer to add to end of stack list." <<std::endl;
            std::cin >> val;
            
            stack_list.add(val);
            */
        }
        else if (menu == 2)
        {
            stack_list.remove();
        }
        else if (menu == 3)
        {
            std::cout << "Enter an integer to add to start of stack list." <<std::endl;
            std::cin >> value;
            
            queue_list.add(value);
            
            /*
            std::cout << "Now adding pre-determined values to list." <<std::endl;
            std::cout << "Values are 7, 15, 100, and 30." <<std::endl;
            
            queue_list.add(7);
            queue_list.add(15);
            queue_list.add(100);
            queue_list.add(30);
            
            
            std::cout << "Enter an integer to add to end of stack list." <<std::endl;
            std::cin >> value;
            
            queue_list.add(value);
            */
        }
        else if (menu == 4)
        {
            queue_list.remove();
        }
        else if (menu == 5)
        {
            std::cout << "Program End." <<std::endl;
        }
        else
        {
            std::cout << "Please select the number corresponding to the action you wish to complete." << std::endl;
        }
    } while (menu != 5);
    
    return 0;
}
