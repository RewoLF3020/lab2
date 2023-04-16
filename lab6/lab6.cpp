#include "tree.h"

int main()
{
    Tree t;

    t.Add("ede", 10);
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
}