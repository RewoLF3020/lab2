#ifndef QUEUE
#define QUEUE

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
        bool enqueue(const Item & item);
        bool dequeue(Item & item);
        bool ViewFromFront() const;
        bool ViewFromRear() const;
        bool DeleteEven();
        void swap();
};

#endif