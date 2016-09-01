//FILO

#include "Stacknode.hpp"
#include <iostream>



Stacknode::Stacknode()
{
    head = NULL;
}


void Stacknode::add(int Value)
{
    stack_node *temp = new stack_node;
    temp->data = Value;
    temp->next = NULL;
    if (head == NULL)
    {
        head = temp;
    }
    else
    {
        temp->next = head;
        head = temp;
    }
}


int Stacknode::remove()
{
    if (head == NULL)
    {
        std::cout << "The list is empty." <<std::endl;
    }
    else if (head->next == NULL)
    {
        int return_value = head->data;
        delete head;
        head = NULL;
        std::cout << "Node (value = " << return_value << ") removed." <<std::endl;
        return return_value;
    }
    else
    {
        stack_node *temp = head;
        int return_value = temp->data;
        head = head->next;
        delete temp;
        
        std::cout << "Node (value = " << return_value << ") removed." <<std::endl;
        return return_value;
    }
    return 0;
}


