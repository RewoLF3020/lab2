#include "tree.h"

using std::cout;
using std::cin;
using std::endl;

struct info 
{
    int key;
    string data;
};


int main()
{
    Tree t;
    int size;
    cout << "Enter amount of elements: ";
    cin >> size;
    info arr[size];
    cout << "Enter info:\n";

    for (int i = 0; i < size; i++)   //написать проверку ввода
    {
        cout << "Enter key: ";
        cin >> arr[i].key;
        cout << "Enter data: ";
        cin >> arr[i].data;
    }

    for (int i = 0; i < size; i++)
    {
        t.Add(arr[i].data, arr[i].key);
    }

    t.ViewInOrder();
    cout << endl;
    t.ViewPreOrder();
    cout << endl;
    t.ViewPostOrder();
    cout << endl;
    
    cout << "Amount of leaves: " << t.countLeaves() << endl;

    cout << "Enter key to search for the info: ";
    int key;
    cin >> key;
    cout << t.SearchByKey(key) << endl;
    cout << "Enter key to delete node: ";
    cin >> key;
    t.DeleteByKey(key);
    //cout << t.SearchByKey(key) << endl;

    return 0;
}





/* t.Add("ede", 10);
    t.Add("chek", 25);
    t.Add("wer", 20);
    t.Add("wf4eg", 6);
    t.Add("thdw", 21);
    t.Add("dgfgdt", 8);
    t.Add("sef", 1);
    t.Add("zxc", 30);
    t.ViewInOrder();
    std::cout << std::endl;
    t.ViewPreOrder();
    std::cout << std::endl;
    t.ViewPostOrder();
    Tree tr;
    cout << t.countLeaves() << endl;
    string s = t.Search(10);
    cout << s << endl;
    t.DeleteByKey(10);
    s = t.Search(10);
    cout << s << endl; */







/* 
    void QuickSort(info arr[], int size)
{
    int stack[size];          // хранит границы массивов

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
        int oporn = arr[(start + end) / 2].key;
        
        while (i <= j)
        {

            while (arr[i].key < oporn) i++;                    
            while (arr[j].key > oporn) j--;

            if (i <= j)
            {
                info temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
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
} */