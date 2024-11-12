#include <iostream>
#include <algorithm>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node* parent;
    int height;

    Node(int value) : data(value), left(nullptr), right(nullptr), parent(nullptr), height(1) {}
};

class AVLTree {
private:
    Node* Insert(Node* node, int key) {
        if (!node) {
            return new Node(key);
        }

        Node* current = node;
        Node* parent = nullptr;

        while (current) {
            parent = current;
            if (key < current->data) {
                current = current->left;
            } else if (key > current->data) {
                current = current->right;
            } else {
                return node;
            }
        }

        Node* newNode = new Node(key);
        newNode->parent = parent;

        if (key < parent->data) {
            parent->left = newNode;
        } else {
            parent->right = newNode;
        }

        updateHeight(newNode->parent);
        checkBalance(newNode->parent);
        return node;
    }

    void updateHeight(Node* node) {
        while (node) {
            node->height = 1 + max(height(node->left), height(node->right));
            node = node->parent;
        }
    }

    int height(Node* node) const {
        return node ? node->height : 0;
    }

    int balanceFactor(Node* node) const {
        return node ? height(node->left) - height(node->right) : 0;
    }

    void leftRotate(Node* x) {
        Node* y = x->right;
        x->right = y->left;
        if (y->left) y->left->parent = x;
        y->parent = x->parent;
        if (!x->parent) root = y;
        else if (x == x->parent->left) x->parent->left = y;
        else x->parent->right = y;
        y->left = x;
        x->parent = y;
        updateHeight(x);
        updateHeight(y);
        cout << "Left_rotate(" << x->data << ")\n";
    }

    void rightRotate(Node* x) {
        Node* y = x->left;
        x->left = y->right;
        if (y->right) y->right->parent = x;
        y->parent = x->parent;
        if (!x->parent) root = y;
        else if (x == x->parent->left) x->parent->left = y;
        else x->parent->right = y;
        y->right = x;
        x->parent = y;
        updateHeight(x);
        updateHeight(y);
        cout << "Right_rotate(" << x->data << ")\n";
    }

    void checkBalance(Node* node) {
        while (node) {
            int bf = balanceFactor(node);
            if (bf > 1) {
                if (balanceFactor(node->left) >= 0) {
                    cout << "Imbalance node: " << node->data << "\nLL Case\n";
                    rightRotate(node);
                } else {
                    cout << "Imbalance node: " << node->data << "\nLR Case\n";
                    leftRotate(node->left);
                    rightRotate(node);
                }
            } else if (bf < -1) {
                if (balanceFactor(node->right) <= 0) {
                    cout << "Imbalance node: " << node->data << "\nRR Case\n";
                    leftRotate(node);
                } else {
                    cout << "Imbalance node: " << node->data << "\nRL Case\n";
                    rightRotate(node->right);
                    leftRotate(node);
                }
            }
            updateHeight(node);
            node = node->parent;
        }
    }
public:
    Node* root;

    AVLTree() : root(nullptr) {}

    void insertion(int key) {
        root = Insert(root, key);
        printAVL(root);
        cout << "\n";
    }

     void printAVL(Node* node) const {
        if (!node) return;
        printAVL(node->left);
        cout << node->data << "(" << balanceFactor(node) << ") ";
        printAVL(node->right);
    }


};


int main() {
    AVLTree tree;
    int value;

    while (cin >> value && value != -1) {
        tree.insertion(value);
    }


    tree.printAVL(tree.root);
    cout << "\n";

    return 0;
}
