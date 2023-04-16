#ifndef TREE_H_
#define TREE_H_
#include <iostream>
#include <string>
using std::string;

class Tree
{
    protected:
        class Node
        {
            public:
                string data;
                int key;
                Node *left, *right;
                Node(string str = "", int num = 0) : data(str), key(num),
                                                     left(nullptr), right(nullptr) {}
                ~Node(){};
                void Delete(Node * t)
                {
                    if (t)
                    {
                        Delete(t->left);
                        Delete(t->right);
                        delete t;
                    }
                }
                void ViewInOrder(Node *t)
                {
                    if (t)
                    {
                        ViewInOrder(t->left);
                        std::cout << t->key << ": " << t->data << std::endl;
                        ViewInOrder(t->right);
                    };
                }
                void ViewPreOrder(Node *t)
                {
                    if (t)
                    {
                        std::cout << t->key << ": " << t->data << std::endl;
                        ViewInOrder(t->left);
                        ViewInOrder(t->right);
                    };
                }
                void ViewPostOrder(Node *t)
                {
                    if (t)
                    {
                        ViewInOrder(t->left);
                        ViewInOrder(t->right);
                        std::cout << t->key << ": " << t->data << std::endl;
                    };
                }
        };
        Node *root;

    public:
        Tree() : root(nullptr) {}
        Tree(string str, int num)
        {
            Node *node = new Node(str, num);
            root = node;
        }
        Tree(Node *node) : root(node) {}
        ~Tree();
        void Add(string str = "empty", int num = 0);
        void DeleteNode(int num);
        void Search();
        void ViewInOrder() { root->ViewInOrder(root); }
        void ViewPreOrder() { root->ViewPreOrder(root); }
        void ViewPostOrder() { root->ViewPostOrder(root); }
        void createBalance();
};


Tree::~Tree() 
{
    Node * t = root;
    t->Delete(t);
}


void Tree::Add(string str, int num)
{
    Node *node = new Node(str, num);
    if (root == nullptr)
    {
        root = node;
        return;
    }
    Node *prev, *t;
    t = root;
    while (t)
    {
        prev = t;
        if (num == t->key)
        {
            std::cout << "There is an element with such key!\n";
            return;
        }
        if (num < t->key)
            t = t->left;
        else
            t = t->right;
    }
    t = node;
    if (num < prev->key)
        prev->left = t;
    else
        prev->right = t;
}


#endif