
#ifndef Queue_hpp
#define Queue_hpp

#include "Creature.hpp"
#include <stdio.h>
#include <iostream>
#include <string>


class Queuenode
{
    struct queue_node
    {
        int data;
        std::string name;
        std::string type;
        Creature* creature;
        struct queue_node *next;
        struct queue_node *prev;
    };
    
public:
    Queuenode();
    
    void add_lineup_val(int Value);
    void add_lineup(Creature* creat, std::string Name, std::string Type);
    
    Creature* get_Front_Creature();
    std::string get_Front_Name();
    std::string get_Front_Type();
    
    void move_Back();
    int remove_lineup();
    int is_Empty();
    
private:
    queue_node *front;
    queue_node *back;
};

#endif