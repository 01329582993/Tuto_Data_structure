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

class BST {
private:
    Node* Insert(Node* node, int key) {
        if (node == nullptr) {
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

    void InorderDisplay(Node* node) {
        if (!node) return;
        InorderDisplay(node->left);
        cout << node->data << "(" << balanceFactor(node) << ") ";
        InorderDisplay(node->right);
    }

public:
    Node* root;

    BST() : root(nullptr) {}

    void insertion(int key) {
        root = Insert(root, key);
        InorderDisplay(root);
        cout << "\n";
    }

};

int main() {
    BST tree;
    int value;

    while (cin >> value && value != -1) {
        tree.insertion(value);
    }

    return 0;
}

