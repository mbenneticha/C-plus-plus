
#include "Queue.hpp"
#include <stdlib.h>
#include <iostream>


//Constructor
Queue::Queue()
{
    front = NULL;
    back = NULL;
}

//func adds value/node to end of queue
void Queue::addBack(int value)
{
    if (front == NULL)      //if there are no nodes created
    {
        QueueNode *temp = new QueueNode;
        temp->data = value;
        front = temp;
        back = temp;
        std::cout << "Value " << temp->data << " added." << std::endl <<std::endl;
        //std::cout << "Data " << temp->data << " front " << front->data <<" back " << back->data << std::endl;
    }
    else if (front->data == -1)     //if the list is empty
    {
        front->data = value;
        back = front->next;
        back->prev = front;
        std::cout << "Value " << front->data << " added." << std::endl <<std::endl;
        //std::cout << "Data " << front->data <<" back " << back->data << std::endl;
    }
    else if (back->data == -1)      //if there are empty nodes
    {
        QueueNode *temp;
        temp = back->next;
        back->data = value;
        
        if (temp->data == -1)       //if there is another empty node following current node
        {
            temp->prev = back;
            back = temp;
            std::cout << "Value " << back->data << " added." << std::endl <<std::endl;
            //std::cout << "Data " << temp->data << " front " << front->data <<" back " << back->data << std::endl;
        }
    }
    else                            //if there are no empty nodes; new node must be created
    {
        QueueNode *temp = new QueueNode;
        temp->data = value;
        back->next = temp;
        temp->prev = back;
        back = temp;
        temp->next = front;
        front->prev = temp;
        std::cout << "Value " << temp->data << " added." << std::endl <<std::endl;
        //std::cout << "Data " << temp->data << " front " << front->data <<" back " << back->data << std::endl;
    }
}


int Queue::getFront()
{
    int front_value = 0;
    if ((front->data == -1) || (front == NULL))     //if list is empty
    {
        std::cout << "List is empty." <<std::endl <<std::endl;
        return -1;
    }
    else                                            //if list is not empty
    {
        std::cout << "List contains: " << std::endl;
        QueueNode *temp = new QueueNode;
        temp = front;
        if (back->data == -1)                     //if there are empty nodes;print only full nodes
        {
            do {
                front_value = temp->data;
                std::cout <<front_value <<std::endl;
                
                temp = temp->next;
            } while (temp->data != -1);
            std::cout << std::endl;
        }
        else                                    //if list is full, print all once.
        {
            do {
                front_value = temp->data;
                std::cout <<front_value <<std::endl;
                
                temp = temp->next;
            } while (temp != back);
            std::cout <<back->data <<std::endl;
            std::cout << std::endl;
        }
        return front_value;
    }
}


int Queue::removeFront()
{
    if (front->data == -1)                                  //if list is empty
    {
        std::cout << "The list is empty." <<std::endl <<std::endl;
        return -1;
    }
    else if (front->next == back)                           //if only one item in queue
    {
        QueueNode *temp = front;
        front = back;
        back = back->next;                                  //adjust placement of back pointer too
        int return_value = temp->data;
        temp->data = -1;
        std::cout << "Item (value = " << return_value << ") removed." <<std::endl <<std::endl;
        //std::cout << "New front = " << front->data << "." <<std::endl;
        return return_value;
    }
    else                                                    //if more than one item in queue
    {                                                       //only adjust front pointer
        QueueNode *temp = front;
        front = front->next;
        int return_value = temp->data;
        temp->data = -1;
        std::cout << "Item (value = " << return_value << ") removed." <<std::endl <<std::endl;
        //std::cout << "New front = " << front->data << "." <<std::endl;
        //std::cout << "Back value = " << back->data << "." <<std::endl;
        return return_value;
    }
    
}



