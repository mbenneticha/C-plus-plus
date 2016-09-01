

#include "List.hpp"
#include <vector>
#include <iostream>

//Constructor
List::List()
{
}

//function to add an item to the list
void List::add_item(Item a, int qnty)
{
    if (grocery_list.size() == 0)
    {
        grocery_list.push_back(a);
    }
    else
    {
        for (std::vector<Item>::iterator it = grocery_list.begin(); it != grocery_list.end(); it++)
        {
            if (*it == a)
            {
                int my_qnty = it->get_quantity();
                if (qnty >= 0)
                {
                    my_qnty += qnty;
                    it->set_quantity(my_qnty);
                }
                return;
            }
        }
        grocery_list.push_back(a);
    }
}

//func to remove item from list
void List::remove_item(Item a, int quant)
{
    for (std::vector<Item>::iterator it = grocery_list.begin(); it != grocery_list.end(); it++)
    {
        if (*it == a)
        {
            int my_quant = it->get_quantity();
            if (my_quant <= quant)
            {
                grocery_list.erase(it);
            }
            else
            {
                my_quant -= quant;
                it->set_quantity(my_quant);
            }
            return;
        }
    }
}

//function to calculate total price
double List::total_price()
{
    double price = 0;
    for (int i = 0; i < grocery_list.size() ; i++)
    {
        price += grocery_list.at(i).extended_price();
    }
    return price;
}

//func diplays full shopping list
void List::display_list()
{
    std::cout << "Your shopping list contains the following items: " <<std::endl;
    for (int i = 0; i < grocery_list.size() ; i++)
    {
        grocery_list.at(i).display_item();
        std::cout <<"Extended Price is: $" << grocery_list.at(i).extended_price() <<std::endl;
        std::cout <<std::endl;
    }
    std::cout << "Total is: $" << total_price() <<std::endl;
}

