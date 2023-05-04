#include <iostream>


typedef int T;
class Stack
{
    private:    
        enum {MAX = 10};
        struct Node { T item; Node * next; };
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
        bool push(const T & item);
        bool pop(T & item);
        int count() const { return items; }
        bool View() const;
        bool DeleteEven();
        void swap2();
        void swap();
};


void Stack::swap() //  поменять вершину с 4-ым местами
{
    Node * nb = begin->next->next->next;  //новый begin
    Node * five = nb->next;

    nb->next = begin->next;
    nb->next->next->next = begin;
    begin->next = five;

    begin = nb;
}


void Stack::swap2() //второй с 4
{
    Node * n_sec = begin->next->next->next;
    Node * five = n_sec->next;
    Node * n_four = begin->next;

    n_sec->next = begin->next->next;
    n_sec->next->next = n_four;
    n_four->next = five;

    begin->next = n_sec;
}


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


bool Stack::push(const T & item)
{
    if (isfull())
        return false;
    Node * add = new Node;
    items++;
    add->item = item;
    add->next = begin;
    begin = add;
    return true;
}


bool Stack::pop(T & item)
{
    if (isempty())     
        return false;
    item = begin->item;
    items--;
    Node * temp = begin;
    begin = begin->next;
    delete temp;
    if (items == 0)
        begin = nullptr;    
    return true;    
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
     return true;
}


bool Stack::DeleteEven()
{
    if (isempty())     
        return false;

    Node * tek = new Node;
    Node * del = new Node;
    tek = begin;

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

    if (begin->item % 2 == 0)
    {
        del = begin;
        begin = begin->next;
        delete del;
        items--;
    }

    return true;
}


int main()
{
    using std::cout;
    using std::cin;

    int size;
    cout << "Enter size of stack: ";
    cin >> size;

    Stack st(size);
    int po;
    //char ch;

    for (int i = 0; i < size; i++)
    {
        cout << "Enter value: ";
        cin >> po;
        st.push(po);
    }

    st.swap2();

    st.View();

    /* st.DeleteEven();
    cout << "After deleting even" << std::endl;
    st.View(); */
}





/*     cout << "Please enter A to add a number,\n"
        << "P to delete a number, or Q to quit.\n";

    while (cin >> ch && toupper(ch) != 'Q')
    {
        while (cin.get() != '\n')
            continue;
        if (!isalpha(ch))
        {
            cout << '\a';
            continue;
        }

        switch(ch)
        {
            case 'A':
            case 'a': 
                cout << "Enter a number to add: ";
                cin >> po;

                if (st.isfull())
                    cout << "stack already full\n";
                else
                    st.push(po);    
                break;
            case 'P':
            case 'p':
                if (st.isempty())
                    cout << "stack already empty\n";
                else 
                {
                    st.pop(po);
                    cout << "Number #" << po << " deleted\n";
                }            
                break;
        }

        cout << "Please enter A to add a number,\n"
            << "P to delete a number, or Q to quit.\n";
    } */