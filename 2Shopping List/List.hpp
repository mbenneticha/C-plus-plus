

#ifndef List_hpp
#define List_hpp

#include "Item.hpp"
#include <vector>

class List
{
public:
    List();
    void add_item(Item a, int qnty);
    void remove_item(Item a, int quant);
    double total_price();
    void display_list();
    
    
private:
    std::vector <Item> grocery_list;
    
};

#endif 
