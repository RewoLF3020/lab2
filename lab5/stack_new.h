#ifndef STACK
#define STACK
#include <string>


class Stack
{
    private:    
        enum {MAX = 10};
        struct Node { char item; Node * next; };
        Node * begin;
        int items;
        int size;

        Stack(const Stack & st) : size(0) {}
        Stack operator=(const Stack & st) { return *this; }

    public:
        explicit Stack(int n = 10);
        ~Stack();
        bool isempty() const { return items == 0; }
        bool isfull() const { return items == size; }
        Node * push(char & item);
        Node * pop(char & item);
        int count() const { return items; }
        bool View() const;
        bool DeleteEven();
        void PopToOpenBracket(std::string & str);
        void PriorityOperator(std::string & str, char ch);
        void outRest(std::string & str);
        bool checkLeftBracket();
};

#endif