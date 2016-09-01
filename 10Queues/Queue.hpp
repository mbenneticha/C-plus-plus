

#ifndef Queue_hpp
#define Queue_hpp

#include <iostream>

class Queue
{
    struct QueueNode
    {
        int data;
        struct QueueNode *next;
        struct QueueNode *prev;
    };
    
public:
    Queue();
    void addBack(int value);
    int getFront();
    int removeFront();
    
private:
    QueueNode *front;
    QueueNode *back;
};

#endif
