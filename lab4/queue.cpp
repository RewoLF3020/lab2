#include "queue.h"
#include <cstdlib>
#include <iostream>


Queue::Queue(int qs) : qsize(qs)
{
    front = rear = 0;
    items = 0;
}


Queue::~Queue()
{
    Node * temp;
    while (front != nullptr)
    {
        temp = front;
        front = front->next;
        delete temp;
    }
}


bool Queue::enqueue(const Item & item) 
{
    if (isfull())
        return false;
    Node * add = new Node;
    add->item = item;
    add->next = nullptr;
    items++;
    if (front == nullptr)
    {   
        front = add;
        add->prev = nullptr;
    }
    else 
    {
        rear->next = add;
        add->prev = rear;
    }
    rear = add;
    return true;            
}


bool Queue::dequeue(Item & item)
{
    if (front == nullptr)
        return false;
    item = front->item;
    items--;
    Node * temp = front;
    front = front->next;
    delete temp;
    if (items == 0)
        rear = nullptr;
    return true;        
}


bool Queue::ViewFromFront() const
{
    if (isempty())
        return false;

    Node * temp = new Node;
    temp = front;
    while (temp != nullptr)
    {
        std::cout << temp->item << std::endl;
        temp = temp->next;
    }

    return true;
}


bool Queue::ViewFromRear() const
{
    if (isempty())
        return false;

    Node * temp = new Node;  
    temp = rear;
    while (temp != nullptr)
    {
        std::cout << temp->item << std::endl;
        temp = temp->prev;
    }

    return true;
}


bool Queue::DeleteEven()
{
    if (isempty())     
        return false;

    Node * tek = new Node;
    Node * del = new Node;
    tek = front;

    while (tek->next != nullptr)
    {
        if (tek->next->item % 2 == 0)
        {
            del = tek->next;
            tek->next = del->next;
            delete del;
            items--;
        }
        else    
            tek = tek->next;
    }

    if (front->item % 2 == 0)
    {
        del = front;
        front = front->next;
        delete del;
        items--;
    }

    return true;
}