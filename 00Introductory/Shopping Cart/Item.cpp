
//

#include "Item.hpp"

//Constructor
//Item() is default constructor, set name to "", price to 0.0, quantity to 0 to be passed values by calling set functions
Item::Item(){
    setName("");
    setPrice(0.0);
    setQuantity(0);
}

Item::Item(std::string n, double p, int q){
    setName(n);
    setPrice(p);
    setQuantity(q);
}

//Setters
//Setter Functions. Updates the name, price, and quantity member variables.
void Item::setName(std::string n){
    name = n;
}

void Item::setPrice(double p){
    price = p;
}

void Item::setQuantity(int q){
    quantity = q;
}

//Getters
std::string Item::getName() {
    return name;
}

double Item::getPrice() {
    return price;
}

int Item::getQuantity() {
    return quantity;
}

