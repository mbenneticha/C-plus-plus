//FIFO

#ifndef Queuenode_hpp
#define Queuenode_hpp

#include <iostream>


class Queuenode
{
    struct queue_node
    {
        int data;
        struct queue_node *next;
        struct queue_node *prev;
    };
    
public:
    Queuenode();
    void add(int Value);
    int remove();
    
private:
    queue_node *front;
    queue_node *back;
};

#endif
