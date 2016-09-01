

#ifndef Stack_hpp
#define Stack_hpp

#include "Creature.hpp"
#include <stdio.h>
#include <iostream>
#include <string>



class Stacknode
{
public:
    struct stack_node
    {
        std::string name;
        std::string team;
        Creature* creature;
        stack_node *next;
    };
    
    Stacknode();
    void add(Creature* Creat, std::string Name, std::string Team);
    Stacknode::stack_node* removeNode();
    
    
private:
    stack_node *head;
};

#endif 
