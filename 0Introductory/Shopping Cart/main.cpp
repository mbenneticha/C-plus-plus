//
//  main.cpp
//  itemTest.cpp

//

#include <iostream>
#include "ShoppingCart.hpp"


int main() {
    
    //variables
    string n;
    int q;
    double p;
    double diff;
    //objects
    ShoppingCart sc1;
    
    //Pre-entered items; Total = 2201.68
    /*
    Item a("affidavit", 179.99, 12);
    Item b("Bildungsroman", 0.7, 20);
    Item c("capybara", 4.5, 6);
    Item d("dirigible", 0.05, 16);
     
    sc1.addItem(&a);
    sc1.addItem(&b);
    sc1.addItem(&c);
    sc1.addItem(&d);
     
    diff = sc1.totalPrice();
    
    cout << "total price is $" << diff <<endl;
    */
    
    //Self entered item
    cout << "Enter a name for your item" <<endl;
    cin >> n;
    cout << "enter price" <<endl;
    cin >> p;
    cout <<"enter quanitity" <<endl;
    cin >> q;
    cout << endl;
    
    Item mine(n, p, q);
    
    sc1.addItem(&mine);
    
    diff = sc1.totalPrice();
    cout << "total price for " << n <<" is $" << diff <<endl;
    
    return 0;
}
