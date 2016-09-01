//
//

#ifndef SHOPPINGCART_HPP
#define SHOPPINGCART_HPP
#include "Item.hpp"

class ShoppingCart
{
private:
    int arrayEnd;
    Item* array[100];
    
public:
    //Constructors
    ShoppingCart();
    
    //ShoppingCart(Point, Point);
    //Functions
    void addItem(Item *a);
    double totalPrice();
    
};
#endif