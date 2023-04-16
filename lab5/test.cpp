#include "stack_new.h"
#include "stack_new.cpp"
#include <iostream>
#include <string>

int main()
{
   /*  Stack t;
    char ch;

    std::cout << "Enter symbols:\n";

    for (int i = 0; i < 14; i++)
    {
        std::cin >> ch;
        t.push(ch);
    }

    t.View(); */
    char a = '9';
    int b = int(a);
    int c = a - '0'; 
    std::cout << b << " " << c;
}