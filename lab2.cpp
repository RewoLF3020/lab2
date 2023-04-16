#include <iostream>
#include <string>
#include <cstring>
#include <cctype>

using std::cout;
using std::cin;
using std::endl;
using std::string;

struct date
{
    int year;
    int month;
    int day;
};

struct list
{
    //char name[50];
    string name;
    int number;
    double price;
    date dt;  
};


void ChooseSortName(list p[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int min_i = i;
        for (int j = i + 1; j < size; j++)
            if (p[min_i].name > p[j].name)
                min_i = j;
        if (min_i != i)
        {
            list temp = p[i];
            p[i] = p[min_i];
            p[min_i] = temp;
        }        
    }
}


void QuickSortPrice(list p[], int size)
{
    int stack[size * 2];          // хранит границы массивов

    int start = 0;
    int end = size - 1;

    int top = -1;

    stack[++top] = start;
    stack[++top] = end;


    while (top >= 0)
    {  
        end = stack[top--];
        start = stack[top--];

        int i = start;
        int j = end;
        double oporn = p[(start + end) / 2].price;
        
        while (i <= j)
        {

            while (p[i].price < oporn) i++;                    
            while (p[j].price > oporn) j--;

            if (i <= j)
            {
                list temp = p[i];
                p[i] = p[j];
                p[j] = temp;
                i++;
                j--;                                                                                                                  
            }
        }

        if (i < end)
        {
            stack[++top] = i;
            stack[++top] = end;
        }

        if (j > start)
        {
            stack[++top] = start;
            stack[++top] = j;
        }
    }
}


int binary_search(list a[], int n, int p) 
{
    int l = 0, r = n - 1, m;
    while (l < r) 
    {
        m = (l + r) / 2;
        //if (a[m].price == p) return m;
        if (a[m].price < p) 
            l = m + 1;
        else 
        r = m;
    }

    return l;
}


void View(list products[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << "Name: " << products[i].name << endl;   
        cout << "Amount of " << products[i].name << ": " << products[i].number << endl;
        cout << "Price: " << products[i].price << endl;
        cout << "Date of receipt: " << products[i].dt.day << "." << products[i].dt.month << "." << products[i].dt.year << endl;
    }
}


int main()
{
    int size;
    cout << "Enter amount of products: ";
    cin >> size;

    list products[size];
    for (int i = 0; i < size; i++)
    {
        cin.get();
        cout << "Enter name: ";
        cin >> products[i].name;
        //cin.getline(products[i].name, 50);
        products[i].name[0] = std::tolower(products[i].name[0]);
        cout << "Enter amount of " << products[i].name << ": ";
        cin >> products[i].number;
        cout << "Enter price of " << products[i].name << ": ";
        cin >> products[i].price;
        cout << "Enter date: (day, month, year)\n";
        cin >> products[i].dt.day >> products[i].dt.month >> products[i].dt.year; 
    }

    QuickSortPrice(products, size);

    cout << "List sorted by price:\n";

    View(products, size);

    int j = binary_search(products, size, 100);
    list arr_ind[size - j];
    int i = 0;
    for (j; j < size; j++)
    {
        if (products[j].dt.month > 1 || products[j].dt.month == 1 && products[j].dt.day > 0)
           arr_ind[i++] = products[j]; 
    }

    if (i == 0)
        cout << "go fuck products.\n";
    else
    {
        ChooseSortName(arr_ind, i);
        cout << "\nResult:\n";
        View(arr_ind, i);
    }
           
}


