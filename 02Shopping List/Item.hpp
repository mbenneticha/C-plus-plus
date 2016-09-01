

#ifndef Item_hpp
#define Item_hpp

#include <string>

class Item
{
public:
    Item();
    Item(std::string name, std::string type, double price, int quantity);
    
    bool operator== (const Item& obj);
    
    void display_item();
    double extended_price();
    
    void set_name(std::string name);
    void set_type(std::string type);
    void set_price(double price);
    void set_quantity(int quantity);
    
    std::string get_name();
    std::string get_type();
    double get_price();
    int get_quantity();
    
private:
    std::string unit_name;
    std::string unit_type;
    double unit_price;
    int unit_quantity;
};

#endif
