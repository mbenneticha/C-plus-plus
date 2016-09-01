//

#ifndef ITEM_HPP
#define ITEM_HPP
#include <string>
using namespace std;

class Item
{
private:
    string name;
    double price;
    int quantity;
    
public:
    //Constructors
    Item();
    Item(string n, double p, int q);
    
    //Setters
    void setName(string n);
    void setPrice(double p);
    void setQuantity(int q);
    
    //Getters
    string getName();
    double getPrice();
    int getQuantity();
    
};
#endif