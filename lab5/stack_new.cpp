#include "stack_new.h"
#include <iostream>

Stack::Stack(int n) : size(n)
{   
    begin = 0;
    items = 0;
}


Stack::~Stack()
{
    Node * temp;
    while (begin != nullptr)
    {
        temp = begin;
        begin = begin->next;
        delete temp;
    }
}


Stack::Node * Stack::push(char & item)
{
    Node * add = new Node;
    items++;
    add->item = item;
    add->next = begin;
    begin = add;
    return begin;
}


Stack::Node * Stack::pop(char & item)
{
    if (isempty()) 
        return begin;
    item = begin->item;
    items--;
    Node * temp = begin;
    begin = begin->next;
    delete temp;
    if (items == 0)
        begin = nullptr;    
    return begin;    
}


bool Stack::View() const
{
    if (isempty())     
        return false;
    Node * temp = new Node;
    temp = begin;
    while (temp != nullptr)
    {
        std::cout << temp->item << std::endl;
        temp = temp->next;
    }
    
    delete temp;
    return true;
}


//special methods for OPZ:
void Stack::PopToOpenBracket(std::string & str)
{
    if (isempty())
        return;  
    if (checkLeftBracket())
    {
        char a;
        while (begin->item != '(')
        {
            pop(a);
            str += a;
        }
        pop(a);
    }       
}


int Prior(char a)
{
    switch(a)
    {
        case '^':
            return 4;
        case '*': case '/':
            return 3;
        case '+': case '-':
            return 2;
        case '(': 
            return 1;            
    }
    return 0;
}


void Stack::PriorityOperator(std::string & str, char ch)
{
    char a;
    while (begin != nullptr && Prior(begin->item) >= Prior(ch))
    {
        pop(a);
        //if (a != '(')
        str += a; 
    }
    push(ch);
}


void Stack::outRest(std::string & str)
{
    char a;
    while (begin != nullptr)
    {
        pop(a);
        if (a != '(')
            str += a;
    }
}


bool Stack::checkLeftBracket()
{
    Node * temp = new Node;
    temp = begin;
    while (temp != nullptr)
    {
        if (temp->item == '(')
            return true;
        temp = temp->next;    
    }
    delete temp;
    return false;
}
