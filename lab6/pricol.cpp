#include <iostream>
using namespace std;


struct Node
{
    int key;
    string data;
    Node *left;
    Node *right;
    Node(int key, string data)
    {
        this->key = key;
        this->data = data;
        left = right = nullptr;
    }
};


class BinarySearchTree
{
private:
    Node *root;
    Node *insert(Node *node, int key, string data)
    {
        if (node == nullptr)
        {
            return new Node(key, data);
        }
        if (key < node->key)
        {
            node->left = insert(node->left, key, data);
        }
        else if (key > node->key)
        {
            node->right = insert(node->right, key, data);
        }
        else
        {
            node->data = data;
        }
        return node;
    }
    Node *balance(Node *node)
    {
        if (node == nullptr)
        {
            return nullptr;
        }
        int balanceFactor = getBalanceFactor(node);
        if (balanceFactor > 1)
        {
            if (getBalanceFactor(node->left) < 0)
            {
                node->left = rotateLeft(node->left);
            }
            return rotateRight(node);
        }
        else if (balanceFactor < -1)
        {
            if (getBalanceFactor(node->right) > 0)
            {
                node->right = rotateRight(node->right);
            }
            return rotateLeft(node);
        }
        return node;
    }
    int getBalanceFactor(Node *node)
    {
        return getHeight(node->left) - getHeight(node->right);
    }
    int getHeight(Node *node)
    {
        if (node == nullptr)
        {
            return 0;
        }
        int leftHeight = getHeight(node->left);
        int rightHeight = getHeight(node->right);
        return max(leftHeight, rightHeight) + 1;
    }
    Node *rotateRight(Node *node)
    {
        Node *leftChild = node->left;
        node->left = leftChild->right;
        leftChild->right = node;
        return leftChild;
    }
    Node *rotateLeft(Node *node)
    {
        Node *rightChild = node->right;
        node->right = rightChild->left;
        rightChild->left = node;
        return rightChild;
    }
    Node *findMin(Node *node)
    {
        while (node->left != nullptr)
        {
            node = node->left;
        }
        return node;
    }
    Node *remove(Node *node, int key)
    {
        if (node == nullptr)
        {
            return nullptr;
        }
        if (key < node->key)
        {
            node->left = remove(node->left, key);
        }
        else if (key > node->key)
        {
            node->right = remove(node->right, key);
        }
        else
        {
            Node *leftChild = node->left;
            Node *rightChild = node->right;
            if (rightChild == nullptr)
            {
                delete node;
                return leftChild;
            }
            Node *minNode = findMin(rightChild);
            minNode->right = removeMin(rightChild);
            minNode->left = leftChild;
            delete node;
            return balance(minNode);
        }
        return balance(node);
    }
    Node *removeMin(Node *node)
    {
        if (node->left == nullptr)
        {
            return node->right;
        }
        node->left = removeMin(node->left);
        return balance(node);
    }

public:
    BinarySearchTree()
    {
        root = nullptr;
    }
    void insert(int key, string data)
    {
        root = insert(root, key, data);
    }
    void balance()
    {
        root = balance(root);
    }
    void add(int key, string data)
    {
        insert(key, data);
        balance();
    }
    string find(int key)
    {
        Node *node = root;
        while (node != nullptr)
        {
            if (key < node->key)
            {
                node = node->left;
            }
            else if (key > node->key)
            {
                node = node->right;
            }
            else
            {
                return node->data;
            }
        }
        return "Not found";
    }
    void remove(int key)
    {
        root = remove(root, key);
    }
    void printInOrder(Node *node)
    {
        if (node != nullptr)
        {
            printInOrder(node->left);
            cout << node->key << " " << node->data << endl;
            printInOrder(node->right);
        }
    }
    void printPreOrder(Node *node)
    {
        if (node != nullptr)
        {
            cout << node->key << " " << node->data << endl;
            printPreOrder(node->left);
            printPreOrder(node->right);
        }
    }
    void printPostOrder(Node *node)
    {
        if (node != nullptr)
        {
            printPostOrder(node->left);
            printPostOrder(node->right);
            cout << node->key << " " << node->data << endl;
        }
    }
    void printInOrder()
    {
        printInOrder(root);
    }
    void printPreOrder()
    {
        printPreOrder(root);
    }
    void printPostOrder()
    {
        printPostOrder(root);
    }
};


int main()
{
    BinarySearchTree bst;
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int key;
        string data;
        cout << "Enter key: ";
        cin >> key;
        cout << "Enter data: ";
        cin >> data;
        bst.insert(key, data);
    }
    bst.printInOrder();
    cout << endl;
    bst.printPreOrder();
    cout << endl;
    bst.printPostOrder();
    cout << endl;
    bst.balance();
    bst.printInOrder();
    cout << endl;
    bst.add(6, "Test");
    bst.printInOrder();
    cout << endl;
    cout << bst.find(4) << endl;
    bst.remove(4);
    bst.printInOrder();
    return 0;
}