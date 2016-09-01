

#include "Queue.hpp"



Queuenode::Queuenode()
{
    front = NULL;
    back = NULL;
}



void Queuenode::add_lineup_val(int Value)
{
    if ((front == NULL) && (back == NULL))
    {
        queue_node *temp = new queue_node;
        temp->data = Value;
        front = temp;
        back = temp;
        //std::cout << "Data " << temp->data << " front " << front->data <<" back " << back->data << std::endl;
    }
    else if (front != NULL)
    {
        queue_node *temp = new queue_node;
        temp->data = Value;
        back->next = temp;
        back = temp;
        temp->next = front->next;
        //std::cout << "Data " << temp->data << " front " << front->data <<" back " << back->data << std::endl;
    }
}



void Queuenode::add_lineup(Creature* creat, std::string Name, std::string Type)
{
    if ((front == NULL) && (back == NULL))
    {
        queue_node *temp = new queue_node;
        temp->creature = creat;
        temp->name = Name;
        temp->type = Type;
        front = temp;
        back = temp;
        //std::cout << "Data " << temp->creature << " front " << front->creature <<" back " << back->creature << std::endl;
    }
    else if (front != NULL)
    {
        queue_node *temp = new queue_node;
        temp->creature = creat;
        temp->name = Name;
        temp->type = Type;
        back->next = temp;
        temp->prev = back;
        back = temp;
        temp->next = front;
        front->prev = temp;
        //std::cout << "Data " << temp->creature << " front " << front->creature <<" back " << back->creature << std::endl;
    }
}



Creature* Queuenode::get_Front_Creature()
{
    //std::cout << "Creature at front of list " <<front->creature <<std::endl;
    return front->creature;
}



std::string Queuenode::get_Front_Name()
{
    //std::cout << "Creature at front of list " <<front->name <<std::endl;
    return front->name;
}



std::string Queuenode::get_Front_Type()
{
    //std::cout << "Creature at front of list " <<front->name <<std::endl;
    return front->type;
}



void Queuenode::move_Back()
{
    back = front;
    front = front->next;
}



int Queuenode::remove_lineup()
{
    if ((front == NULL) && (back == NULL))
    {
        //std::cout << "The list is empty." <<std::endl;
        return -1;
    }
    else if (front == back)
    {
        delete front;
        front = NULL;
        back = NULL;
        //std::cout << "Node (value = " << return_value << ") removed." <<std::endl;
        return -1;
    }
    else
    {
        queue_node *temp = front;
        front = front->next;
        delete temp;
        back->next = front;
        front->prev = back;
        //std::cout << "Node (value = " << return_value << ") removed." <<std::endl;
        return 0;
    }
}



int Queuenode::is_Empty()
{
    if ((front == NULL) && (back == NULL))
    {
        return -1;
    }
    else
        return 0;
}
