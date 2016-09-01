/********************************************************
 * Program: Book.cpp
 * Author: Mariam Ben-Neticha
 * Date: 08/15/15
 * Description: Functions to find book titles, ID numbers, locations, and authors. Also keeps track of whether a book has been requested, checked-out, and the dates a book was checked out.
********************************************************/


#include "Book.hpp"


//Constructor

Book::Book(std::string idc, std::string t, std::string a)
{
    checkedOutBy = 0;
    requestedBy = 0;
    setLocation(ON_SHELF);  //new book is on shelf
    title = t;
    author = a;
    idCode = idc;
    dateCheckedOut = 0;
}


//Setters and Getters
std::string Book::getIdCode()
{
    return idCode;
}

std::string Book::getTitle()
{
    return title;
}

std::string Book::getAuthor()
{
    return author;
}

void Book::setLocation(Locale l)
{
    location = l;
}

Locale Book::getLocation()
{
    return location;
}

void Book::setCheckedOutBy(Patron* x)
{
    checkedOutBy = x;
}

Patron* Book::getCheckedOutBy()
{
    return checkedOutBy;
}

void Book::setRequestedBy(Patron* y)
{
    requestedBy = y;
}

Patron* Book::getRequestedBy()
{
    return requestedBy;
}

void Book::setDateCheckedOut(int d)
{
    dateCheckedOut = d;
}

int Book::getDateCheckedOut()
{
    return dateCheckedOut;
}

int Book::getCheckOutLength()   //not used; in progress
{
    return 0;
}




