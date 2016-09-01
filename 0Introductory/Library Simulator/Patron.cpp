/********************************************************
 * Program: Patron.cpp
 * Author: Mariam Ben-Neticha
 * Date: 08/15/15
 * Description: Functions to allow Librarian to find a Patron's record: their ID number, Books checked out, and any fines they may have accumulated.
********************************************************/


#include "Patron.hpp"
#include "Book.hpp"
#include <iostream>

Patron::Patron(std::string idn, std::string n)
{
    idNum = idn;
    name = n;
    fineAmount = 0;
}

std::string Patron::getIdNum()
{
    return idNum;
}

std::string Patron::getName()
{
    return name;
}

std::vector<Book*> Patron::getCheckedOutBooks()
{
    return checkedOutBooks;
}

void Patron::addBook(Book* b)
{
    //function that adds the specified book to checkedOutBooks
    checkedOutBooks.push_back(b);
}

void Patron::removeBook(Book* b)
{
    //function that removes the specified book from checkOutBooks
    for (int i=0; i<checkedOutBooks.size(); i++)
    {
        if (checkedOutBooks[i] == b)
        {
            checkedOutBooks.erase(checkedOutBooks.begin()+i);
        }
    }
}

double Patron::getFineAmount()
{
    return fineAmount;
}

void Patron::amendFine(double amount)
{
    fineAmount += amount;
}






