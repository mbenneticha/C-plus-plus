
#include "Stack.hpp"
#include <iostream>



Stacknode::Stacknode()
{
    head = NULL;
}



void Stacknode::add(Creature* Creat, std::string Name, std::string Team)
{
    stack_node *temp = new stack_node;
    temp->creature = Creat;
    temp->name = Name;
    temp->team = Team;
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




Stacknode::stack_node * Stacknode::removeNode()
{
    if (head == NULL)
    {
        return NULL;
    }
    else if (head->next == NULL)
    {
        stack_node* sn = new stack_node;
        sn->name = head->name;
        sn->creature = head->creature;
        sn->team = head->team;
        delete head;
        head = NULL;
        
        return sn;
    }
    else
    {
        stack_node* sn = new stack_node;
        sn->name = head->name;
        sn->creature = head->creature;
        sn->team = head->team;
        stack_node *temp = head;
        head = head->next;
        delete temp;
        
        return sn;
    }
}
