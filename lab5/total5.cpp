#include <iostream>
#include <cstring>
#include <string>
#include <cctype>
#include <cmath>


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


using std::string;

double Result(const string &str);
string CreateOpz(string &str);

Stack t(40);

int main()
{
    string inStr;
    std::cout << "Enter problem:\n";
    std::cin >> inStr;
    string result_s = CreateOpz(inStr);
    std::cout << result_s << std::endl;
    std::cout << Result(result_s);
}

string CreateOpz(string &str)
{
    string outStr;
    int k = 0;

    while (str[k] != '\0')
    {
        if (str[k] >= 'a' && str[k] <= 'z' || isdigit(str[k]))
        {
            if (str[k - 1] >= 'a' && str[k - 1] <= 'z' || isdigit(str[k - 1]))
                t.PriorityOperator(outStr, '*');
            else if (str[k - 1] == ')')
                t.PriorityOperator(outStr, '*');
            outStr += str[k];
        }
        else if (str[k] == '(')
        {
            if (str[k - 1] == ')' || str[k - 1] >= 'a' && str[k - 1] <= 'z')
                t.PriorityOperator(outStr, '*');
            t.push(str[k]);
        }
        else if (str[k] == ')')
            t.PopToOpenBracket(outStr);
        else if (strchr("^*/+-", str[k]))
        {
            if (strchr("^*/+-", str[k - 1]))
            {
                std::cout << "Wrong input\n";
                return "";
            }
            t.PriorityOperator(outStr, str[k]);
        }
        else
        {
            std::cout << "Wrong input\n";
            return "";
        }
        k++;
    }

    t.outRest(outStr);

    return outStr;
}

double Result(const string &str)
{
    char ch, ch1, ch2, chr = 'z' + 1;
    double op1, op2, res = 0.0, mas[200];

    for (int i = 0; str[i] != '\0'; i++)
    {
        ch = str[i];

        if (ch >= 'a' && ch <= 'z')
        {
            std::cout << ch << " = ";
            std::cin >> mas[int(ch)];
        }

        if (isdigit(ch))
            mas[int(ch)] = ch - '0';
    }

    for (int i = 0; str[i] != '\0'; i++)
    {
        ch = str[i];
        res = mas[int(ch)];

        if (!strchr("^*/+-", ch))
            t.push(ch);

        else
        {
            t.pop(ch1);
            t.pop(ch2);
            op1 = mas[int(ch1)];
            op2 = mas[int(ch2)];

            switch (ch)
            {
            case '+':
                res = op2 + op1;
                break;
            case '-':
                res = op2 - op1;
                break;
            case '*':
                res = op2 * op1;
                break;
            case '/':
                if (op1 == 0)
                {
                    std::cout << "0 in denominator";
                    return 0.0;
                }
                res = op2 / op1;
                break;
            case '^':
                res = pow(op2, op1);
                break;
            }

            mas[int(chr)] = res;
            t.push(chr);
            chr++;
        }
    }
    return res;
}