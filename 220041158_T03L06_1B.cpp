#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
    Node* parent;
    int height;
    int size;

    Node(int value) : data(value), left(nullptr), right(nullptr), parent(nullptr), height(1), size(1) {}
};

class AVLTree
{
public:
    Node* root;

    AVLTree() : root(nullptr) {}

    void insertion(int key)
    {
        root = insertIteratively(root, key);
    }

    int lowerCount(int key)
    {
        return lowerCountUtil(root, key);
    }

private:
    Node* insertIteratively(Node* node, int key)
    {
        if (!node)
        {
            return new Node(key);
        }

        Node* current = node;
        Node* parent = nullptr;

        while (current)
        {
            parent = current;
            parent->size++;
            if (key < current->data)
            {
                current = current->left;
            }
            else if (key > current->data)
            {
                current = current->right;
            }
            else
            {
                return node;
            }
        }

        Node* newNode = new Node(key);
        newNode->parent = parent;

        if (key < parent->data)
        {
            parent->left = newNode;
        }
        else
        {
            parent->right = newNode;
        }

        updateHeightAndSize(newNode->parent);
        checkBalance(newNode->parent);
        return node;
    }

    int lowerCountUtil(Node* node, int key)
    {
        int count = 0;
        while (node)
        {
            if (key > node->data)
            {
                count += (node->left ? node->left->size : 0) + 1;
                node = node->right;
            }
            else
            {
                node = node->left;
            }
        }
        return count;
    }

    void updateHeightAndSize(Node* node)
    {
        while (node)
        {
            node->height = 1 + max(height(node->left), height(node->right));
            node->size = 1 + (node->left ? node->left->size : 0) + (node->right ? node->right->size : 0);
            node = node->parent;
        }
    }

    int height(Node* node) const
    {
        return node ? node->height : 0;
    }

    int balanceFactor(Node* node) const
    {
        return node ? height(node->left) - height(node->right) : 0;
    }

    void leftRotate(Node* x)
    {
        Node* y = x->right;
        x->right = y->left;
        if (y->left) y->left->parent = x;
        y->parent = x->parent;
        if (!x->parent) root = y;
        else if (x == x->parent->left) x->parent->left = y;
        else x->parent->right = y;
        y->left = x;
        x->parent = y;


        updateHeightAndSize(x);
        updateHeightAndSize(y);
    }

    void rightRotate(Node* x)
    {
        Node* y = x->left;
        x->left = y->right;
        if (y->right) y->right->parent = x;
        y->parent = x->parent;
        if (!x->parent) root = y;
        else if (x == x->parent->left) x->parent->left = y;
        else x->parent->right = y;
        y->right = x;
        x->parent = y;

        updateHeightAndSize(x);
        updateHeightAndSize(y);
    }

    void checkBalance(Node* node)
    {
        while (node)
        {
            int bf = balanceFactor(node);
            if (bf > 1)
            {
                if (balanceFactor(node->left) >= 0)
                {
                    rightRotate(node);
                }
                else
                {
                    leftRotate(node->left);
                    rightRotate(node);
                }
            }
            else if (bf < -1)
            {
                if (balanceFactor(node->right) <= 0)
                {
                    leftRotate(node);
                }
                else
                {
                    rightRotate(node->right);
                    leftRotate(node);
                }
            }
            node = node->parent;
        }
    }
};

int main()
{
    AVLTree tree;
    int value;

    vector<int> values;
    vector<int> queries;


    while( cin>>value && value != -1)
    {
        values.push_back(value);
        tree.insertion(value);
    }

    cout <<"\n \n";

    int query;
    while(cin>>query)
    {
        cout << query << "\n";
        cout << tree.lowerCount(query) << "\n";
    }

    return 0;
}
