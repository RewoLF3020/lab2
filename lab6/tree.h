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
                int countLeaves(Node * t)
                {
                    if (!t)
                        return 0;
                    if (!t->left && !t->right)
                        return 1;
                    return countLeaves(t->left) + countLeaves(t->right);        
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
        string SearchByKey(int key);
        void ViewInOrder() { root->ViewInOrder(root); }
        void ViewPreOrder() { root->ViewPreOrder(root); }
        void ViewPostOrder() { root->ViewPostOrder(root); }
        void Balance(int n, int k, int *a);
        void DeleteByKey(int key);
        int countLeaves();
};


Tree::~Tree() 
{
    Node * t = root;
    t->Delete(t);
}


void Tree::Add(string str, int num)
{
    Node * node = new Node(str, num);
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


string Tree::SearchByKey(int key) 
{
    if (key < 1)
        return "incorrect key";
    if (!root)
        return "tree is empty";    
    Node * t = root;
    while (t)
    {
        if (key < t->key)
        {
            t = t->left;
        }
        else if (key > t->key)
        {
            t = t->right;
        }
        else
        {
            return t->data;
        }
    }
    return "key not found";
}


void Tree::DeleteByKey(int key)
{
    if (key < 1)
    {
        std::cout << "incorrect key\n";
        return;
    }
    if (!root)
    {
        std::cout << "tree is empty\n"; 
        return;
    }

    Node *del, *prev_del, *r, *prev_r;
    del = root;
    prev_del = nullptr;

    while (del && del->key != key)
    {
        prev_del = del;
        if (del->key > key)
            del = del->left;
        else 
            del = del->right;    
    }

    if (!del)
    {
        std::cout << "key not found\n";
        return;
    }

    if (!del->right)
        r = del->left;
    else if (!del->left)
        r = del->right;    
    else 
    {
        prev_r = del;
        r = del->left;
        while (r->right)
        {
            prev_r = r;
            r = r->right;
        }

        if (prev_r == del)
            r->right = del->right;
        else 
        {
            r->right = del->right;
            prev_r->right = r->left;
            r->left = prev_r;
        }
    }    

    if (del == root)
        root = r;
    else if (del->key < prev_del->key)
        prev_del->left = r;
    else 
        prev_del->right = r;
    std::cout << "deleted info: " << del->key << ": " << del->data << std::endl;
    delete del;        
}


int Tree::countLeaves() 
{
    Node * t = root;
    return t->countLeaves(t);
}


void Tree::Balance(int n, int k, int *a)
{
    if (n == k) 
    {
        
    }
}


#endif