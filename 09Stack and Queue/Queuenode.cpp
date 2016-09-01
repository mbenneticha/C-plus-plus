//FIFO

#include "Queuenode.hpp"
#include <iostream>


Queuenode::Queuenode()
{
    front = NULL;
    back = NULL;
}


void Queuenode::add(int Value)
{
    if ((front == NULL) && (back == NULL))
    {
        queue_node *temp = new queue_node;
        temp->data = Value;
        front = temp;
        back = temp;
        std::cout << "Data " << temp->data << " front " << front->data <<" back " << back->data << std::endl;
    }
    else if (front != NULL)
    {
        queue_node *temp = new queue_node;
        temp->data = Value;
        back->next = temp;
        back = temp;
        temp->next = front->next;
        std::cout << "Data " << temp->data << " front " << front->data <<" back " << back->data << std::endl;
    }
}


int Queuenode::remove()
{
    if ((front == NULL) && (back == NULL))
    {
        std::cout << "The list is empty." <<std::endl;
    }
    else if (front == back)
    {
        int return_value = front->data;
        delete front;
        front = NULL;
        back = NULL;
        std::cout << "Node (value = " << return_value << ") removed." <<std::endl;
        return return_value;
    }
    else
    {
        queue_node *temp = front;
        int return_value = temp->data;
        front = front->next;
        delete temp;
        std::cout << "Node (value = " << return_value << ") removed." <<std::endl;
        return return_value;
    }
    return 0;
}