
#include "menu.hpp"
#include "CreateFiles.hpp"
#include "SearchZero.hpp"
#include "SortFiles.hpp"
#include "SearchBinary.hpp"
#include <iostream>
#include <string>

int main() {

    int menu;
    
    
    do {
        menu = main_menu();
        
        std::string file_name;
        std::string early;
        std::string mid;
        std::string end;
        std::string early_sort;
        std::string mid_sort;
        std::string end_sort;
        std::cout << "Enter file name." <<std::endl;
        std::cin >> file_name;
        std::cout << "Enter early-copy name." <<std::endl;
        std::cin >> early;
        std::cout << "Enter mid-copy name." <<std::endl;
        std::cin >> mid;
        std::cout << "Enter end-copy name." <<std::endl;
        std::cin >> end;
        std::cout << "Enter early-sort name." <<std::endl;
        std::cin >> early_sort;
        std::cout << "Enter mid-sort name." <<std::endl;
        std::cin >> mid_sort;
        std::cout << "Enter end-sort name." <<std::endl;
        std::cin >> end_sort;
        
        if (menu == 1)
        {
            create_file(file_name, early, mid, end);
        }
        else if ( menu == 2)
        {
            int val;
            std::cout << "Enter target integer to search [0-9]." <<std::endl;
            std::cin >> val;

            search_value(val, early, mid, end);
        }
        else if (menu == 3)
        {
            std::cout <<"Sorting files..." <<std::endl;
            bubble_sort(early, mid, end, early_sort, mid_sort, end_sort);
        }
        else if (menu == 4)
        {
            int value;
            std::cout << "Enter target integer to search [0-9]." <<std::endl;
            std::cin >> value;
            
            search_redux(value, early_sort, mid_sort, end_sort);
        }
        else if (menu == 5)
        {
            std::cout <<"Program End." <<std::endl;
        }
        else
            std::cout <<"Please selest the number corresponding to the action you wish to complete." <<std::endl;
    } while (menu != 5);
    
    return 0;
}
