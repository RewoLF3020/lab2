#include <iostream>
#include <cstdlib>
#include <iostream>
/* #include "queue.h"
#include "queue.cpp" */


typedef int Item;

class Queue
{
    private:
        struct Node { Item item; Node * next; Node * prev; };
        enum {Q_SIZE = 10};
        Node *  front;
        Node * rear;
        int items;
        const int qsize;

        Queue(const Queue & q) : qsize(0) {}
        Queue & operator=(const Queue & q) { return *this; }

    public:
        Queue(int qs = Q_SIZE);
        ~Queue();
        bool isempty() const { return items == 0; }
        bool isfull() const { return items == qsize; }
        int queuecount() const { return items; }
        bool AddToFront(const Item & item);
        bool AddToRear(const Item & item);
        bool dequeue(Item & item);
        bool ViewFromFront() const;
        bool ViewFromRear() const;
        bool DeleteEven();
};





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


bool Queue::AddToFront(const Item & item) 
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


bool Queue::AddToRear(const Item & item)
{
    if (isfull())
        return false;

    Node * add = new Node;
    add->item = item;
    //add->next = front;
    add->prev =  nullptr;
    items++;

    if (rear == nullptr)
    {   
        rear = add;
        add->next = nullptr;
    }
    else 
    {
        rear->prev = add;
        add->next = rear;
    }
    front = add;
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


int main()
{
    using std::cin;
    using std::cout;

    int size;
    cout << "Enter size of queue: ";
    cin >> size;
    Queue nq(size);
    int val;
    
    for (int i = 0; i < size; i++)
    {
        cout << "Enter value: ";
        cin >> val;        
        nq.AddToFront(val);
    }

    cout << "View from the beginning:\n";
    nq.ViewFromFront();
    cout << "\nView from the end:\n";
    nq.ViewFromRear();

    nq.DeleteEven();
    cout << "\nView after deleting even:\n";
    nq.ViewFromFront();
}