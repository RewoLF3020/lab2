#include "stack_new.h"
#include "stack_new.cpp"
#include <iostream>
#include <cstring>
#include <string>
#include <cctype>
#include <cmath>

using std::string;

double Result(const string &str);
string CreateOpz(string &str);

Stack t(40);

int main()          //ИСПРАВИТЬ: (строка с пробелами)-почти исправлено(умножение без знака если между операндами есть пробелы не сработает); и числа больше одного знакака
{
    string inStr;
    std::cout << "Enter problem:\n";
    getline(std::cin, inStr);
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
            if (str[k - 1] >= 'a' && str[k - 1] <= 'z' || isdigit(str[k - 1]) || str[k - 1] == ')')
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
        else if (str[k] == ' ')
        {
            k++;
            continue;
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