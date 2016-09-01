
#include <iostream>
#include <iomanip>
#include "Item.hpp"

//Constructor

Item::Item()
{
    set_name("");
    set_type("");
    set_price(0.0);
    set_quantity(0);
}

Item::Item(std::string name, std::string type, double price, int quantity)
{
    set_name(name);
    set_type(type);
    set_price(price);
    set_quantity(quantity);
}

//Overload operator
bool Item::operator== (const Item& obj)
{
    return ((unit_name == obj.unit_name) &&
            (unit_type == obj.unit_type) &&
            (unit_price == obj.unit_price)
            );
}

//calculate item's exteneded price
double Item::extended_price()
{
    return (get_price()*get_quantity());
}

//displays the item's information
void Item::display_item()
{
    std::cout << "Item Name is:      " << unit_name <<std::endl;
    std::cout << "Item Unit is:      " << unit_type <<std::endl;
    std::cout << "Unit Price is:     $" << unit_price <<std::endl;
    std::cout << "Item Quantity is:  " << unit_quantity <<std::endl;
}

//Setters
void Item::set_name(std::string name)
{
    unit_name = name;
}
void Item::set_type(std::string type)
{
    unit_type = type;
}
void Item::set_price(double price)
{
    unit_price = price;
}
void Item::set_quantity(int quantity)
{
    unit_quantity = quantity;
}


//Getters
std::string Item::get_name()
{
    return unit_name;
}
std::string Item::get_type()
{
    return unit_type;
}
double Item::get_price()
{
    return unit_price;
}
int Item::get_quantity()
{
    return unit_quantity;
}