#include <iostream>

void sort(int ar[], int size);
int pos(int ar[], int right, int c);
int pos_rec(int ar[], int right, int c, int left = 0);

int main()
{
    int n, c;
    std::cout << "Enter array size: ";
    std::cin >> n;
    if (n < 1)
    {
        std::cout << "False size.\n";
        return 0;
    }
    int *arr = new int[n];

    std::cout << "Fill array:\n";
    for (int i = 0; i < n; i++)
        std::cin >> arr[i];

    sort(arr, n);
    std::cout << "Sorted array:\n";
    for (int i = 0; i < n; i++)
        std::cout << arr[i] << " ";

    std::cout << "\nEnter c: ";
    std::cin >> c;
    std::cout << "Positions of " << c
        << " in sorted array: " /* << pos(arr, n, c) */ << pos_rec(arr, n, c);    
}


int pos(int ar[], int right, int c)
{   
    int left = 0, middle;
    do
    {
        middle = (left + right) / 2;
        if (ar[middle] < c)
            left = middle + 1;
        else
            right = middle;
    } while (left < right);
    if (ar[left] == c)
        return left;
    return -1;       
}


void sort(int ar[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int min_i = i;
        for (int j = i + 1; j < size; j++)
            if (ar[min_i] > ar[j])
                min_i = j;
        if (min_i != i)
        {
            int temp = ar[i];
            ar[i] = ar[min_i];
            ar[min_i] = temp;
        }        
    }
}


int pos_rec(int ar[], int right, int c, int left)
{
    int middle = (left + right) / 2;
    if (ar[middle] == c)
        return middle;
    if (middle == left && middle == right)
        return -1;
    if (ar[middle] < c)
       return pos_rec(ar, right, c, middle + 1);
    else 
       return pos_rec(ar, middle, c, left);    
}






    //int l_i = left;
    //right = 0; left = size;
    /* do
    {
        middle = (left + right) / 2;
        if (ar[middle] > c)
            right = middle;
        else
            left = middle + 1;
    } while (left < right);
    int r_i = right - 1;

    int new_size =  r_i - l_i + 1;
    if (new_size <= 0)
        std::cout << "No " << c << " in array.\n";
    else
    {
        int *c_ar = new int[new_size];
        for (int i = l_i; i <= r_i; i++)
            c_ar[i - l_i] = i;
        for (int i = 0; i < new_size; i++)
            std::cout << c_ar[i] << " ";
    } */ 



//такая себе сортировка
    /* while (size--)
    {
        int swaped = 0;
        for (int i = 0; i < size; i++)
        {
            if (ar[i] > ar[i+1])
            {
                int temp = ar[i];
                ar[i] = ar[i + 1];
                ar[i + 1] = temp;
                swaped = 1;
            }
        }

        if (!swaped)
            break;
    } */