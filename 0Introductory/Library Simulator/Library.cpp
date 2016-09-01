/********************************************************
 * Program: Library.cpp
 * Author: Mariam Ben-Neticha
 * Date: 08/15/15
 * Description: Library class that checks to see if a book is in the library, if it's been requested by someone, or looks up the location of the book and allows patrons to check books out and return them according to availability. It also keeps track of the amount of days a patron has had the books and calculates fines associated with the checked-out items if applicable.
********************************************************/

#include "Book.hpp"
#include "Patron.hpp"
#include "Library.hpp"
#include <iostream>

//Default Constructor to initialize currentDate to 0.
Library::Library()
{
    currentDate = 0;
}

void Library::addBook(Book* bk)
{
    //function that adds the parameter to holdings.
    holdings.push_back(bk);
}

void Library::addPatron(Patron* pt)
{
    //function that adds the parameters to members.
    members.push_back(pt);
}

Book* Library::getBook(std::string bID)
{
    //returns pointer to the Book corresponding to the ID parameter or NULL if no such Book is in the holdings
    for (int i=0; i<holdings.size(); i++)
    {
        if (holdings.at(i)->getIdCode() == bID)
        {
            return holdings.at(i);
        }
    }
    return 0;
}

Patron* Library::getPatron(std::string pID)
{
    //returns pointer to Patron corresponding to the ID parameter, or NULL if no such Patron is a member.
    for (int i=0; i<members.size(); i++)
    {
        if (members.at(i)->getIdNum() == pID)
        {
            return members.at(i);
        }
    }
    return 0;
}

std::string Library::checkOutBook(std::string pID, std::string bID)
{
    Book* bk = getBook(bID);
    Patron* person = getPatron(pID);
    if (bk == 0)
    {
        return "book not found";
    }
    if (person == 0)
    {
        return "patron not found";
    }
    Locale bkLoc = bk->getLocation();
    switch (bkLoc) {
        case CHECKED_OUT:
            return "book already checked out";
            break;
        case ON_HOLD_SHELF:
            if (person == bk->getRequestedBy())
            {
                bk->setCheckedOutBy(person);
                bk->setDateCheckedOut(currentDate);
                bk->setLocation(CHECKED_OUT);
                bk->setRequestedBy(0);
                person->addBook(bk);
                return "check out successful";
            }
            else
            {
                return "book on hold by other patron";
            }
            break;
        case ON_SHELF:
            bk->setCheckedOutBy(person);
            bk->setDateCheckedOut(currentDate);
            bk->setLocation(CHECKED_OUT);
            person->addBook(bk);
            return "check out successful";
            break;
        default:
            return "invalid";
            break;
    }
}

std::string Library::returnBook(std::string bID)
{
    Book* bk = getBook(bID);
    if (bk == 0)
    {
        return "book not found";
    }
    Locale bkLoc = bk->getLocation();
    if(bkLoc != CHECKED_OUT)
    {
        return "book already in library";
    }
    
    Patron* person = bk->getCheckedOutBy();
    Patron* request = bk->getRequestedBy();
    person->removeBook(bk);
    if (request != 0)
    {
        bk->setLocation(ON_HOLD_SHELF);
    }
    else
    {
        bk->setLocation(ON_SHELF);
    }
    bk->setCheckedOutBy(0);
    return "return successful";
}


std::string Library::requestBook(std::string pID, std::string bID)
{
    std::string state;
    Book* bk = getBook(bID);
    Patron* person = getPatron(pID);
    if (bk == 0)
    {
        state = "book not found";
    }
    if (person == 0)
    {
        state = "patron not found";
    }
   
    Patron* request = bk->getRequestedBy();
    if (request != 0)  //&&(request != person)
    {
        state = "book on hold by other patron";
    }
    else
    {
        bk->setRequestedBy(person);
        if (bk->getLocation() == ON_SHELF)
        {
            bk->setLocation(ON_HOLD_SHELF);
        }
        state = "request successful";
    }
    return state;
}

std::string Library::payFine(std::string pID, double payment)
{
    std::string fine = "payment successful";
    Patron* person = getPatron(pID);
    if (person == 0)
    {
        fine = "patron not found";
    }
    else
    {
        person->amendFine(-payment);
    }
    return fine;
}

void Library::incrementCurrentDate()
{
    currentDate++;
    for (int i = 0; i < members.size(); i++)
    {
        std::vector<Book*> myBooks = members[i]->getCheckedOutBooks();
        for (int j = 0; j < myBooks.size(); j++)
        {
            int dayOne = myBooks[j]->getDateCheckedOut();
            int delta = (currentDate - dayOne);
            if (delta > Book::CHECK_OUT_LENGTH)
            {
                members[i]->amendFine(.1);
            }
        }
    }
}









