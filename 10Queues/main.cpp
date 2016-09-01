
#include "Queue.hpp"
#include <iostream>

int main() {
    
    int menu;
    Queue my_queue;
    int val;
    
    do {
        std::cout << "Please choose what you would like to do." <<std::endl;
        std::cout << "1: Add a Value." <<std::endl;
        std::cout << "2: Remove a Value." <<std::endl;
        std::cout << "3: Display Queue Contents." <<std::endl;
        std::cout << "4: Exit." <<std::endl;
        std::cin >> menu;
    
        if (menu == 1)
        {
            std::cout << "Enter an integer to add to the list." <<std::endl;
            std::cin >> val;
            
            my_queue.addBack(val);
        }
        else if (menu == 2)
        {
            my_queue.removeFront();
        }
        else if (menu == 3)
        {
            my_queue.getFront();
        }
        else if (menu == 4)
        {
            std::cout << "Program End." <<std::endl;
        }
        else
        {
            std::cout << "Please select the number corresponding to the action you wish to complete." << std::endl;
        }
        
        } while (menu != 4);
    
    return 0;
}
