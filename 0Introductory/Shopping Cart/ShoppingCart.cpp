//

#include "ShoppingCart.hpp"


//Default Constructor
ShoppingCart::ShoppingCart(){
    arrayEnd = 0;
    for (int i = 0; i < 100; i++) {
        array[i] = 0;
    }
}


    
//Function addItem
void ShoppingCart::addItem(Item *a){
     array[arrayEnd] = a;
     arrayEnd++;
    
    }

//Function totalPrice
double ShoppingCart::totalPrice() {
    double price = 0;
    
    for (int i = 0; i < arrayEnd; i++) {
        price += array[i]->getPrice() * array[i]->getQuantity();
        
    }
    

    return price;
    }

