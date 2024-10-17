#include <iostream>
using namespace std;

class Node
{
public:
    int value;
    Node *left, *right;

    Node(int val) : value(val), left(nullptr), right(nullptr) {}
};

class BinarySearchTree
{
private:
    Node *root;

    Node* insertNode(Node* node, int value)
    {
        if (node == nullptr)
        {
            return new Node(value);
        }

        if (value < node->value)
        {
            node->left = insertNode(node->left, value);
        }
        else
        {
            node->right = insertNode(node->right, value);
        }

        return node;
    }

    Node* findLCA(Node* node, int u, int v)
    {
        if (node == nullptr) return nullptr;

        if (node->value > u && node->value > v)
            return findLCA(node->left, u, v);

        if (node->value < u && node->value < v)
            return findLCA(node->right, u, v);

        return node;
    }

public:
    BinarySearchTree() : root(nullptr) {}

    void insert(int value)
    {
        root = insertNode(root, value);
    }

     findLCA(int u, int v)
    {
        cout<< findLCA(root, u, v)->value<<endl;
    }

};


int man()
{
    BinarySearchTree BST;

    int data;

    while(cin>> data )
    {
        BST.insert(data);
    }

    return 0;
}

