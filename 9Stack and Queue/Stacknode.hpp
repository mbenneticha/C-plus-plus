//FILO

#ifndef Stacknode_hpp
#define Stacknode_hpp

#include <iostream>


class Stacknode
{
    struct stack_node
    {
        int data;
        stack_node *next;
    };
    
public:
    Stacknode();
    void add(int Value);
    int remove();
    
private:
    stack_node *head;
};

#endif
