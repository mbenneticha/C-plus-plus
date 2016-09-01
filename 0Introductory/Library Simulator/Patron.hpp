/********************************************************
 * Program: Patron.hpp
 * Author: Mariam Ben-Neticha
 * Date: 08/15/15
 * Description: Defines the class patron and the data members that will be used in the class.
********************************************************/

#ifndef PATRON_HPP
#define PATRON_HPP

#include <string>
#include <vector>
#include "Book.hpp"

class Patron
{
private:
    std::string idNum;
    std::string name;
    std::vector<Book*> checkedOutBooks;
    double fineAmount;
public:
    Patron(std::string idn, std::string n);
    std::string getIdNum();
    std::string getName();
    std::vector<Book*> getCheckedOutBooks();
    void addBook(Book* b);
    void removeBook(Book* b);
    double getFineAmount();
    void amendFine(double amount);
};

#endif
